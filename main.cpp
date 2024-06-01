#include <iostream>
#include "Value.h"

// enum TokenType
// {
//     LParen,
//     RParen,
//     Comma,
//     Colon,
//     LBrace,
//     RBrace,
//     String,
//     Number,
//     True,
//     False,
//     Null
// };

int main()
{
    Object o;
    o.add("abc", new String("xyz"));

    Array a1;
    a1.add(new String("x1"));
    o.add("values", &a1);
    o.add("ret", new Number(1));
    std::cout << o.toString() << '\n';
    return 0;
}
