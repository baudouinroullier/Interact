#include "Drag.h"

namespace act
{
Drag::Drag(std::function<void(sf::Shape&, bool)>&& callback) :
    m_stateChangeCallback{std::move(callback)}
{
}

void Drag::setStateChangeCallback(std::function<void(sf::Shape&, bool)> callback)
{
    m_stateChangeCallback = callback;
}

bool Drag::processEvent(sf::Event event, sf::Shape& shape)
{
    bool oldActive = m_active;

    if (!m_active &&
        event.type == sf::Event::EventType::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Button::Left &&
        shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        m_active = true;
        m_relClickPos = shape.getPosition() - sf::Vector2f{event.mouseButton.x, event.mouseButton.y};
    }
    else if (m_active)
    {
        if (event.type == sf::Event::EventType::MouseButtonReleased)
            m_active = false;
        else if (event.type == sf::Event::MouseMoved)
            shape.setPosition(m_relClickPos + sf::Vector2f{event.mouseMove.x, event.mouseMove.y});
    }

    if (oldActive != m_active)
        m_stateChangeCallback(shape, m_active);

    return oldActive != m_active;
}

} // namespace act
