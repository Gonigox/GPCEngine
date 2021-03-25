#include <Input.hpp>
#include <Input_Task.hpp>

namespace engine
{
    bool Input::GetKey(Key_Code key)
    {
        return Input_Task::keystate[Input_Task::translate_sdl_scancode(key)];
    }

    bool Input::GetKeyDown(Key_Code key)
    {
        if(!Input_Task::KeyDown[key] && Input_Task::keystate[Input_Task::translate_sdl_scancode(key)])
        {
            Input_Task::KeyDown[key] = true;
            return true;
        }

        return false;
    }

    bool Input::GetKeyUp(Key_Code key)
    {
        if(Input_Task::KeyUp[key] && !Input_Task::keystate[Input_Task::translate_sdl_scancode(key)])
        {
            Input_Task::KeyUp[key] = false;
            return true;
        }

        return false;
    }

    
}
