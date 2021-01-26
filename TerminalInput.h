#ifndef TERMINALINPUT_H
#define TERMINALINPUT_H
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Input.h"
class TerminalInput : public Input {


public:
    virtual std::string getData(std::string source) override;
    virtual ~TerminalInput() = default;

};
#endif // TERMINALINPUT_H








