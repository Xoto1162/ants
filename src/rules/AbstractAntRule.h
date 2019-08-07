#ifndef ANTS_ABSTRACTANTRULE_H
#define ANTS_ABSTRACTANTRULE_H

#include "AbstractRule.h"
#include "../agents/ants/AntBasePheromone.h"

class AbstractAntRule : public AbstractRule
{
private:
    AntBasePheromone *m_ant;

public:
    AbstractAntRule(AntBasePheromone *ant);
    AntBasePheromone* getAnt() const;
};


#endif //ANTS_ABSTRACTANTRULE_H
