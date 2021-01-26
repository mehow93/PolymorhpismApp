#ifndef STDININPUT_H
#define STDININPUT_H
#include "Input.h"

class StdinInput : public Input {
public:
    std::string getData();
    virtual ~StdinInput()override;
};
#endif // STDININPUT_H

