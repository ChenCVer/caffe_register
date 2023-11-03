#include "common_net.h"


CommonNet::CommonNet() = default;

CommonNet::~CommonNet() = default;


void CommonNet::initialize(const int & input)
{
    std::cout << "this is CommonNet initilize." << std::endl;
}


void CommonNet::pre_process(const int orig_img)
{
    std::cout << "this is CommonNet pre process." << std::endl;    
}


void CommonNet::forward_(const float& img)
{
    std::cout << "this is CommonNet forward_." << std::endl; 
}