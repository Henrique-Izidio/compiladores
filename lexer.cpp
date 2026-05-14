#include "lexer.h"
#include <iostream>
#include <sstream>

using std::unordered_map;
using std::stringstream;
using std::cin;
using std::cout;

char peek;
int line;

unordered_map<string, Id> id_table;

Lexer::Lexer(){

}

Token Lexer::Scan(){
    while (isspace(peek))
    {
        if(peek == '\n'){
            line = line + 1;
        }
        peek = cin.get();
    }

    if (isdigit(peek)){
        int v = 0;
        do {
            int n = peek - '0';
            v = 10 * v + n;
            peek = cin.get();
        }while (isdigit(peek));

        cout << "<NUM," << v << ">\n";
        
        return Num(v);
    }
    
    if(isalpha(peek)){
        stringstream ss;
        do {
            ss << peek;
            peek = cin.get();
        } while (isalpha(peek));

        string s = ss.str();

        auto pos = id_table.find(s);

        if(pos != id_table.end()){
            cout << "<ID," << pos->second.name << ">\n";
            return pos->second;
        }
        Id new_id(s);
        id_table.insert({s, new_id});
        cout << "<ID," << new_id.name << ">\n";

        return new_id;
    }

    Token t(peek);
    peek = cin.get();
    
    cout << "<" << char(t.tag) << ">\n";

    return t;
    
}

void Lexer::Start(){
    while(peek != '\n'){
        Scan();
    }
}