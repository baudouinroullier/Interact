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

bool Hover::processEvent(std::optional<sf::Event> event, sf::Shape& shape)
{
    bool oldActive = m_active;

    sf::Event::MouseMoved* mouseMoved = event->getIf<sf::Event::MouseMoved>();
    if (!m_active && mouseMoved &&
        shape.getGlobalBounds().contains(sf::Vector2f{mouseMoved->position}))
        m_active = true;
    else if (m_active && mouseMoved &&
             !shape.getGlobalBounds().contains(sf::Vector2f{mouseMoved->position}))
        m_active = false;

    m_stateChangeCallback(shape, m_active);

    return oldActive != m_active;
}

} // namespace act
