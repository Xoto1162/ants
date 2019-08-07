#include "AntFactory.h"

std::unique_ptr<AntFactory> AntFactory::s_singleton = nullptr;

AntFactory* AntFactory::getInstance()
{
    return s_singleton.get();
}

void AntFactory::initialize()
{
    s_singleton = std::unique_ptr<AntFactory>(new AntFactory());
}

void AntFactory::finalize()
{
    s_singleton = nullptr;
}
