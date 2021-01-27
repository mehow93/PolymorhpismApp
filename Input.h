#ifndef BASEPARSER_H
#define BASEPARSER_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
class Input{
protected:
    std::string mOrginalContent = "defaultData";
    std::string mProcessedContent = "defaultData";
public:
    std::string& getOrginalContent() { return mOrginalContent;}
    std::string& getProcessesContent() { return mProcessedContent;}
    void setProcessedContent(std::string Input) {mProcessedContent = Input;}
    void setOriginalContent(std::string Input) {mOrginalContent = Input;}
    virtual ~Input() = default;
    virtual std::string getData() = 0;

};
#endif // BASEPARSER_H



