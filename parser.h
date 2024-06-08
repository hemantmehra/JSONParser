#pragma once

#include "Value.h"
#include "tokenizer.h"

class Parser
{
public:
    Parser(std::vector<Token*> tokens);
    Value* parse(size_t i);
    Object* parse_object(size_t i);
    Array* parse_array(size_t i);

private:
    std::vector<Token*> m_tokens;
};
