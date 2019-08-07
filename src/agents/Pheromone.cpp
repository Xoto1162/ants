#include "Pheromone.h"
#include "../Renderer.h"
#include "../utils/Timer.h"

Pheromone::Pheromone(Environment *environment, const Vector2<float> & pos, float quantity) :
    Agent(environment, pos), m_quantity(quantity)
{}

float Pheromone::getQuantity() const
{
    return m_quantity;
}

void Pheromone::addQuantity(float quantity)
{
    m_quantity += quantity;
}

void Pheromone::draw() const
{
    Renderer::getInstance()->drawPixel(getPosition(), Renderer::Color(0, 128, 128, (Uint8) std::min(255.0f, getQuantity())));
}

void Pheromone::behaviour()
{
    m_quantity -= (float) (0.01 * m_quantity * Timer::dt());
    if (m_quantity < 0.01)
    {
        setStatus(Status::destroy);
    }
}
