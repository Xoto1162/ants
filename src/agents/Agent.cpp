#include <iostream>
#include "Agent.h"

std::set<Agent*> Agent::s_agents;

Agent::Agent(Environment *environment, const Vector2<float> & pos, float radius) :
    LocalizedEntity(environment, pos, radius), m_status(running)
{
    s_agents.insert(this);
}

void Agent::setStatus(Agent::Status s)
{
    this->m_status = s;
}

Agent::Status Agent::getStatus() const
{
    return m_status;
}

void Agent::update()
{
    behaviour();
    draw();
}

void Agent::simulate()
{
    for (std::set<Agent*>::iterator it = s_agents.begin(); it != s_agents.end();)
    {
        Agent::Status s = (*it)->getStatus();
        switch (s)
        {
            case running:
                (*it)->update();
                ++it;
                break;
            case destroy:
                delete *it;
                it = s_agents.erase(it);
                break;
        }
    }
}

void Agent::finalize() {
    for (auto it = s_agents.begin(); it != s_agents.end();)
    {
        delete *it;
        it = s_agents.erase(it);
    }
}
