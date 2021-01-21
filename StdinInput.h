#ifndef STDININPUT_H
#define STDININPUT_H

#endif // STDININPUT_H
#include "Input.h"

class StdinInput : public Input {
public:
    virtual std::string getData(std::string source) override;
};
