#include "MoveToPheromoneRule.h"

AntWithRules::MoveToPheromoneRule::MoveToPheromoneRule(AntBasePheromone *ant) :
        AbstractAntRule(ant)
{}

bool AntWithRules::MoveToPheromoneRule::condition()
{
    if (getAnt()->getCarryQuantity() == 0)
    {
        Pheromone *pheromone = getAnt()->choosePheromone();
        if (pheromone != nullptr)
        {
            return true;
        }
    }
    return false;
}

void AntWithRules::MoveToPheromoneRule::action()
{
    Pheromone *pheromone = getAnt()->choosePheromone();
    getAnt()->setDirection(getAnt()->getPosition().direction(pheromone->getPosition()));
    getAnt()->movingForward();
}
