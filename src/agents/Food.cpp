#include "Food.h"
#include "../Renderer.h"

Food::Food(Environment *environment, const Vector2<float> & pos, float quantity) :
    Agent(environment, pos, MathUtils::circleRadius(quantity)), m_foodQuantity(quantity)
{}

float Food::getFoodQuantity() const
{
    return this->m_foodQuantity;
}

float Food::collectFood(float quantity)
{
    float givenQuantity = (this->m_foodQuantity > quantity) ? quantity : m_foodQuantity;
    this->m_foodQuantity -= givenQuantity;
    return givenQuantity;
}

void Food::behaviour()
{
    float currentRadius = MathUtils::circleRadius(this->m_foodQuantity);

    this->setRadius(currentRadius);

    if(this->m_foodQuantity == 0)
    {
        this->setStatus(destroy);
    }
}

void Food::draw() const
{
    Renderer::getInstance()->drawCircle(this->getPosition(), this->getRadius(), Renderer::Color(154, 235, 38, 255));
}
