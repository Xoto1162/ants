#include "SillyAnt.h"
#include "../Food.h"
#include "../../utils/Timer.h"

SillyAnt::SillyAnt(Environment *env, Anthill *anthill) :
    AntBase(env, anthill)
{}

void SillyAnt::behaviour()
{
    if (getCarryQuantity() == 0) // Si la fourmi n'a pas de nourriture sur elle
    {
        std::vector<Food*> foodsUnder = perceive<Food>();
        if (!foodsUnder.empty()) // S'il y a de la nourriture en dessous de la fourmi
        {
            gatherFood(foodsUnder.front());
        }
        else // S'il n'y a pas de nourriture sous la fourmi
        {
            std::vector<Food*> foodsAround = perceive<Food>(getDirection(), getPerceptionAngle(), getPerceptionDistance());
            if (!foodsAround.empty()) // Si la fourmi detecte de la nourriture a proximite
            {
                // Elle se dirige vers la nourriture
                setDirection(getPosition().direction(foodsAround.front()->getPosition()));
            }
            else // S'il n'y a pas de nourriture a proximite
            {
                // elle tourne aléatoirement
                turn(MathUtils::random(-MathUtils::pi / 10 * Timer::dt(), MathUtils::pi / 10 * Timer::dt()));
            }
            movingForward(); // elle avance
        }
    }
    else // Si la fourmi a de la nourriture sur elle
    {
        std::vector<Anthill*> anthills = perceive<Anthill>();
        if (std::find(anthills.begin(), anthills.end(), getAnthill()) != anthills.end()) // Si la fourmi est a sa fourmiliere
        {
            dropFood();
        }
        else // Si la fourmi n'est pas a sa fourmiliere
        {
            setDirection(getPosition().direction(getAnthill()->getPosition()));
            movingForward();
        }
    }
}
