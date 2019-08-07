#ifndef ANTS_MOVETOPHEROMONE_H
#define ANTS_MOVETOPHEROMONE_H

#include "../agents/ants/AntWithRules.h"
#include "AbstractAntRule.h"

class AntWithRules::MoveToPheromoneRule : public AbstractAntRule
{
public:
    MoveToPheromoneRule(AntBasePheromone *ant);
    bool condition() override;
    void action() override;
};


#endif //ANTS_MOVETOPHEROMONE_H
