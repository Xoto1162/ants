#include "DropFoodRule.h"

AntWithRules::DropFoodRule::DropFoodRule(AntBasePheromone *ant) :
        AbstractAntRule(ant)
{}

bool AntWithRules::DropFoodRule::condition()
{
   if (getAnt()->getCarryQuantity() > 0)
   {
       std::vector<Anthill*> anthills = getAnt()->perceive<Anthill>();
       if (std::find(anthills.begin(), anthills.end(), getAnt()->getAnthill()) != anthills.end())
       {
           return true;
       }
   }
   return false;
}

void AntWithRules::DropFoodRule::action()
{
    std::vector<Anthill*> anthills = getAnt()->perceive<Anthill>();
    if (std::find(anthills.begin(), anthills.end(), getAnt()->getAnthill()) != anthills.end())
    {
        getAnt()->dropFood();
        getAnt()->turnBack();
    }
}
