#ifndef TCPIPINPUT_H
#define TCPIPINPUT_H
#include "Input.h"




class TcpIpInput : public Input {
private:
    short mPort;

public:
    TcpIpInput(short port);
    virtual ~TcpIpInput() = default;
    virtual std::string getData() override;

};



#endif // TCPIPINPUT_H
