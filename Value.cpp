#include <sstream>
#include "Value.h"


void Object::add(std::string key, Value* value)
{
    auto p = std::make_pair(key, value);
    m_members.push_back(p);
}

std::string Object::toString()
{
    std::ostringstream ss;
    ss << "{\n";
    for (auto p : m_members)
    {
        ss << "\"" << p.first << "\"" << ": " << p.second->toString() << "\n";
    }
    ss << "}\n";
    return ss.str();
}

void Array::add(Value* value)
{
    m_members.push_back(value);
}

std::string Array::toString()
{
    std::ostringstream ss;
    ss << "[";
    for (auto i : m_members)
    {
        ss << i->toString() << " ";
    }
    ss << "]";
    return ss.str();
}

String::String(std::string s)
{
    m_value = s;
}

std::string String::toString()
{
    return "\"" + m_value + "\"";    
}

Number::Number(int i)
{
    m_value.i = i;
    m_type = INTEGER;
}

Number::Number(double i)
{
    m_value.d = i;
    m_type = DOBULE;
}

std::string Number::toString()
{
    switch (m_type)
    {
    case INTEGER:
        return std::to_string(m_value.i);
        break;
    
    case DOBULE:
        return std::to_string(m_value.d);
        break;
    
    default:
        return "";
        break;
    }
}

std::string True::toString()
{
    return "true";
}

std::string False::toString()
{
    return "false";
}

std::string Null::toString()
{
    return "null";
}
