#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>
#include <string>
#include "cmd.h"
#include "connector.h"
#include "execute.h"
using namespace std;

vector<CMD*> tokenize(string input) {
    int i = 0;
    string strExec; //stores the command that will be stored as an Execute object
    string strCon; //stores the connector that will be stored as a Connector object
    vector<CMD*> token;
    
    while (i != input.size()) { //iterates through the input 
        if ((input.at(i) == '|') && (input.at(i+1) == '|')) {
            strExec = input.substr(0, i-1);
            strCon = "||";
            input = input.substr(i+3, input.size()-1);
            i = 0;
            if (strExec.size() != 0) {
                token.push_back(new Execute(strExec));
            }
            token.push_back(new Connector(strCon));
        }
        else if ((input.at(i) == '&') && (input.at(i+1) == '&')) {
            strExec = input.substr(0, i-1);
            strCon = "&&";
            input = input.substr(i+3, input.size()-1);
            i = 0;
            if (strExec.size() != 0) {
                token.push_back(new Execute(strExec));
            }
            token.push_back(new Connector(strCon));
        }
        else if (input.at(i) == ';') {
            strExec = input.substr(0, i);
            strCon = ";";
            input = input.substr(i+2, input.size()-1);
            i = 0;
            token.push_back(new Execute(strExec));
            token.push_back(new Connector(strCon));
        }
       
        i = i+1;
    }
    token.push_back(new Execute(input));
    return token;
}

#endif