#pragma once

#include <string>

enum TokenType {
    LParen,
    RParen,
    LBrace,
    RBrace,
    Colon,
    Comma,
    StringLiteral,
    IntLiteral,
    DoubleLiteral,
    TrueLiteral,
    FalseLiteral,
    NullLiteral
};

class Token
{
public:
    TokenType type();
    Token(TokenType);
    Token(std::string s);
    Token(int i);
    Token(double i);
    bool isLiteral();
    std::string get_string();

private:
    TokenType m_type;
    std::string m_string;
    int m_int;
    double m_double;
};
