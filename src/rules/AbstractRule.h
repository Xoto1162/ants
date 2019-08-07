#ifndef ANTS_ABSTRACTRULE_H
#define ANTS_ABSTRACTRULE_H

class AbstractRule
{
public:
    virtual ~AbstractRule() = default;
    virtual bool condition() = 0;
    virtual void action() = 0;
};

#endif //ANTS_ABSTRACTRULE_H
