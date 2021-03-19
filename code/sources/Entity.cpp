#include <Entity.hpp>

engine::Entity::Entity() : transform(this)
{
    model_path = "";    
}

engine::Entity::Entity(std::string model) : transform(this)
{
    model_path = model;
}

bool engine::Entity::initialize()
{
    bool result = true;

    for (auto component : components)
    {
        if (component.second->initialize() == false)
        {
            result = false;
        }
    }

    return result;
}

bool engine::Entity::add_component(const std::string& type, std::shared_ptr<Component>& component)
{
    if (components.count(type) != 0)
    {
        return false;
    }
    else
    {
        components[type] = component;
        return true;
    }
}


void engine::Entity::delete_component(const std::string &component_name)
{
    components.erase(component_name);
}

bool engine::Entity::set_parent(Entity* parent)
{
    for(Entity* child : childs)
    {
        if(child == parent)
        {
            return false;
        }
    }

    parent->childs.push_back(this);
    return true;
}

std::list< engine::Entity* > & engine::Entity::get_childs()
{
    return childs;
}


