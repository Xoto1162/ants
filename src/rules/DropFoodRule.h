#ifndef ANTS_DROPFOODRULE_H
#define ANTS_DROPFOODRULE_H

#include "../agents/ants/AntWithRules.h"
#include "AbstractAntRule.h"

class AntWithRules::DropFoodRule : public AbstractAntRule
{
public:
    DropFoodRule(AntBasePheromone *ant);
    bool condition() override;
    void action() override;
};


#endif //ANTS_DROPFOODRULE_H
