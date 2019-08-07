#ifndef ANTS_PHEROMONE_H
#define ANTS_PHEROMONE_H

#include "Agent.h"
#include "../Renderer.h"

class Pheromone : public Agent
{
private:
    /**
     * Quantite de pheromone
     */
    float m_quantity;

public:
    Pheromone(Environment *environment, const Vector2<float> & pos, float quantity = 0);

    /**
     * Donne la quantite de pheromone
     * @return quantite de pheromone
     */
    float getQuantity() const;

    /**
     * Ajoute une quantite de pheromone
     * @param quantity  quantite a jouter
     */
    void addQuantity(float quantity);

    void draw() const override;
    void behaviour() override;
};


#endif //ANTS_PHEROMONE_H
