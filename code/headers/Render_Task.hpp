/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once

#include <Task.hpp>
#include <memory>
#include <string>
#include <internal/declarations.hpp>

namespace engine
{
	class Scene;
	class Window;

	/**
	 * @brief Render_Task
	 *
	 * @details Task in charge of rendering all 3D models from the Entities in the scene
	 */
    class Render_Task : public Task
    {
	protected:

		/**
		 * @brief Pointer to the scene
		 *
		 */
		Scene  *_scene  = nullptr;
		/**
		 * @brief Pointer to the window
		 *
		 */
		Window *_window = nullptr;
		/**
		 * @brief Pointer to the Render_node
		 *
		 */
		std::shared_ptr< glt::Render_Node > _renderer;

	public:

		Render_Task(int priority, Window &win, Scene &scene);

	   ~Render_Task(){}

	private:

		virtual bool initialize() override;
		virtual bool finalize() override;
		virtual bool do_step(float time) override;

		/**
		 * @brief Set the render transform object
		 *
		 * @details Modifi the render transform of the Entities in sintony whit the Transfrom_component of them
		 */
		void set_render_transform();
		/**
		 * @brief Charge models of the scene
		 *
		 */
		void set_models();

    };
}