#ifndef ANTS_GATHERFOODRULE_H
#define ANTS_GATHERFOODRULE_H

#include "AbstractAntRule.h"
#include "../agents/ants/AntWithRules.h"

class AntWithRules::GatherFoodRule : public AbstractAntRule
{
public:
    GatherFoodRule(AntBasePheromone *ant);
    bool condition() override;
    void action() override;
};


#endif //ANTS_GATHERFOODRULE_H
