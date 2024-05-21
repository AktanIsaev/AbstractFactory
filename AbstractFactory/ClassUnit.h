#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "Unit.h"
#include <iostream>
#include <vector>

class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

public:
    ClassUnit(const std::string& name): m_name(name){}
protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector< Fields > m_fields;
};

#endif // CLASSUNIT_H
