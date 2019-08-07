#ifndef ANTS_FOOD_H
#define ANTS_FOOD_H

#include "Agent.h"

class Food : public Agent
{
private:
    /**
     * Quantite de nourriture
     */
    float m_foodQuantity;

public:
    Food(Environment *environment, const Vector2<float> & pos, float quantity);

    /**
     * Indique la quantite de nourriture restante
     * @return quantite de nourriture restante
     */
    float getFoodQuantity() const;

    /**
     * Collecte de la nourriture
     * @param quantity  quantite de nourriture a collecter
     * @return la quantite de nourriture collecte
     */
    float collectFood(float quantity);

    void draw() const override;
    void behaviour() override;

};

#endif //ANTS_FOOD_H
