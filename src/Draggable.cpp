#include "Draggable.h"

namespace act
{
Draggable::Draggable(sf::Shape* shape) :
    m_shape(shape)
{
}

void Draggable::setShape(sf::Shape* shape)
{
    m_shape = shape;
}

void Draggable::setStateChangeCallback(std::function<void(sf::Shape&, Draggable::MoveState)> callback)
{
    m_stateChangeCallback = callback;
}

void Draggable::processEvent(sf::Event e)
{
    MoveState oldState = state;

    if (state == None && e.type == sf::Event::EventType::MouseMoved && m_shape->getGlobalBounds().contains(e.mouseMove.x, e.mouseMove.y))
        state = Hover;
    else if (state == Hover)
    {
        if (e.type == sf::Event::EventType::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Button::Left)
        {
            state = Drag;
            m_relClickPos = m_shape->getPosition() - sf::Vector2f{e.mouseButton.x, e.mouseButton.y};
        }
        else if (e.type == sf::Event::EventType::MouseMoved && !m_shape->getGlobalBounds().contains(e.mouseMove.x, e.mouseMove.y))
            state = None;
    }
    else if (state == Drag)
    {
        if (e.type == sf::Event::EventType::MouseButtonReleased)
            state = Hover;
        else if (e.type == sf::Event::MouseMoved)
            m_shape->setPosition(m_relClickPos + sf::Vector2f{e.mouseMove.x, e.mouseMove.y});
    }

    if (oldState != state)
        m_stateChangeCallback(*m_shape, state);

}

} // namespace act
