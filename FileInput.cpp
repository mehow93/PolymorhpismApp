
#include "FileInput.h"


std::string FileInput::getData(std::string source){
    std::ifstream fileOut;
    fileOut.open(source);
    std::string result;
    char c;
    while(fileOut.get(c)){
        result = result + c;
    }
    fileOut.close();
    return result;
}
