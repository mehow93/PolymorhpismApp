#ifndef TERMINALINPUT_H
#define TERMINALINPUT_H

#endif // TERMINALINPUT_H

#include <sstream>
#include <fstream>
#include "Input.h"

class TerminalInput : public Input{



public:
    virtual std::string getData(std::string command) override;
    virtual std::string deleteChar(std::string& inputString, char charToDelete) override;
    virtual ~TerminalInput() = default;

};

