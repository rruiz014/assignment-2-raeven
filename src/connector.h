#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <fstream>
#include "tokenizer.h"

vector<CMD*> tokenize(string input);

class Connector : public CMD {
    public:
        Connector() { };
        Connector(string strInput);
        void setRun(bool toRun); //sets run to true if the previous command sucessfully finished
        string showString(); //outputs str
        bool finished(); //returns true if next command can be executed
    private:
        string str;
        bool run; //stores true if previous command sucessfully finished
};

Connector::Connector(string strInput) {
    str = strInput;
    run = true;
}

void Connector::setRun(bool toRun) {
    run = toRun;
}

string Connector::showString() {
    return str;
}

bool Connector::finished() {
    if (str == ";") {
        return true;
    }
    else if (str == "||") {
        if (run) {
            return false;
        }
        else {
            return true;
        }
    }
    else if (str == "&&") {
        if (run) {
            return true;
        }
        else {
            return false;
        }
    }
    
}

#endif