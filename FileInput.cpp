
#include "FileInput.h"


std::string FileInput::getData(){
    std::ifstream fileOut;
    fileOut.open(this->mFileName);
    std::string result;
    char c;
    if(fileOut.is_open()){ //start reading file if file was opened correctly
        while(fileOut.get(c)){
              result = result + c;
        }
        fileOut.close();
    }
    else{
        result = "File doesn't exist!";
    }

    return result;
}
