#include "tokenizer.h"

TokenType Token::type()
{
    return m_type;
}

Token::Token(TokenType type) : m_type(type)
{}

Token::Token(std::string s)
    : m_type(TokenType::StringLiteral), m_string(s)
{}

Token::Token(int i)
    : m_type(TokenType::IntLiteral), m_int(i)
{}

Token::Token(double i)
    : m_type(TokenType::DoubleLiteral), m_double(i)
{}

bool Token::isLiteral()
{
    switch (m_type)
    {
    case TokenType::StringLiteral:
    case TokenType::IntLiteral:
    case TokenType::DoubleLiteral:
    case TokenType::TrueLiteral:
    case TokenType::FalseLiteral:
    case TokenType::NullLiteral:
        return true;
    
    default:
        return false;
    }
}

std::string Token::get_string()
{
    return m_string;
}