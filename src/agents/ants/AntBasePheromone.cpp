#include "AntBasePheromone.h"
#include "../Pheromone.h"

AntBasePheromone::AntBasePheromone(Environment *environment, Anthill *anthill) :
    AntBase(environment, anthill)
{}

void AntBasePheromone::putPheromone()
{
    float qteToAdd = getCarryQuantity() > 0 ? 100.0f : 10.0f;
    std::vector<Pheromone*> pheromones = perceive<Pheromone>();
    if (pheromones.empty())
    {
        new Pheromone(getEnvironment(), getPosition(), qteToAdd);
    }
    else
    {
        pheromones.front()->addQuantity(qteToAdd);
    }
}

Pheromone* AntBasePheromone::choosePheromone()
{
    std::vector<Pheromone*> pheromones = perceive<Pheromone>(getDirection(), getPerceptionAngle(), 8);
    if (pheromones.empty())
    {
        return nullptr;
    }
    std::vector<float> weights;
    weights.reserve(pheromones.size());
    for (auto &pheromone : pheromones)
    {
        weights.push_back(pheromone->getQuantity());
    }
    return pheromones[MathUtils::randomChoose(weights)];
}

void AntBasePheromone::movingForward()
{
    AntBase::movingForward();
    putPheromone();
}
