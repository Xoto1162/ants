#ifndef ANTS_ORRULE_H
#define ANTS_ORRULE_H

#include "AbstractRule.h"
#include "AbstractAntRule.h"
#include <vector>

class OrRule : public AbstractRule
{
private:
    std::vector<AbstractRule*> m_rules;

public:
    OrRule(std::vector<AbstractRule*> & rules);

    bool condition() override;
    void action() override;
};

#endif //ANTS_ORRULE_H
