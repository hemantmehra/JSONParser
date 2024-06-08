#include <cassert>
#include "parser.h"

#define TOKEN_CHECK_LPAREN(x) (x->type() == TokenType::LParen)
#define TOKEN_CHECK_RPAREN(x) (x->type() == TokenType::RParen)
#define TOKEN_CHECK_LBRACE(x) (x->type() == TokenType::LBrace)
#define TOKEN_CHECK_RBRACE(x) (x->type() == TokenType::RBrace)
#define TOKEN_CHECK_STRING(x) (x->type() == TokenType::StringLiteral)
#define TOKEN_CHECK_COLON(x) (x->type() == TokenType::Colon)

Parser::Parser(std::vector<Token*> tokens) : m_tokens(tokens)
{
}

Value* Parser::parse(size_t i)
{
    assert(m_tokens.size() > i);

    if (TOKEN_CHECK_LPAREN(m_tokens.at(i)))
    {
        return parse_object(i+1);
    }

    if (TOKEN_CHECK_LBRACE(m_tokens.at(i)))
    {
        return parse_array(i+1);
    }

    return nullptr;
}

Object* Parser::parse_object(size_t i)
{
    if (TOKEN_CHECK_STRING(m_tokens.at(i)) &&
        TOKEN_CHECK_COLON(m_tokens.at(i+1)))
    {
        auto t1 = m_tokens.at(i);
        auto t2 = m_tokens.at(i+2);
        std::string k = t1->get_string();
        std::string v = t2->get_string();
        Object* o = new Object;
        o->add(k, new String(v));
        return o;
    }

    return nullptr;
}

Array* Parser::parse_array(size_t i)
{
    Array* a = new Array;
    return a;
}
