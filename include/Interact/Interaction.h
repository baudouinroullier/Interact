#ifndef ACT_INTERACTION_H
#define ACT_INTERACTION_H

namespace act
{

class Interaction
{
public:
    virtual bool processEvent(std::optional<sf::Event> event, sf::Shape& shape) = 0;
};

} // namespace act

#endif // ACT_INTERACTION_H
