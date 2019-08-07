#include "AntBase.h"
#include "../../utils/Timer.h"

AntBase::AntBase(
        Environment *env, Anthill * anthill,
        float lifeSpan, float speed, float carryCapacity,
        float perceptionAngle, float perceptionDistance,
        const Vector2<float> & direction
):
    Agent(env, anthill->getPosition()),
    m_anthill(anthill),
    m_speed(speed), m_direction(direction.normalized()),
    m_lifeSpan(lifeSpan),
    m_perceptionAngle(perceptionAngle), m_perceptionDistance(perceptionDistance),
    m_carryCapacity(carryCapacity), m_carryQuantity(0)
{}

void AntBase::movingForward()
{
    setPosition(getPosition() + getDirection() * getSpeed() * Timer::dt());
}

void AntBase::turn(float angle)
{
    setDirection(getDirection().rotate(angle));
}

void AntBase::turn(Agent *target)
{
    setDirection(getPosition().direction(target->getPosition()));
}

void AntBase::turnBack()
{
    turn(MathUtils::pi);
}

void AntBase::dropFood()
{
    getAnthill()->depositFood(getCarryQuantity());
    m_carryQuantity = 0;
}

void AntBase::gatherFood(Food *food)
{
    m_carryQuantity = food->collectFood(getCarryCapacity() - getCarryQuantity());
}

Renderer::Color AntBase::getColor() const
{
    if (getCarryQuantity() == 0)
    {
        return {255, 255, 255};
    }
    return {128, 255, 125};
}

void AntBase::draw() const
{
    Renderer::getInstance()->drawPixel(getPosition(), getColor());
}

void AntBase::update()
{
    if (getLifeSpan() <= 0) {
        setStatus(Status::destroy);
    }
    m_lifeSpan--;
    Agent::update();
}

Anthill* AntBase::getAnthill() const
{
    return m_anthill;
}

float AntBase::getSpeed() const
{
    return m_speed;
}

Vector2<float> AntBase::getDirection() const
{
    return m_direction;
}

void AntBase::setDirection(Vector2<float> direction)
{
    m_direction = direction.normalized();
}

float AntBase::getLifeSpan() const
{
    return m_lifeSpan;
}

float AntBase::getCarryCapacity() const
{
    return m_carryCapacity;
}

float AntBase::getCarryQuantity() const
{
    return m_carryQuantity;
}

float AntBase::getPerceptionAngle() const
{
    return m_perceptionAngle;
}

float AntBase::getPerceptionDistance() const
{
    return m_perceptionDistance;
}
