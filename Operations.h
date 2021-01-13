#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef OPERATIONS_H
#define OPERATIONS_H

#endif // OPERATIONS_H


class Operations {

public:
    virtual ~Operations() = default;
    virtual std::string deleteChar(std::string& inputString, char charToDelete) = 0;


};
