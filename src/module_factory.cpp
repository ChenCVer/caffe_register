#include "module_factory.hpp"


ModuleRegistry::ModuleRegistry() = default;

void* ModuleRegistry::creat_module(const std::string& module_name)
{  
    std::map<std::string, Creator>::const_iterator iter;  
    
    iter = module_map.find(module_name);  
    if ( iter == module_map.end())  
        return NULL;  
    else  
        return iter->second();  
}  


void ModuleRegistry::register_module(const std::string& name, Creator& creator)
{  
    if(module_map.count(name) != 0)
    {
       std::cout << "Module type: " << name << " already registered.";
       return;
    }
    module_map[name] = creator;  
}  


ModuleRegistry* ModuleRegistry::get_instance()
{
    static ModuleRegistry* module_registry = new ModuleRegistry();  
    return module_registry;  
}
