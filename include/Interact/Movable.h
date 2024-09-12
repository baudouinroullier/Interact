#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>

namespace act
{
class Movable : public sf::Drawable
{
public:
    Movable(sf::Shape* shape = nullptr) :
        m_shape(shape) {}

    void setShape(sf::Shape* shape)
    {
        m_shape = shape;
    }

    void processEvent(sf::Event e)
    {
        if (state == Fixed && e.type == sf::Event::EventType::MouseMoved && m_shape->getGlobalBounds().contains(e.mouseMove.x, e.mouseMove.y))
            state = Hover;
        else if (state == Hover)
        {
            if (e.type == sf::Event::EventType::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Button::Left)
            {
                state = Held;
                m_relClickPos = m_shape->getPosition() - sf::Vector2f{e.mouseButton.x, e.mouseButton.y};
            }
            else if (e.type == sf::Event::EventType::MouseMoved && !m_shape->getGlobalBounds().contains(e.mouseMove.x, e.mouseMove.y))
                state = Fixed;
        }
        else if (state == Held)
        {
            if (e.type == sf::Event::EventType::MouseButtonReleased)
                state = Hover;
            else if (e.type == sf::Event::MouseMoved)
                m_shape->setPosition(m_relClickPos + sf::Vector2f{e.mouseMove.x , e.mouseMove.y});
        }

        m_shape->setOutlineThickness(2+2*state);
    }

    enum MoveState
    {
        Fixed, Hover, Held
    } state = Fixed;


protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(*m_shape, states);
    }

    sf::Shape* m_shape = nullptr;
    sf::Vector2f m_relClickPos;
};
}

#endif // MOVABLE_H
