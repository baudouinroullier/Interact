#ifndef DRAGGABLE_H
#define DRAGGABLE_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

namespace act
{
class Interaction
{
public:
    virtual bool processEvent(sf::Event event, sf::Shape& shape) = 0;
};

class Drag : public Interaction
{
public:
    enum class State
    {
        None, Hover, Drag
    } state = State::None;

    Drag(std::function<void(sf::Shape& shape, State state)>&& callback);

    void setStateChangeCallback(std::function<void(sf::Shape& shape, State state)> callback);
    bool processEvent(sf::Event event, sf::Shape& shape) override;

protected:

    std::function<void(sf::Shape& shape, State state)> m_stateChangeCallback;
    sf::Vector2f m_relClickPos;
};
}

#endif // DRAGGABLE_H
