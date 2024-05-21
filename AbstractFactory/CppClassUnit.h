#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "ClassUnit.h"

class cpp_class_unit :public ClassUnit
{
public:

    cpp_class_unit(const std::string & name):ClassUnit(name)
    {
        m_fields.resize( PRIVATE + 1);

    }

    void add (const std::shared_ptr<Unit>& unit, Flags flags)
    {
        Flags accessModifier = PRIVATE;
        if (flags<accessModifier)
        {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < m_fields.size(); ++i )
        {
            if( m_fields[ i ].empty() )
            {
                continue;
            }
            if (i == PUBLIC)
            {
                result+= "public:\n";
            }
            else if (i == PROTECTED)
            {
                result+= "protected:\n";
            }
            else if (i == PRIVATE)
            {
                result+= "private:\n";
            }
            for( const auto& f : m_fields[ i ] )
            {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }

        result += generateShift( level ) + "};\n";

        return result;
    }
};

#endif // CPPCLASSUNIT_H
