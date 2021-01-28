#include "StdinInput.h"

std::string StdinInput::getData(){
    std::string lineInput;
    std::string result = "";

    while (getline(std::cin,lineInput)) {
        result += (lineInput + '\n');

    }
    return result;

}
