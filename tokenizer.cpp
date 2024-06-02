#include "tokenizer.h"

Token::TokenType Token::type()
{
    return m_type;
}

Token::Token(Token::TokenType type) : m_type(type)
{}

Token::Token(std::string s)
    : m_type(Token::TokenType::StringLiteral), m_string(s)
{}

Token::Token(int i)
    : m_type(Token::TokenType::IntLiteral), m_int(i)
{}

Token::Token(double i)
    : m_type(Token::TokenType::DoubleLiteral), m_double(i)
{}

bool Token::isLiteral()
{
    switch (m_type)
    {
    case Token::TokenType::StringLiteral:
    case Token::TokenType::IntLiteral:
    case Token::TokenType::DoubleLiteral:
    case Token::TokenType::TrueLiteral:
    case Token::TokenType::FalseLiteral:
    case Token::TokenType::NullLiteral:
        return true;
    
    default:
        return false;
    }
}
