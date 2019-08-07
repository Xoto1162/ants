#include "Anthill.h"
#include "../Renderer.h"
#include "../AntFactory.h"
#include "ants/AntWithRules.h"
#include "ants/SillyAnt.h"

Anthill::Anthill(Environment *environment, const Vector2<float> & pos): Agent(environment, pos, 10), m_foodQuantity(0) {

}

void Anthill::draw() const
{
    Renderer::getInstance()->drawCircle(this->getPosition(), this->getRadius(), Renderer::Color(0, 0, 255, 255));
}

void Anthill::behaviour()
{
    if (m_foodQuantity >= 5)
    {
        AntFactory::getInstance()->createAnt<AntWithRules>(this);
        m_foodQuantity -= 5;
    }
}

void Anthill::depositFood(float quantity)
{
    this->m_foodQuantity += quantity;
}
