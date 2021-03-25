#include <Script_Task.hpp>
#include <Script_Component.hpp>
#include <Scene.hpp>

namespace engine
{
    Script_Task::Script_Task(int priority, Scene & scene) : Task(priority)
    {
        _scene = &scene;
    }

    bool Script_Task::initialize()
    {
		set_script_components();
		return true;
    }

	bool Script_Task::finalize()
	{
		return false;
	}

	bool Script_Task::do_step(float time)
	{
		for(Script_Component * script : script_components)
		{
			script->Update();
		}
		return true;
	}

    void Script_Task::set_script_components()
    {
		auto    i_entity = _scene->get_entity_Map()->begin();
		auto last_entity = _scene->get_entity_Map()->end();

		if(_scene->get_entity_Map()->size() > 0)
		{
			while (i_entity != last_entity)
			{
				if(auto component = i_entity->second->get_Component("Script_Component"))
				{
					auto script_component = static_cast < Script_Component* > (component);
					script_component->Start();
					script_components.push_back(script_component);					
				}
	
				++i_entity;
			}
		}
    }
}