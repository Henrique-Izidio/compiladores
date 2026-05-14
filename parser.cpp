#include "parser.h"
#include <iostream>
#include <cctype>

using std::cin;
using std::cout;

void Parser::Expr() {
    Term();
    R();
}

void Parser::R(){
    switch (lookahead) {
        case '+':
            Match('+');
            Term();
            cout << "+";
            R();
            break;
        case '-':
            Match('-');
            Term();
            cout << "-";
            R();
            break;
        default:
        
        return;
    }
}

void Parser::Term(){
    if(isdigit(lookahead)){
        cout << lookahead;
        Match(lookahead);
    } else {
        cout << "Deu errado!\n";
    }
}

void Parser::Match(char t) {
    if (t == lookahead){
        lookahead = cin.get();
    } else {
        cout << "Caractere fora do padrão";
    }
}

Parser::Parser(){}

void Parser::Start(){
    lookahead = cin.get();
    Expr();
    if (lookahead == '\n')
    {
        cout << "\nSucesso!\n";
    }else {
        cout << "\nErro!\n";
    }
    
}