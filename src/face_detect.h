#ifndef _FACE_DETECT_H
#define _FACE_DETECT_H

#include "common_net.h"


class FaceDetect : public CommonNet
{
public:
    float det_input;

protected:
    float det_output;
    virtual void pre_process(const int orig_img);

public:
    FaceDetect();
    virtual ~FaceDetect();
    virtual void initialize(const int & input);
    virtual void draw_result() override;

private:
    virtual void post_process() override;
};


#endif //_FACE_DETECT_H