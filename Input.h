#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifndef BASEPARSER_H
#define BASEPARSER_H

#endif // BASEPARSER_H

class Input{
private:
    std::string mOrginalContent;
    std::string mProcessedContent;
public:
    std::string& getOrginalContent() { return mOrginalContent;}
    void setOrginalContent(std::string Input) {mOrginalContent = Input;}
    std::string getProcessesContent() { return mProcessedContent;}
    void setProcessedContent(std::string Input) {mProcessedContent = Input;}
    virtual ~Input() = default;
    virtual std::string getData(std::string source) = 0;


};

