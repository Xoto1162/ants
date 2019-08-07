#include "Ant.h"
#include "../../utils/Timer.h"

Ant::Ant(Environment *environment, Anthill *anthill) : AntBasePheromone(environment, anthill)
{}

void Ant::behaviour()
{
    if (getCarryQuantity() > 0)
    {
        std::vector<Anthill*> anthills = perceive<Anthill>();
        if (std::find(anthills.begin(), anthills.end(), getAnthill()) != anthills.end()) // Si la fourmi est a sa fourmiliere
        {
            dropFood();
            turnBack();
        }
        else
        {
            setDirection(getPosition().direction(getAnthill()->getPosition()));
            Pheromone *pheromone = choosePheromone();
            if (pheromone != nullptr)
            {
                setDirection(getPosition().direction(pheromone->getPosition()));
            }
            movingForward();
        }
    }
    else
    {
        std::vector<Food*> foodsUnder = perceive<Food>();
        if (!foodsUnder.empty()) // S'il y a de la nourriture en dessous de la fourmi
        {
            gatherFood(foodsUnder.front());
        }
        else
        {
            std::vector<Food*> foodsAround = perceive<Food>(getDirection(), getPerceptionAngle(), getPerceptionDistance());
            if (!foodsAround.empty()) // Si la fourmi detecte de la nourriture a proximite
            {
                // Elle se dirige vers la nourriture
                setDirection(getPosition().direction(foodsAround.front()->getPosition()));
            }
            else
            {
                Pheromone *pheromone = choosePheromone();
                if (pheromone != nullptr)
                {
                    setDirection(getPosition().direction(pheromone->getPosition()));
                }
                else
                {
                    turn(MathUtils::random(-MathUtils::pi / 10 * Timer::dt(), MathUtils::pi / 10 * Timer::dt()));
                }
            }
            movingForward();
        }
    }
}
