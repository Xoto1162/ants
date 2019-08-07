#ifndef ANTS_ANT_H
#define ANTS_ANT_H

#include "AntBasePheromone.h"

class Ant : public AntBasePheromone
{
private:

public:
    Ant(Environment *environment, Anthill *anthill);

    void behaviour() override;
};


#endif //ANTS_ANT_H
