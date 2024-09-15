#include "Arrow.h"

namespace act
{

ArrowShape::ArrowShape() :
    m_vArray{sf::TriangleFan, 7}
{
    const double L = 100;
    const double W = 10;

    m_vArray[0].position = sf::Vector2f{100, 0};
    m_vArray[1].position = sf::Vector2f{L-3*W, 1.5*W};
    m_vArray[2].position = sf::Vector2f{L-2.5*W, 0.5*W};
    m_vArray[3].position = sf::Vector2f{0, 0.5*W};
    m_vArray[4].position = sf::Vector2f{0, -0.5*W};
    m_vArray[5].position = sf::Vector2f{L-2.5*W, -0.5*W};
    m_vArray[6].position = sf::Vector2f{L-3*W, -1.5*W};

    m_vArray[0].color = sf::Color::Red;
    m_vArray[1].color = sf::Color::Green;
    m_vArray[2].color = sf::Color::Blue;
    m_vArray[3].color = sf::Color::Green;
    m_vArray[4].color = sf::Color::Blue;
    m_vArray[5].color = sf::Color::Green;
    m_vArray[6].color = sf::Color::Blue;
}

std::size_t ArrowShape::getPointCount() const
{
    return m_vArray.getVertexCount();
}

sf::Vector2f ArrowShape::getPoint(std::size_t index) const
{
    return m_vArray[index].position;
}

void ArrowShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_vArray, states);
}
}
