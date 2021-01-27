#ifndef FILEINPUT_H
#define FILEINPUT_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Input.h"
class FileInput : public Input {
private:
    std::string mFileName;
public:
    FileInput(std::string fileName) : mFileName(fileName){}
    virtual ~FileInput()=default;
    virtual std::string getData(std::string source) override;


};

#endif // FILEINPUT_H


