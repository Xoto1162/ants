#ifndef ANTS_ANTHILL_H
#define ANTS_ANTHILL_H

#include "Agent.h"

class Anthill : public Agent
{
private:
    /**
     * Quantite de nourriture dans la fourmiliere
     */
    float m_foodQuantity;

public:
    Anthill(Environment *environment, const Vector2<float> & pos);

    /**
     * Depose de la nourriture dans la fourmiliere
     * @param quantity  quantite de nourriture a deposer
     */
    void depositFood(float quantity);

    void draw() const override;
    void behaviour() override;

};

#endif //ANTS_ANTHILL_H
