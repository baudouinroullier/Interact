#ifndef ACT_HOVER_H
#define ACT_HOVER_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include "Interaction.h"

namespace act
{

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

#endif // ACT_HOVER_H
