#include "TcpIpInput.h"



TcpIpInput::TcpIpInput(short port){
    mPort = port;
    std::string portAsString = std::to_string(mPort);
    std::string fullCommand = "nc -l "+ portAsString;
    const char* convertedCommand = fullCommand.c_str();
    static_cast<void>(std::system(convertedCommand)); //execute command

}

std::string TcpIpInput::getData(){
    return "defualtValue";
}
