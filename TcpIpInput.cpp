#include "TcpIpInput.h"



TcpIpInput::TcpIpInput(short port, unsigned short domain, unsigned int type){

    mAddress.sin_port = htons(port);
    mAddress.sin_family = domain;
    mAddress.sin_addr.s_addr = type;
    int opt = 1;

    // Creating socket file descriptor
    if ((mServerFile = socket(domain, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(mServerFile, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }


    // Forcefully attaching socket to the port
    if (bind(mServerFile,(struct sockaddr *)&mAddress,sizeof(mAddress))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

std::string TcpIpInput::getData(){
    int newSocket, valRead;
    int addrLen = sizeof(this->mAddress);
    if (listen(this->mServerFile, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((newSocket = accept(this->mServerFile, (struct sockaddr *)&(this->mAddress),
                       (socklen_t*)&addrLen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valRead = read(newSocket , this->mBuffer, 1024);
    printf("%s\n",this->mBuffer );


    return "";
}
