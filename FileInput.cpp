
#include "FileInput.h"


std::string FileInput::getData(std::string source){
    std::ifstream fileOut;
    fileOut.open(source);
    std::string result;
    char c;
    if(fileOut.is_open()){ //start reading file if file was opened correctly
        while(fileOut.get(c)){
            result = result + c;
        }
    }
    else{
         result = "File doesn't exist!";
    }
    fileOut.close();
    return result;
}
