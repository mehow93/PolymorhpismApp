
#include "TerminalInput.h"



std::string TerminalInput:: getData(std::string command){
    std::ostringstream sstr;
    std::string fullCommand = command + " > test.txt";
    const char* convertedCommand = fullCommand.c_str();
    static_cast<void>(std::system(convertedCommand)); //execute command
    sstr << std::ifstream("test.txt").rdbuf();
    //std::cout <<  std::ifstream("test.txt").rdbuf();
    return sstr.str();
}

std::string TerminalInput:: deleteChar(std::string& inputString, char charToDelete){
    std::string result = inputString; //copy string to avoid overwritting orginal input

    for (auto& stringChar : result){
        if( stringChar == charToDelete)
            stringChar = '_';
    }

    return result;
}
