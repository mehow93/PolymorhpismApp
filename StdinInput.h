#ifndef STDININPUT_H
#define STDININPUT_H
#include "Input.h"

class StdinInput : public Input {
public:
    std::string getData();
    virtual ~StdinInput() = default;
};
#endif // STDININPUT_H

