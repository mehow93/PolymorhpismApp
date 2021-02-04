#ifndef TCPIPINPUT_H
#define TCPIPINPUT_H
#include "Input.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>




class TcpIpInput : public Input {
private:
    short mPort;
    struct sockaddr_in mAddress;
    char mBuffer[1024] = {0};
    int mServerFile;

public:
    TcpIpInput(short port, unsigned short domain, unsigned int type);
    virtual ~TcpIpInput() = default;
    virtual std::string getData() override;
    std::string bufferToString();

};



#endif // TCPIPINPUT_H
