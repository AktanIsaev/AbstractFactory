#ifndef METHODUNIT_H
#define METHODUNIT_H
#include"Unit.h"
#include"ClassUnit.h"

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags):
        _name( name ), _returnType( returnType ), _flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override{
        _body.push_back( unit );
    }

protected:
    std::string _name;
    std::string _returnType;
    Flags _flags;
    std::vector< std::shared_ptr< Unit > > _body;
};
#endif // METHODUNIT_H
