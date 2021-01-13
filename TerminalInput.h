#ifndef TERMINALINPUT_H
#define TERMINALINPUT_H

#endif // TERMINALINPUT_H

#include <sstream>
#include <fstream>
#include "Input.h"
#include "Operations.h"

class TerminalInput : public Input, public Operations{


public:

    virtual std::string deleteChar(std::string& inputString, char charToDelete) override;
    virtual std::string getData(std::string source) override;
    virtual ~TerminalInput() = default;

};

