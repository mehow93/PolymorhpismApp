#ifndef FILEINPUT_H
#define FILEINPUT_H

#endif // FILEINPUT_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Input.h"

class FileInput : public Input {

public:
    std::string getData(std::string source) override;



};
