/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: March/2021
    email: gonigox@gmail.com
*/

#pragma once
#include <Task.hpp>
#include <Script_Component.hpp>

namespace engine
{
    class Scene;

    class Script_Task : public Task
    {
    protected:

        Scene * _scene;

        std::list < Script_Component * > script_components; 

    public:

        Script_Task(int priority, Scene & scene);

        bool initialize();

        bool finalize();

        bool do_step(float time);

    private:

        void set_script_components();
    };
}
