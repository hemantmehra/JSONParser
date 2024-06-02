#include <iostream>
#include "Value.h"
#include "tokenizer.h"

int main()
{
    Token t("abc");
    std::cout << t.isLiteral() << '\n';
    std::cout << (t.type() == Token::TokenType::StringLiteral) << '\n';

    Object o;
    o.add("abc", new String("xyz"));

    Array a1;
    a1.add(new String("x1"));
    o.add("values", &a1);
    o.add("ret", new Number(1));
    std::cout << o.toString() << '\n';
    return 0;
}
