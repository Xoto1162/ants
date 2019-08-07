#include "MoveToAnthillRule.h"

AntWithRules::MoveToAnthillRule::MoveToAnthillRule(AntBasePheromone *ant) :
        AbstractAntRule(ant)
{}

bool AntWithRules::MoveToAnthillRule::condition()
{
    if (getAnt()->getCarryQuantity() > 0)
    {
        std::vector<Anthill*> anthills = getAnt()->perceive<Anthill>();
        if (std::find(anthills.begin(), anthills.end(), getAnt()->getAnthill()) == anthills.end())
        {
            return true;
        }
    }
    return false;
}

void AntWithRules::MoveToAnthillRule::action()
{
    getAnt()->setDirection(getAnt()->getPosition().direction(getAnt()->getAnthill()->getPosition()));
    Pheromone *pheromone = getAnt()->choosePheromone();
    if (pheromone != nullptr)
    {
        getAnt()->setDirection(getAnt()->getPosition().direction(pheromone->getPosition()));
    }
    getAnt()->movingForward();
}
