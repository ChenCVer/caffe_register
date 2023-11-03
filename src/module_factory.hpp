#ifndef _MODULE_FACTORY_H
#define _MODULE_FACTORY_H

#include <map>
#include <string>
#include <iostream>

/*
factory and single model.
reference: https://github.com/BVLC/caffe/blob/master/include/caffe/layer_factory.hpp
code interpretation: https://blog.csdn.net/u013171226/article/details/121450408
code interpretation: https://developer.aliyun.com/article/986530
*/

typedef void* (*Creator)();


class ModuleRegistry
{
private:  
    std::map<std::string, Creator> module_map;  
	ModuleRegistry();
	
public:   
    void* creat_module(const std::string& module_name);  
    void register_module(const std::string& name, Creator& method);  
    static ModuleRegistry* get_instance();  
};
 

class ModuleRegisterer
{
public:
	ModuleRegisterer(const std::string& module_name, Creator creator)
    {
		ModuleRegistry::get_instance()->register_module(module_name, creator);
	}
};


#define REGISTER_MODULE(module_name) 					      \
	module_name* module_creator##module_name()                \
    {     		  					                          \
        return new module_name;                               \
    }                                                         \
    ModuleRegisterer g_creator_registerer##module_name(       \
		#module_name, (Creator)module_creator##module_name)

#endif // _MODULE_FACTORY_H
