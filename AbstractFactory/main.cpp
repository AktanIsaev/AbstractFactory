#include <iostream>


#include "CppFactory.h"
#include "JavaFactory.h"
#include "SharpFactory.h"
#include "ProgramFactory.h"

int main()
{
    ProgramFactory* p = new ProgramFactory(std::make_unique<cpp_factory>());
    std::cout<<p->GenerateProgram_1();
    std::cout<<p->GenerateProgram_2();
    delete p;
    return 0;
}
