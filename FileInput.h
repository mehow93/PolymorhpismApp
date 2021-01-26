#ifndef FILEINPUT_H
#define FILEINPUT_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Input.h"
class FileInput : public Input {

public:
    virtual std::string getData(std::string source) override;
    virtual ~FileInput()=default;

};

#endif // FILEINPUT_H


