#include "MoveToFoodRule.h"

AntWithRules::MoveToFoodRule::MoveToFoodRule(AntBasePheromone *ant) :
    AbstractAntRule(ant)
{}

bool AntWithRules::MoveToFoodRule::condition()
{
    if (getAnt()->getCarryQuantity() == 0)
    {
        std::vector<Food*> foodsAround = getAnt()->perceive<Food>(
                getAnt()->getDirection(),
                getAnt()->getPerceptionAngle(),
                getAnt()->getPerceptionDistance()
        );
        if (!foodsAround.empty())
        {
            return true;
        }
    }
    return false;
}

void AntWithRules::MoveToFoodRule::action()
{
    std::vector<Food*> foodsAround = getAnt()->perceive<Food>(
            getAnt()->getDirection(),
            getAnt()->getPerceptionAngle(),
            getAnt()->getPerceptionDistance()
    );
    getAnt()->setDirection(getAnt()->getPosition().direction(foodsAround.front()->getPosition()));
    getAnt()->movingForward();
}
