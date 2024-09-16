#include "ArrowShape.h"
#include <cmath>


namespace act
{

ArrowShape::ArrowShape(double width, sf::Color color) :
    m_width(width),
    m_vArray{sf::TriangleFan, 7}
{
    for (int i = 0; i < m_vArray.getVertexCount(); ++i)
        m_vArray[i].color = color;
}

void ArrowShape::setStartPosition(float x, float y)
{
    setStartPosition({x, y});
}
void ArrowShape::setStartPosition(const sf::Vector2f& position)
{
    m_startPos = position;
    _computeVertexArray();
}

void ArrowShape::setEndPosition(float x, float y)
{
    setEndPosition({x, y});
}

void ArrowShape::setEndPosition(const sf::Vector2f& position)
{
    m_endPos = position;
    _computeVertexArray();
}

void ArrowShape::setPosition(float x, float y)
{
    setPosition({x, y});
}

void ArrowShape::setPosition(const sf::Vector2f& position)
{
    move(position - m_startPos);
}

void ArrowShape::moveStart(float offsetX, float offsetY)
{
    moveStart({offsetX, offsetY});
}

void ArrowShape::moveStart(const sf::Vector2f& offset)
{
    m_startPos += offset;
    _computeVertexArray();
}

void ArrowShape::moveEnd(float offsetX, float offsetY)
{
    moveEnd({offsetX, offsetY});
}

void ArrowShape::moveEnd(const sf::Vector2f& offset)
{
    m_endPos += offset;
    _computeVertexArray();
}

void ArrowShape::move(float offsetX, float offsetY)
{
    move({offsetX, offsetY});
}

void ArrowShape::move(const sf::Vector2f& offset)
{
    m_startPos += offset;
    m_endPos += offset;
}

void ArrowShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    const sf::Vector2f vec = m_endPos - m_startPos;
    const double angle = 180 / M_PI * std::atan2(vec.y, vec.x);

    sf::Transform t;
    t.translate(m_startPos).rotate(angle);

    states.transform.combine(t);
    target.draw(m_vArray, states);
}

void ArrowShape::_computeVertexArray()
{
    const sf::Vector2f vec = m_endPos - m_startPos;
    const float L = std::sqrt(vec.x * vec.x + vec.y * vec.y);

    if (std::abs(L - m_length) < 1.f)
        return;

    m_length = L;
    const float W = std::min<float>(L / 3, m_width);

    m_vArray[0].position = sf::Vector2f{L, 0.f};
    m_vArray[1].position = sf::Vector2f{L - 3.f * W, 1.5f * W};
    m_vArray[2].position = sf::Vector2f{L - 2.5f * W, 0.5f * W};
    m_vArray[3].position = sf::Vector2f{0, 0.5f * W};
    m_vArray[4].position = sf::Vector2f{0, -0.5f * W};
    m_vArray[5].position = sf::Vector2f{L - 2.5f * W, -0.5f * W};
    m_vArray[6].position = sf::Vector2f{L - 3.f * W, -1.5f * W};
}
}
