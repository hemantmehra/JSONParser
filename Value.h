#pragma once
#include <string>
#include <vector>

class Value
{
public:
    virtual std::string toString() = 0;
    virtual bool isObject() { return false; }
    virtual bool isArray() { return false; }
    virtual bool isString() { return false; }
    virtual bool isNumber() { return false; }
    virtual bool isTrue() { return false; }
    virtual bool isFalse() { return false; }
    virtual bool isNull() { return false; }
};

class Object : public Value
{
public:
    std::string toString() override;
    bool isObject() override { return true; }
    void add(std::string key, Value* value);

private:
    std::vector<std::pair<std::string, Value*>> m_members;
};

class Array : public Value
{
public:
    std::string toString() override;
    bool isArray() override { return true; }
    void add(Value* value);

private:
    std::vector<Value*> m_members;
};

class String : public Value
{
public:
    String(std::string s);
    std::string toString() override;
    bool isString() override { return true; }

private:
    std::string m_value;
};

class Number : public Value
{
public:
    Number(int i);
    Number(double i);
    std::string toString() override;
    bool isNumber() override { return true; }
    enum NumberType
    {
        INTEGER,
        DOBULE
    };
    NumberType type();
private:
    union value{
        int i;
        double d;
    };
    value m_value;
    NumberType m_type;
};

class True : public Value
{
public:
    std::string toString() override;
    bool isTrue() override { return true; }

private:
};

class False : public Value
{
public:
    std::string toString() override;
    bool isFalse() override { return true; }

private:
};

class Null : public Value
{
public:
    std::string toString() override;
    bool isNull() override { return true; }

private:
};
