#include <iostream>

using std::cin;
using std::cout;

void Parser::Match(char t) {
    if (t == lookahead){
        lookahead = cin.get();
    } else {
        cout << "Caractere fora do padrão";
    }
}

void Parser::Term(){
    if(isdigit(lookahead)){
        Match(lookahead);
    } else {
        cout << "Deu merda no termo... Vagabundo\n";
    }
}

void Parser::R(){
    switch (lookahead)
    {
    case "+":
        Match("+");
        Term();
        cout <<("+");
        R();
        break;
    case "-":
        Match("-");
        Term();
        cout <<("-");
        R();
        break;
    default:
        return;
    
    return;
}

void Parser::Expr() {
    Term();
    R();
}

Parser::Parser(){}

void Parser::Start(){
    lookahead = cin.get();
    Expr();
    if lookahead
}