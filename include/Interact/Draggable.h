#ifndef DRAGGABLE_H
#define DRAGGABLE_H

#include <SFML/Graphics.hpp>
#include <functional>

namespace act
{
class Draggable : public sf::Drawable
{
public:
    enum MoveState
    {
        None, Hover, Drag
    } state = None;

    Draggable(sf::Shape* shape = nullptr);

    void setShape(sf::Shape* shape);
    void setStateChangeCallback(std::function<void(sf::Shape& shape, MoveState state)> callback);
    void processEvent(sf::Event e);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(*m_shape, states);
    }

    sf::Shape* m_shape = nullptr;
    std::function<void(sf::Shape& shape, MoveState state)> m_stateChangeCallback;
    sf::Vector2f m_relClickPos;
};
}

#endif // DRAGGABLE_H
