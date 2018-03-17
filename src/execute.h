#ifndef EXECUTE_H
#define EXECUTE_H

#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
//#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

class Execute : public CMD {
    public:
        Execute() { };
        Execute(string strInput);
        void setRun(bool toRun); //sets run as true if the connector allows this command to be executed
        string showString(); //outputs str
        bool finished(); //returns true if the command sucessfully finished
        void setParenIn(string in) { }
    private:
        string str;
        bool run; //is true if the previous connector allows this command to be exectued
};

Execute::Execute(string strInput) {
    str = strInput;
    run = true;
}

void Execute::setRun(bool toRun) {
    run = toRun;
}

string Execute::showString() {
    return str;
}

bool Execute::finished() {
    if (!run) {
        return true;
    }
    char* charString = strdup(str.c_str()); //convert string to char string
    char* args[1024]; // array for tokens
    char* token = strtok(charString, " "); 
    int i = 0;
    
    while (token != NULL){
        args[i] = token;
        //cout << args[i] << endl;
        ++i;
        token = strtok (NULL, " ");
    }
    //args[i] = 0;
    
    pid_t pid;
    pid_t wpid;
    int* status;
    
    pid = fork();
    if (pid == 0) {
        //Child process
        if (execvp(args[0], args) == -1) {
            cout << '"' << str << "\": FAILED" << endl;
            return false;
        }
    } 
    else if (pid < 0) {
        //Error in forking
        cout << '"' << str << "\": FAILED" << endl;
            return false;
    } 
    else {
        //Parent process
        do {
            wpid = waitpid(pid, status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return true;
}
