#ifndef ACT_SHAPE_H
#define ACT_SHAPE_H


#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Interaction.h"

namespace act
{

class Shape : public sf::Drawable
{
public:
    Shape();

    template<class S, typename... Args>
        requires std::derived_from<S, sf::Shape>
    S* makeShape(Args&&... args)
    {
        m_shape = std::make_unique<S>(args...);
        return static_cast<S*>(m_shape.get());
    }

    template<class I, typename... Args>
        requires std::derived_from<I, act::Interaction>
    I* makeInteraction(Args&&... args)
    {
        m_interactions.push_back(std::make_unique<I>(args...));
        return static_cast<I*>(m_interactions.back().get());
    }

    sf::Shape* getShape();
    const sf::Shape* getShape() const;

    bool processEvent(sf::Event e);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(*m_shape, states);
    }

    std::unique_ptr<sf::Shape> m_shape = nullptr;

    std::vector<std::unique_ptr<Interaction>> m_interactions;
};

} // namespace act

#endif // ACT_SHAPE_H
