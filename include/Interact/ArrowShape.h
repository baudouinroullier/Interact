#include <SFML/Graphics.hpp>


namespace act
{

class ArrowShape : public sf::Shape
{
public:
    ArrowShape();

    std::size_t getPointCount() const override;
    sf::Vector2f getPoint(std::size_t index) const override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


    sf::VertexArray m_vArray;
};
}
