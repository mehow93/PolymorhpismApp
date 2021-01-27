
#include "TerminalInput.h"



std::string TerminalInput:: getData(){
    std::ostringstream sstr;
    std::string fullCommand = this->mCommand + " > test.txt";
    const char* convertedCommand = fullCommand.c_str();
    static_cast<void>(std::system(convertedCommand)); //execute command
    sstr << std::ifstream("test.txt").rdbuf();

    return sstr.str();
}


