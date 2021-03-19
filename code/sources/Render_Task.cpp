#include <Render_Task.hpp>
#include <Render_Node.hpp>
#include <Light.hpp>
#include <Camera.hpp>
#include <Entity.hpp>
#include <Scene.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Window.hpp>
#include <iostream>
#include <glm/gtx/quaternion.hpp>


engine::Render_Task::Render_Task(int priority, Window &win, Scene &scene) : Task(priority)
{
	_window = &win;
	_scene  = &scene;
	_renderer.reset(new glt::Render_Node);

	std::shared_ptr< glt::Camera > camera(new glt::Camera(50.f, 0.5f, 300.f, 1.f));
	std::shared_ptr< glt::Light >  light (new glt::Light);

	_renderer->add("CameraMain", camera);
	_renderer->get("CameraMain")->translate(glt::Vector3(0.f, -12.f, 60.f));
	_renderer->get("CameraMain")->rotate_around_x(0.2f);

	_renderer->add("Light", light);	
	_renderer->get("Light")->translate(glt::Vector3(0.f, 50.f, 10.f));
	
	set_render_transform();
}

bool engine::Render_Task::initialize()
{
	int width, height;

	set_models();
	
	_window->get_window_dimensions(&width, &height);

	_renderer->get_active_camera()->set_aspect_ratio(float(width) / (float)height);

	glViewport(0, 0, width, height);

	return true;
}


bool engine::Render_Task::finalize()
{
	return false;
}

bool engine::Render_Task::do_step(float time)
{	
	set_render_transform();
	_window->clear();
	_renderer->render();
	_window->swap_buffers();

	return true;
}

void engine::Render_Task::set_render_transform()
{
	auto    i_entity = _scene->get_entity_Map()->begin();
	auto last_entity = _scene->get_entity_Map()->end();
	
	if(_scene->get_entity_Map()->size() > 0)
	{
		while (i_entity != last_entity)
		{
			glt::Node* model			   = _renderer->get(i_entity->first);
			Transform_Component* transform = i_entity->second->get_transform_component();

			// Calculate traslation
			glm::mat4 mtx_tras
			(
						1.f,					0.f,				   0.f,			   0.f,
						0.f,					1.f,				   0.f,		       0.f,
						0.f,					0.f,				   1.f,		       0.f,
				transform->position.x,  transform->position.y, transform->position.z,  1.f
			);

			// Calculate scale
			glm::mat4 mtx_scale
			(
				transform->scale.x,			0.f,				0.f,		0.f,
						0.f,		transform->scale.y,			0.f,		0.f,
						0.f,				0.f,		transform->scale.z, 0.f,
						0.f,				0.f,				0.f,		1.f
			);

			// Calculate rotation			
			Vector3 radAngle
			(
				glm::radians(transform->rotation.x), 
				glm::radians(transform->rotation.y), 
				glm::radians(transform->rotation.z)
			);
			//X rotation
			glm::mat4 mtx_rot
			(
				1.f,	  0.f,				0.f,		 0.f,
				0.f, cos(radAngle.x), -sin(radAngle.x),  0.f,
				0.f, sin(radAngle.x),  cos(radAngle.x),  0.f,
				0.f,	  0.f,				0.f,	     1.f
			);

			//Y rotation
			mtx_rot *= glm::mat4
			(
				 cos(radAngle.y), 0.f, sin(radAngle.y),  0.f,
					  0.f, 	      1.f,		0.f,		 0.f, 
				-sin(radAngle.y), 0.f, cos(radAngle.y),  0.f,
					  0.f,		  0.f,		0.f,	     1.f
			);

			//Z rotation
			mtx_rot *= glm::mat4
			(
				cos(radAngle.z), -sin(radAngle.z),  0.f,  0.f,
				sin(radAngle.z),  cos(radAngle.z),  0.f,  0.f, 
					 0.f,			   0.f,			1.f,  0.f,
					 0.f,			   0.f,			0.f,  1.f
			);

			// Final transformation
			glm::mat4 mtx_transform(mtx_tras * mtx_scale * mtx_rot);

			model->set_transformation(mtx_transform);

			++i_entity;
		}
	}
	
}

void engine::Render_Task::set_models()
{
	auto    i_entity = _scene->get_entity_Map()->begin();
	auto last_entity = _scene->get_entity_Map()->end();

	if(_scene->get_entity_Map()->size() > 0)
	{
		while (i_entity != last_entity)
		{
			std::shared_ptr< glt::Model > new_model(new glt::Model_Obj(i_entity->second->get_model_path()));

			_renderer->add(i_entity->first, new_model);
			
			std::cout << "\n" << i_entity->first << " Charged";

			++i_entity;
		}
	}	
}
