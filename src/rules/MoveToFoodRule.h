#ifndef ANTS_MOVETOFOODRULE_H
#define ANTS_MOVETOFOODRULE_H

#include "../agents/ants/AntWithRules.h"
#include "AbstractAntRule.h"

class AntWithRules::MoveToFoodRule : public AbstractAntRule
{
public:
    MoveToFoodRule(AntBasePheromone *ant);
    bool condition() override;
    void action() override;
};


#endif //ANTS_MOVETOFOODRULE_H
