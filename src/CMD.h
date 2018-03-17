#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>

class CMD {
    public:
        CMD() { };
        virtual bool finished() = 0; 
        virtual string showString() = 0;
        virtual void setRun(bool toRun) = 0;
};

#endif