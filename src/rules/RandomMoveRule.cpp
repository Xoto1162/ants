#include "RandomMoveRule.h"
#include "../utils/Timer.h"

AntWithRules::RandomMoveRule::RandomMoveRule(AntBasePheromone *ant) :
        AbstractAntRule(ant)
{}

bool AntWithRules::RandomMoveRule::condition()
{
    return getAnt()->getCarryQuantity() == 0;
}

void AntWithRules::RandomMoveRule::action()
{
    getAnt()->turn(MathUtils::random(-MathUtils::pi / 10 * Timer::dt(), MathUtils::pi / 10 * Timer::dt()));
    getAnt()->movingForward();
}
