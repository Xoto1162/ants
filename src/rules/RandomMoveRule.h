#ifndef ANTS_RANDOMMOVERULE_H
#define ANTS_RANDOMMOVERULE_H

#include "../agents/ants/AntWithRules.h"
#include "AbstractAntRule.h"

class AntWithRules::RandomMoveRule : public AbstractAntRule
{
public:
    RandomMoveRule(AntBasePheromone *ant);
    bool condition() override;
    void action() override;
};


#endif //ANTS_RANDOMMOVERULE_H
