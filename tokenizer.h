#pragma once

#include <string>

class Token
{
public:
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

    TokenType type();
    Token(TokenType);
    Token(std::string s);
    Token(int i);
    Token(double i);
    bool isLiteral();

private:
    TokenType m_type;
    std::string m_string;
    int m_int;
    double m_double;
};
