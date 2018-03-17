#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#include "tokenizer.h"
#include "cmd.h"
#include "connector.h"
#include "execute.h"

int main() {
    bool loop = true;
    while(loop) {
    	cout << "$ ";
    	string input;
    	getline(cin, input);
    	int found = input.find('#');
    	
    	if (found != std::string::npos) {
    	    input = input.substr(0, found);
    	}
    	vector<CMD*> vec = tokenize(input);
    	bool toRun = true;
    	char* args[1024];
    	for (int i = 0; i < vec.size(); ++i) {
    	    if ((vec.at(i))->showString() == "exit") {
    	        cout << "exit rshell" << endl;
    	        loop = false;
    	        return 0;
    	    }
    	    else if ((vec.at(i))->showString() != ")") {
    	        toRun = (vec.at(i))->finished();
        	    if (i < vec.size()-1) {
        	        (vec.at(i+1))->setRun(toRun);
        	    }
    	    }
    	}
    }
    
    return 0;
}