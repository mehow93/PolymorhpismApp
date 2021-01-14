#ifndef TERMINALINPUT_H
#define TERMINALINPUT_H

#endif // TERMINALINPUT_H

#include <sstream>
#include <fstream>
#include "Input.h"
#include "Operations.h"

class TerminalInput : public Input {


public:


    virtual std::string getData(std::string source) override;
};

