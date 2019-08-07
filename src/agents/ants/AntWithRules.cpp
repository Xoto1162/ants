#include "AntWithRules.h"
#include "../../rules/OrRule.h"
#include "../../rules/AbstractAntRule.h"
#include "../../rules/GatherFoodRule.h"
#include "../../rules/MoveToFoodRule.h"
#include "../../rules/MoveToPheromoneRule.h"
#include "../../rules/RandomMoveRule.h"
#include "../../rules/DropFoodRule.h"
#include "../../rules/MoveToAnthillRule.h"

AntWithRules::AntWithRules(Environment *environment, Anthill *anthill) :
    AntBasePheromone(environment, anthill), m_rules(std::vector<AbstractRule*>())
{
    m_rules.push_back(new GatherFoodRule(this));
    m_rules.push_back(new MoveToFoodRule(this));
    m_rules.push_back(new MoveToPheromoneRule(this));
    m_rules.push_back(new RandomMoveRule(this));
    m_rules.push_back(new DropFoodRule(this));
    m_rules.push_back(new MoveToAnthillRule(this));
}

AntWithRules::~AntWithRules()
{
    for (auto &m_rule : m_rules)
    {
        delete m_rule;
    }
}

void AntWithRules::behaviour()
{
    OrRule rules(m_rules);
    rules.action();
}
