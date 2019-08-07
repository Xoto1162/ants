#ifndef ANTS_MOVETOANTHILLRULE_H
#define ANTS_MOVETOANTHILLRULE_H

#include "../agents/ants/AntWithRules.h"
#include "AbstractAntRule.h"

class AntWithRules::MoveToAnthillRule : public AbstractAntRule
{
public:
    MoveToAnthillRule(AntBasePheromone *ant);
    bool condition() override;
    void action() override;
};


#endif //ANTS_MOVETOANTHILLRULE_H
