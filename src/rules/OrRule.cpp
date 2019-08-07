#include "OrRule.h"
#include "AbstractAntRule.h"

OrRule::OrRule(std::vector<AbstractRule*> & rules) : m_rules(rules)
{}

bool OrRule::condition()
{
    for (auto &m_rule : m_rules)
    {
        if (m_rule->condition())
        {
            return true;
        }
    }
    return false;
}

void OrRule::action()
{
    for (auto &m_rule : m_rules)
    {
        if (m_rule->condition())
        {
            m_rule->action();
            return;
        }
    }
}
