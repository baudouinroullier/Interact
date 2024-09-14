#ifndef DRAG_H
#define DRAG_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include "Interaction.h"

namespace act
{

class Drag : public Interaction
{
public:
    Drag(std::function<void(sf::Shape&, bool)>&& callback);

    void setStateChangeCallback(std::function<void(sf::Shape&, bool)> callback);
    bool processEvent(sf::Event event, sf::Shape& shape) override;

protected:
    std::function<void(sf::Shape&, bool)> m_stateChangeCallback;
    sf::Vector2f m_relClickPos;
    bool m_active = false;
};

class Hover : public Interaction
{
public:
    Hover(std::function<void(sf::Shape& shape, bool)>&& callback);

    void setStateChangeCallback(std::function<void(sf::Shape& shape, bool)> callback);
    bool processEvent(sf::Event event, sf::Shape& shape) override;

protected:

    std::function<void(sf::Shape& shape, bool)> m_stateChangeCallback;
    bool m_active = false;
};
}

#endif // DRAG_H
