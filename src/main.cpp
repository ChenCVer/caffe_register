#include <iostream>
#include <string>
#include "module_factory.hpp"
#include "face_detect.h"
#include "face_headpose.h"

#define TO_STRING(x) #x
#define ERROR_TO_STRING(x) TO_STRING(x)

using namespace std;


int main(int argc, char* argv[])
{
 
	auto face_detect = ModuleRegistry::get_instance()->creat_module("FaceDetect");
    ((FaceDetect*)face_detect)->draw_result();

	auto face_headpose = ModuleRegistry::get_instance()->creat_module("FaceHeadPose");
    ((FaceHeadPose*)face_headpose)->draw_result();

    return 0;
}