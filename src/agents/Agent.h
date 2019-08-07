#ifndef ANTS_AGENT_H
#define ANTS_AGENT_H

#include "../Environment.h"
#include "../utils/Vector2.h"

class Agent : public Environment::LocalizedEntity
{
public:
    /**
     * Status possible pour un agent
     */
    typedef enum { running, destroy } Status;

    /**
     * Met a jour tout les agents
     */
    static void simulate();

    /**
     * Detruit tout les agents
     */
    static void finalize();

private:
    /**
     * Contient tout les agents
     */
    static std::set<Agent*> s_agents;

    /**
     * Status de l'agent
     */
    Status m_status;

public:
    Agent(Environment *environment, const Vector2<float> & pos, float radius = Environment::LocalizedEntity::defaultRadius());

    /**
     * Permet de definir les status d'un agent
     * @param s     Nouveau status
     */
    void setStatus(Status s);

    /**
     * Indique le status actuel de l'agent
     * @return status actuel de l'agent
     */
    Status getStatus() const;

    /**
     * Dessine l'agent
     */
    virtual void draw() const = 0;

    /**
     * Realise une etape du comportement de l'agent
     */
    virtual void behaviour() = 0;

    /**
     * Met a jour l'agent et le dessine
     */
    virtual void update();

};


#endif //ANTS_AGENT_H
