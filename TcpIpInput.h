#ifndef TCPIPINPUT_H
#define TCPIPINPUT_H
#include "Input.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>




class TcpIpInput : public Input {
private:
    short mPort;
    struct sockaddr_in mAddress;
    char mBuffer[1024] = {0};
    int mServerFile;

public:
    //domain - integer, communication domain e.g., AF_INET (IPv4 protocol) , AF_INET6 (IPv6 protocol)
    //type: communication type SOCK_STREAM: TCP
    //SOCK_DGRAM: UDP
    TcpIpInput(uint16_t port, unsigned short domain = AF_INET, unsigned int type =INADDR_ANY);
    virtual ~TcpIpInput() = default;
    virtual std::string getData() override;
    std::string bufferToString();

};

//AF_INET,INADDR_ANY

#endif // TCPIPINPUT_H
