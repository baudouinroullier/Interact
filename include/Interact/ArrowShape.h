#include <SFML/Graphics.hpp>


namespace act
{

class ArrowShape : public sf::Drawable
{
public:
    ArrowShape(double width, sf::Color color);

    void setStartPosition(float x, float y);
    void setStartPosition(const sf::Vector2f& position);
    void setEndPosition(float x, float y);
    void setEndPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
    void moveStart(float offsetX, float offsetY);
    void moveStart(const sf::Vector2f& offset);
    void moveEnd(float offsetX, float offsetY);
    void moveEnd(const sf::Vector2f& offset);
    void move(float offsetX, float offsetY);
    void move(const sf::Vector2f& offset);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void _computeVertexArray();

    sf::Vector2f m_startPos, m_endPos;
    double m_length, m_width;
    sf::VertexArray m_vArray;
};
}
