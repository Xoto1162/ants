#ifndef ANTS_ANTWITHRULE_H
#define ANTS_ANTWITHRULE_H

#include "AntBasePheromone.h"
#include "../../rules/AbstractAntRule.h"

class AntWithRules : public AntBasePheromone
{
private:
    class GatherFoodRule;
    class MoveToFoodRule;
    class MoveToPheromoneRule;
    class RandomMoveRule;
    class DropFoodRule;
    class MoveToAnthillRule;

private:
    std::vector<AbstractRule*> m_rules;

public:
    AntWithRules(Environment *environment, Anthill *anthill);
    ~AntWithRules() override;
    void behaviour() override;
};


#endif //ANTS_ANTWITHRULE_H
