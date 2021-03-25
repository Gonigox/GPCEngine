/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: March/2021
    email: gonigox@gmail.com
*/

#pragma once

#include <Task.hpp>
#include <Input.hpp>
#include <Window.hpp>

namespace engine
{
    
    class Input_Task : public Task
    {
    protected:

        Window *      window;

        Window::Event engine_event;
        
        static const unsigned char * keystate;
        static bool KeyDown[KEY_NUM];
        static bool KeyUp  [KEY_NUM];

    public:

        Input_Task(int priority, Window & win);

        static Key_Code translate_sdl_to_key_code (int sdl_scancode);

    private:

		virtual bool initialize() override;

		virtual bool finalize() override;

		virtual bool do_step(float time) override;

        static int   translate_sdl_scancode(Key_Code key);
        

        friend class Input;
    };    

}