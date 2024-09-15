#include "Hover.h"

namespace act
{
Hover::Hover(std::function<void(sf::Shape&, bool)>&& callback) :
    m_stateChangeCallback{std::move(callback)}
{
}

void Hover::setStateChangeCallback(std::function<void(sf::Shape&, bool)> callback)
{
    m_stateChangeCallback = callback;
}

bool Hover::processEvent(sf::Event event, sf::Shape& shape)
{
    bool oldActive = m_active;

    if (!m_active &&
        event.type == sf::Event::EventType::MouseMoved &&
        shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
        m_active = true;
    else if (m_active &&
             event.type == sf::Event::EventType::MouseMoved &&
             !shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
        m_active = false;

    if (oldActive != m_active)
        m_stateChangeCallback(shape, m_active);

    return oldActive != m_active;
}

} // namespace act
