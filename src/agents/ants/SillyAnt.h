#ifndef ANTS_SILLYANT_H
#define ANTS_SILLYANT_H

#include "AntBase.h"

class SillyAnt : public AntBase
{
public:
    SillyAnt(Environment * env, Anthill * anthill);

    void behaviour() override;
};


#endif //ANTS_SILLYANT_H
