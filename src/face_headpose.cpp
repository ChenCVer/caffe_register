#include "face_headpose.h"
#include "module_factory.hpp"

FaceHeadPose::FaceHeadPose() = default;

FaceHeadPose::~FaceHeadPose() = default;

void FaceHeadPose::initialize(const int & input)
{
    std::cout << "this FaceHeadPose initialize." << std::endl;
}


void FaceHeadPose::pre_process(const int orig_img)
{
    std::cout << "this FaceHeadPose pre_process." << std::endl;
}


void FaceHeadPose::post_process()
{
    std::cout << "this FaceHeadPose post process." << std::endl;
}


void FaceHeadPose::draw_result()
{
    std::cout << "this is FaceHeadPose draw result." << std::endl;
}


REGISTER_MODULE(FaceHeadPose);