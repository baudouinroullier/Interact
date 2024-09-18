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
    bool caught = false;
    bool oldActive = m_active;

    if (!m_active &&
        event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Button::Left &&
        shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        m_active = true;
        m_relClickPos = shape.getPosition() - sf::Vector2f{event.mouseButton.x, event.mouseButton.y};
        caught = true;
    }
    else if (m_active)
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            m_active = false;
            caught = true;
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            shape.setPosition(m_relClickPos + sf::Vector2f{event.mouseMove.x, event.mouseMove.y});
            caught = true;
        }
    }

    m_stateChangeCallback(shape, m_active);

    return caught;
}

} // namespace act
