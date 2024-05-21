#ifndef FACTORY_H
#define FACTORY_H

#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

#include <iostream>
class factory
{
public:
    virtual std::shared_ptr<ClassUnit> Create_Class(const std::string name) = 0;
    virtual std::shared_ptr<MethodUnit> Create_Method(const std::string &func_name,
                                                      const std::string &return_type,
                                                      const unsigned int &modificator) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> Create_Print(const std::string &body) = 0;

    virtual ~factory(){}
};

#endif // FACTORY_H
