#ifndef _FACE_HEADPOSE_H
#define _FACE_HEADPOSE_H

#include "common_net.h"


class FaceHeadPose : public CommonNet
{
public:
    float pose_input;

protected:
    float pose_output;
    virtual void pre_process(const int orig_img);

public:
    FaceHeadPose();
    virtual ~FaceHeadPose();
    virtual void initialize(const int & input);
    virtual void draw_result() override;

private:
    virtual void post_process() override;
};


#endif //_FACE_HEADPOSE_H