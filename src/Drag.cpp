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

bool Drag::processEvent(std::optional<sf::Event> event, sf::Shape& shape)
{
    bool caught = false;
    bool oldActive = m_active;

    if (sf::Event::MouseButtonPressed* mousePress = event->getIf<sf::Event::MouseButtonPressed>();
        !m_active && mousePress &&
        mousePress->button == sf::Mouse::Button::Left &&
        shape.getGlobalBounds().contains(sf::Vector2f{mousePress->position}))
    {
        m_active = true;
        m_relClickPos = shape.getPosition() - sf::Vector2f{mousePress->position};
        caught = true;
    }
    else if (m_active)
    {
        if (event->is<sf::Event::MouseButtonReleased>())
        {
            m_active = false;
            caught = true;
        }
        else if (sf::Event::MouseMoved* mouseMove = event->getIf<sf::Event::MouseMoved>();
                 mouseMove)
        {
            shape.setPosition(m_relClickPos + sf::Vector2f{mouseMove->position});
            caught = true;
        }
    }

    m_stateChangeCallback(shape, m_active);

    return caught;
}

} // namespace act
