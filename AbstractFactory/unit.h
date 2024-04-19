#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <vector>
#include <string>

class Unit {
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags ) = 0;
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual std::string generateShift( unsigned int level ) const;
};

class ClassUnit : public Unit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const std::string& name );
    ClassUnit(const ClassUnit&) = default; // Конструктор копирования
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override;
    std::string compile( unsigned int level = 0 ) const override;
private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags );
    void add( const std::shared_ptr< Unit >& unit, Flags flags = 0 ) override;
    std::string compile( unsigned int level = 0 ) const override;
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text );
    void add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) override;
    std::string compile( unsigned int level = 0 ) const override;
private:
    std::string m_text;
};

std::string generateProgram();

#endif // UNIT_H
