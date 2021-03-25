#include <Input_Task.hpp>
#include <Kernel.hpp>
#include <SDL.h>


namespace engine
{
    const Uint8 * Input_Task::keystate = SDL_GetKeyboardState(NULL);
    
    bool Input_Task::KeyDown[] = {false};
    bool Input_Task::KeyUp  [] = {false};

    Input_Task::Input_Task(int priority, Window & win) : Task(priority)
    {
        window = &win;
    }
    
    bool Input_Task::initialize()
    {
        for (int i = 0; i < KEY_NUM; ++i)
	    {
	    	KeyDown[i] = false;
            KeyUp  [i] = false;
	    }

        return true;
    }
    
    bool Input_Task::finalize()
    {
        return false;
    }
    
    bool Input_Task::do_step(float time)
    {
        window->poll(engine_event);
        
        switch(engine_event.type)
        {
        case Window::Event::CLOSE:
            kernel->exit = true;
            break;
    
        case Window::Event::KEY_RELEASED:
            KeyDown[engine_event.data.keyboard.key_code] = false;
            break;
    
        case Window::Event::KEY_PRESSED:
            KeyUp  [engine_event.data.keyboard.key_code] = true;
            break;
        }   
        
        return true;
    }

    int Input_Task::translate_sdl_scancode(Key_Code key)
    {
        switch (key)
        {
            case KEY_RETURN:         return SDL_SCANCODE_RETURN;   
            case KEY_ESCAPE:         return SDL_SCANCODE_ESCAPE;   
            case KEY_BACKSPACE:      return SDL_SCANCODE_BACKSPACE;
            case KEY_TAB:            return SDL_SCANCODE_TAB;      
            case KEY_SPACE:          return SDL_SCANCODE_SPACE; 

            case KEY_A:              return SDL_SCANCODE_A;        
            case KEY_B:              return SDL_SCANCODE_B;        
            case KEY_C:              return SDL_SCANCODE_C;        
            case KEY_D:              return SDL_SCANCODE_D;        
            case KEY_E:              return SDL_SCANCODE_E;        
            case KEY_F:              return SDL_SCANCODE_F;        
            case KEY_G:              return SDL_SCANCODE_G;        
            case KEY_H:              return SDL_SCANCODE_H;        
            case KEY_I:              return SDL_SCANCODE_I;        
            case KEY_J:              return SDL_SCANCODE_J;        
            case KEY_K:              return SDL_SCANCODE_K;        
            case KEY_L:              return SDL_SCANCODE_L;        
            case KEY_M:              return SDL_SCANCODE_M;        
            case KEY_N:              return SDL_SCANCODE_N;        
            case KEY_O:              return SDL_SCANCODE_O;        
            case KEY_P:              return SDL_SCANCODE_P;        
            case KEY_Q:              return SDL_SCANCODE_Q;        
            case KEY_R:              return SDL_SCANCODE_R;        
            case KEY_S:              return SDL_SCANCODE_S;        
            case KEY_T:              return SDL_SCANCODE_T;        
            case KEY_U:              return SDL_SCANCODE_U;        
            case KEY_V:              return SDL_SCANCODE_V;        
            case KEY_W:              return SDL_SCANCODE_W;        
            case KEY_X:              return SDL_SCANCODE_X;        
            case KEY_Y:              return SDL_SCANCODE_Y;        
            case KEY_Z:              return SDL_SCANCODE_Z;

            case KEY_0:              return SDL_SCANCODE_0;        
            case KEY_1:              return SDL_SCANCODE_1;        
            case KEY_2:              return SDL_SCANCODE_2;        
            case KEY_3:              return SDL_SCANCODE_3;        
            case KEY_4:              return SDL_SCANCODE_4;        
            case KEY_5:              return SDL_SCANCODE_5;        
            case KEY_6:              return SDL_SCANCODE_6;        
            case KEY_7:              return SDL_SCANCODE_7;        
            case KEY_8:              return SDL_SCANCODE_8;        
            case KEY_9:              return SDL_SCANCODE_9;        
        }

        return 0;
    }

    Key_Code Input_Task::translate_sdl_to_key_code (int sdl_scancode)
    {
        // Se podría hacer un array de traducción directa, pero con la sentencia
        // switch el compilador lo hará por nosotros de un modo transparente y
        // de sobra eficiente.

        switch (sdl_scancode)
        {
            case SDL_SCANCODE_RETURN:       return KEY_RETURN;
            case SDL_SCANCODE_ESCAPE:       return KEY_ESCAPE;
            case SDL_SCANCODE_BACKSPACE:    return KEY_BACKSPACE;
            case SDL_SCANCODE_TAB:          return KEY_TAB;
            case SDL_SCANCODE_SPACE:        return KEY_SPACE;

            case SDL_SCANCODE_A:            return KEY_A;
            case SDL_SCANCODE_B:            return KEY_B;
            case SDL_SCANCODE_C:            return KEY_C;
            case SDL_SCANCODE_D:            return KEY_D;
            case SDL_SCANCODE_E:            return KEY_E;
            case SDL_SCANCODE_F:            return KEY_F;
            case SDL_SCANCODE_G:            return KEY_G;
            case SDL_SCANCODE_H:            return KEY_H;
            case SDL_SCANCODE_I:            return KEY_I;
            case SDL_SCANCODE_J:            return KEY_J;
            case SDL_SCANCODE_K:            return KEY_K;
            case SDL_SCANCODE_L:            return KEY_L;
            case SDL_SCANCODE_M:            return KEY_M;
            case SDL_SCANCODE_N:            return KEY_N;
            case SDL_SCANCODE_O:            return KEY_O;
            case SDL_SCANCODE_P:            return KEY_P;
            case SDL_SCANCODE_Q:            return KEY_Q;
            case SDL_SCANCODE_R:            return KEY_R;
            case SDL_SCANCODE_S:            return KEY_S;
            case SDL_SCANCODE_T:            return KEY_T;
            case SDL_SCANCODE_U:            return KEY_U;
            case SDL_SCANCODE_V:            return KEY_V;
            case SDL_SCANCODE_W:            return KEY_W;
            case SDL_SCANCODE_X:            return KEY_X;
            case SDL_SCANCODE_Y:            return KEY_Y;
            case SDL_SCANCODE_Z:            return KEY_Z;
                               
            case SDL_SCANCODE_0:            return KEY_0;
            case SDL_SCANCODE_1:            return KEY_1;
            case SDL_SCANCODE_2:            return KEY_2;
            case SDL_SCANCODE_3:            return KEY_3;
            case SDL_SCANCODE_4:            return KEY_4;
            case SDL_SCANCODE_5:            return KEY_5;
            case SDL_SCANCODE_6:            return KEY_6;
            case SDL_SCANCODE_7:            return KEY_7;
            case SDL_SCANCODE_8:            return KEY_8;
            case SDL_SCANCODE_9:            return KEY_9;

            // ...
        }

        return KEY_UNKOWN;
    }


}