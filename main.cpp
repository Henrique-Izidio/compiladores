#include "parser.h"
#include "lexer.h"
#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    Lexer lexer;
    lexer.Start();
    cout << "\n";
    Parser tradutor;
    tradutor.Start();
}
