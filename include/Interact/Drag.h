#ifndef ACT_DRAG_H
#define ACT_DRAG_H

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

}

#endif // ACT_DRAG_H
