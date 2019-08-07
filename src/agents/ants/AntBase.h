#ifndef ANTS_ANTBASE_H
#define ANTS_ANTBASE_H

#include "../Agent.h"
#include "../Anthill.h"
#include "../../Renderer.h"
#include "../Food.h"

class AntBase : public Agent
{
private:
    /**
     * Indique a quelle fourmiliere la fourmi appartient
     */
    Anthill * m_anthill;

    /**
     * Vitesse de deplacement de la fourmi
     */
    float m_speed;

    /**
     * Direction de la fourmi pour les deplacements
     */
    Vector2<float> m_direction;

    /**
     * Duree de vie restante de la fourmi
     */
    float m_lifeSpan;

    /**
     * Quantite max de nourriture que la fourmi peut transporter
     */
    float m_carryCapacity;

    /**
     * Quantite de nourriture transporte par la fourmi
     */
    float m_carryQuantity;

    /**
     * Angle de perception de la fourmi
     */
    float m_perceptionAngle;

    /**
     * Distance de perception de la fourmi
     */
    float m_perceptionDistance;

public:
    AntBase(
            Environment * env, Anthill * anthill,
            float lifeSpan = MathUtils::random(1500, 2500), float speed = 1, float carryCapacity = 5,
            float perceptionAngle = MathUtils::pi / 2, float perceptionDistance = 3,
            const Vector2<float> & direction = Vector2<float>::random()
    );

    /**
     * Fait avancer la fourmi
     */
    virtual void movingForward();

    /**
     * Tourner la fourmis d'un certain angle
     * @param angle     angle de rotation
     */
    void turn(float angle);

    /**
     * Tourner la fourmi vers une cible
     * @param target    cible vers laquelle s'orienter
     */
    void turn(Agent * target);

    /**
     * La fourmis fait demitour
     */
    void turnBack();

    /**
     * Depose la nourriture collecte dans sa fourmiliere
     */
    void dropFood();

    /**
     * Collecte de la nourriture sur un spot
     * @param food spot de nourriture a collecter
     */
    void gatherFood(Food *food);

    void behaviour() override = 0;
    void draw() const override;
    void update() override;

    /**
     * Donne la fourmiliere de la fourmi
     * @return fourmiliere de la fourmi
     */
    Anthill* getAnthill() const;

    /**
     * Donne la vitesse de la fourmi
     * @return vitesse de la fourmi
     */
    float getSpeed() const;

    /**
     * Donne la direction de la fourmi
     * @return direction de la fourmi
     */
    Vector2<float> getDirection() const;

    /**
     * Met a jour la direction de la fourmi
     */
    void setDirection(Vector2<float> direction);

    /**
     * Donne la duree de vie restante de la fourmi
     * @return duree de vie restante
     */
    float getLifeSpan() const;

    /**
     * Donne la quantié max de nourriture que la fourmi peut transporter
     * @return quantite max de nourriture transportable
     */
    float getCarryCapacity() const;

    /**
     * Donne la quantite de nourritute porte par la fourmi
     * @return quantite de nourriture porte par la fourmi
     */
    float getCarryQuantity() const;

    /**
     * Donne l'angle de perception de la fourmi
     * @return angle de perception
     */
    float getPerceptionAngle() const;

    /**
     * Donne la distance de perception de la fourmi
     * @return distance de perception
     */
    float getPerceptionDistance() const;

    /**
     * Donne la couleur de la fourmi
     * @return la couleur de la fourmi
     */
    virtual Renderer::Color getColor() const;
};

#endif //ANTS_ANTBASE_H
