#include <iostream>
#include "Value.h"
#include "tokenizer.h"
#include "parser.h"

int main()
{
    Token t("abc");
    std::cout << t.isLiteral() << '\n';
    std::cout << (t.type() == TokenType::StringLiteral) << '\n';

    std::vector<Token*> l;
    l.push_back(new Token(TokenType::LParen));
    l.push_back(new Token("key0"));
    l.push_back(new Token(TokenType::Colon));
    l.push_back(new Token("test_value1"));
    l.push_back(new Token(TokenType::RParen));

    Parser parser(l);
    auto obj = parser.parse(0);
    std::cout << obj->toString() << '\n';

    // Object o;
    // o.add("abc", new String("xyz"));

    // Array a1;
    // a1.add(new String("x1"));
    // o.add("values", &a1);
    // o.add("ret", new Number(1));
    // std::cout << o.toString() << '\n';
    return 0;
}
