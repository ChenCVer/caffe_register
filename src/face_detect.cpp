#include "face_detect.h"
#include "module_factory.hpp"


FaceDetect::FaceDetect() = default;

FaceDetect::~FaceDetect() = default;

void FaceDetect::initialize(const int & input)
{
    std::cout << "this FaceDetect initialize." << std::endl;
}


void FaceDetect::pre_process(const int orig_img)
{
    std::cout << "this FaceDetect pre_process." << std::endl;
}


void FaceDetect::post_process()
{
    std::cout << "this face detect post process." << std::endl;
}


void FaceDetect::draw_result()
{
    std::cout << "this is face detect draw result." << std::endl;
}


REGISTER_MODULE(FaceDetect);