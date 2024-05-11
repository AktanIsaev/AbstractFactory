#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"Unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;

public:
    ClassUnit( const std::string& name ) : _name( name ) {
        _fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        _fields[ accessModifier ].push_back( unit );
    }

protected:
    std::string _name;
    using Fields = std::vector< std::shared_ptr<Unit> >;
    std::vector< Fields > _fields;
};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private",
                                                              "internal", "protected_internal", "private_protected" };

#endif // CLASSUNIT_H
