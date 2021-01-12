#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifndef BASEPARSER_H
#define BASEPARSER_H

#endif // BASEPARSER_H

class Input{

public:

    virtual std::string getData(std::string source) = 0;
    virtual std::string deleteChar(std::string& inputString, char charToDelete) = 0;
    virtual ~Input() = default;

};

