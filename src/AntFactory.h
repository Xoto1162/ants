#ifndef ANTS_ANTFACTORY_H
#define ANTS_ANTFACTORY_H

#include <memory>
#include "agents/Anthill.h"

class AntFactory
{
private:
    static std::unique_ptr<AntFactory> s_singleton;

public:
    static AntFactory* getInstance();
    static void initialize();
    static void finalize();

private:
    AntFactory() = default;

public:
    template<typename T>
    T* createAnt(Anthill *anthill)
    {
        return new T(anthill->getEnvironment(), anthill);
    }


};


#endif //ANTS_ANTFACTORY_H
