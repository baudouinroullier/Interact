#include "Draggable.h"

namespace act
{
Drag::Drag(std::function<void(sf::Shape&, State)>&& callback) :
    m_stateChangeCallback{std::move(callback)}
{
}

void Drag::setStateChangeCallback(std::function<void(sf::Shape&, Drag::State)> callback)
{
    m_stateChangeCallback = callback;
}

bool Drag::processEvent(sf::Event event, sf::Shape& shape)
{
    State oldState = state;

    if (state == State::None && event.type == sf::Event::EventType::MouseMoved && shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
    {
        state = State::Hover;
    }
    else if (state == State::Hover)
    {
        if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
        {
            state = State::Drag;
            m_relClickPos = shape.getPosition() - sf::Vector2f{event.mouseButton.x, event.mouseButton.y};
        }
        else if (event.type == sf::Event::EventType::MouseMoved && !shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
            state = State::None;
    }
    else if (state == State::Drag)
    {
        if (event.type == sf::Event::EventType::MouseButtonReleased)
            state = State::Hover;
        else if (event.type == sf::Event::MouseMoved)
            shape.setPosition(m_relClickPos + sf::Vector2f{event.mouseMove.x, event.mouseMove.y});
    }

    if (oldState != state)
        m_stateChangeCallback(shape, state);

    return oldState != state;
}

} // namespace act
