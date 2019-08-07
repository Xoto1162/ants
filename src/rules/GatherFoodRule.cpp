#include "GatherFoodRule.h"

AntWithRules::GatherFoodRule::GatherFoodRule(AntBasePheromone *ant) :
    AbstractAntRule(ant)
{}

bool AntWithRules::GatherFoodRule::condition()
{
    if (getAnt()->getCarryQuantity() == 0)
    {
        std::vector<Food*> foodsUnder = getAnt()->perceive<Food>();
        if (!foodsUnder.empty()) // S'il y a de la nourriture en dessous de la fourmi
        {
            return true;
        }
    }
    return false;
}

void AntWithRules::GatherFoodRule::action()
{
    std::vector<Food*> foodsUnder = getAnt()->perceive<Food>();
    getAnt()->gatherFood(foodsUnder.front());
}
