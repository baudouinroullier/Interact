#include "Shape.h"

namespace act
{

Shape::Shape()
{
}

sf::Shape* Shape::getShape()
{
    return m_shape.get();
}

const sf::Shape* Shape::getShape() const
{
    return m_shape.get();
}

bool Shape::processEvent(sf::Event e)
{
    for (auto& interaction : m_interactions)
    {
        if (interaction->processEvent(e, *m_shape))
            return true;
    }
    return false;
}
} // namespace act
