#ifndef TERMINALINPUT_H
#define TERMINALINPUT_H
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Input.h"
class TerminalInput : public Input {
private:
    std::string mCommand;
public:
    TerminalInput(std::string Command) : mCommand(Command){}
    virtual ~TerminalInput() = default;
    virtual std::string getData() override;


};
#endif // TERMINALINPUT_H








