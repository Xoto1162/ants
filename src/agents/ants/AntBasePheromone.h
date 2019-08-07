#ifndef ANTS_ANTBASEPHEROMONE_H
#define ANTS_ANTBASEPHEROMONE_H

#include "AntBase.h"
#include "../Pheromone.h"

class AntBasePheromone : public AntBase
{
private:

public:
    AntBasePheromone(Environment *environment, Anthill *anthill);

    /**
     * Depose des pheromones a la position de la fourmi
     */
    void putPheromone();

    /**
     * Percoit des pheromone a 8cm max
     * et choisi au hasard une pheromone a suivre en fonction de sa concentration
     * @return pointeur sur la pheromone choisi, ou nullptr si aucune pheromone
     */
    Pheromone* choosePheromone();

    /**
     * Fait avancer la fourmi et depose des pheromone
     */
    void movingForward() override;
};


#endif //ANTS_ANTBASEPHEROMONE_H
