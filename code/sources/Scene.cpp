#include <Scene.hpp>

engine::Scene::Scene(const std::string& title, int width, int height, bool fullscreen) :     
    window(title, width, height, fullscreen), 
    kernel(window, *this), 
    root()
{
    
}

void engine::Scene::start_game()
{
    kernel.execute();
}

void engine::Scene::add_Entity(const std::string &name, Entity *new_Entity)
{    
    entity_Map.insert(std::make_pair(name, new_Entity));

    new_Entity->set_parent(&root);
}

void engine::Scene::add_Entity
(
    std::string const &name, 
    Entity*     new_Entity, 
    Vector3*    pos, 
    Vector3*    rot, 
    Vector3*    scale
)
{
    entity_Map.insert(std::make_pair(name, new_Entity));

    new_Entity->set_parent(&root);

    new_Entity->get_transform_component()->set_transform(pos);
    new_Entity->get_transform_component()->set_rotation(rot);
    new_Entity->get_transform_component()->set_scale(scale);
}
