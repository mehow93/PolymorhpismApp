#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifndef BASEPARSER_H
#define BASEPARSER_H

#endif // BASEPARSER_H

class Input{
protected:
    std::string mOrginalContent;
    std::string mProcessedContent;
public:
    std::string& getOrginalContent() { return mOrginalContent;}    
    std::string getProcessesContent() { return mProcessedContent;}
    void setProcessedContent(std::string Input) {mProcessedContent = Input;}
    void setOriginalContent(std::string Input) {mOrginalContent = Input;}
    virtual ~Input() = default;
    virtual void getData(std::string source) = 0;

};

