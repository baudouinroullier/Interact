#ifndef ACT_INTERACTION_H
#define ACT_INTERACTION_H

namespace act
{

class Interaction
{
public:
    virtual bool processEvent(sf::Event event, sf::Shape& shape) = 0;
};

} // namespace act

#endif // ACT_INTERACTION_H
