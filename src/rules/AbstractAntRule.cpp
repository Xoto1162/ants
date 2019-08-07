#include "AbstractAntRule.h"

AbstractAntRule::AbstractAntRule(AntBasePheromone *ant) : m_ant(ant)
{}

AntBasePheromone* AbstractAntRule::getAnt() const
{
    return m_ant;
}
