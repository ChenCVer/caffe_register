#ifndef _COMMON_NET_H
#define _COMMON_NET_H

#include <iostream>

#include "module_factory.hpp"

class CommonNet
{
public:
    float input;

protected:
    float output;
    virtual void pre_process(const int orig_img);
    void forward_(const float& img);

public:
    CommonNet();
    virtual ~CommonNet();
    virtual void initialize(const int & input);
    virtual void draw_result() = 0;

private:
    virtual void post_process() = 0;
};

#endif //_COMMON_NET_H