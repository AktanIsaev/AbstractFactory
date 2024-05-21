#ifndef PRINTOPERATOR_UNIT_H
#define PRINTOPERATOR_UNIT_H

#include <iostream>
#include "Unit.h"

class PrintOperatorUnit:public Unit
{
public:
    PrintOperatorUnit (const std::string& text): m_text(text){}

protected:
    std::string m_text;
};

#endif // PRINTOPERATOR_UNIT_H
