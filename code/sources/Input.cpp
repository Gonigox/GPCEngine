#include <Input.hpp>
#include <SDL.h>

namespace engine
{
    Input::Input()
    {
        keystate = SDL_GetKeyboardState(NULL);
    }    
    
    bool Input::GetKey(Key_Code key)
    {
        return true;//keystate[translate_sdl_key_code(key)];
    }

    int Input::translate_sdl_key_code(Key_Code key)
    {
        switch (key)
        {
            case Key_Code::KEY_RETURN:         return SDL_SCANCODE_RETURN;   
            case Key_Code::KEY_ESCAPE:         return SDL_SCANCODE_ESCAPE;   
            case Key_Code::KEY_BACKSPACE:      return SDL_SCANCODE_BACKSPACE;
            case Key_Code::KEY_TAB:            return SDL_SCANCODE_TAB;      
            case Key_Code::KEY_SPACE:          return SDL_SCANCODE_SPACE; 

            case Key_Code::KEY_A:              return SDL_SCANCODE_A;        
            case Key_Code::KEY_B:              return SDL_SCANCODE_B;        
            case Key_Code::KEY_C:              return SDL_SCANCODE_C;        
            case Key_Code::KEY_D:              return SDL_SCANCODE_D;        
            case Key_Code::KEY_E:              return SDL_SCANCODE_E;        
            case Key_Code::KEY_F:              return SDL_SCANCODE_F;        
            case Key_Code::KEY_G:              return SDL_SCANCODE_G;        
            case Key_Code::KEY_H:              return SDL_SCANCODE_H;        
            case Key_Code::KEY_I:              return SDL_SCANCODE_I;        
            case Key_Code::KEY_J:              return SDL_SCANCODE_J;        
            case Key_Code::KEY_K:              return SDL_SCANCODE_K;        
            case Key_Code::KEY_L:              return SDL_SCANCODE_L;        
            case Key_Code::KEY_M:              return SDL_SCANCODE_M;        
            case Key_Code::KEY_N:              return SDL_SCANCODE_N;        
            case Key_Code::KEY_O:              return SDL_SCANCODE_O;        
            case Key_Code::KEY_P:              return SDL_SCANCODE_P;        
            case Key_Code::KEY_Q:              return SDL_SCANCODE_Q;        
            case Key_Code::KEY_R:              return SDL_SCANCODE_R;        
            case Key_Code::KEY_S:              return SDL_SCANCODE_S;        
            case Key_Code::KEY_T:              return SDL_SCANCODE_T;        
            case Key_Code::KEY_U:              return SDL_SCANCODE_U;        
            case Key_Code::KEY_V:              return SDL_SCANCODE_V;        
            case Key_Code::KEY_W:              return SDL_SCANCODE_W;        
            case Key_Code::KEY_X:              return SDL_SCANCODE_X;        
            case Key_Code::KEY_Y:              return SDL_SCANCODE_Y;        
            case Key_Code::KEY_Z:              return SDL_SCANCODE_Z;

            case Key_Code::KEY_0:              return SDL_SCANCODE_0;        
            case Key_Code::KEY_1:              return SDL_SCANCODE_1;        
            case Key_Code::KEY_2:              return SDL_SCANCODE_2;        
            case Key_Code::KEY_3:              return SDL_SCANCODE_3;        
            case Key_Code::KEY_4:              return SDL_SCANCODE_4;        
            case Key_Code::KEY_5:              return SDL_SCANCODE_5;        
            case Key_Code::KEY_6:              return SDL_SCANCODE_6;        
            case Key_Code::KEY_7:              return SDL_SCANCODE_7;        
            case Key_Code::KEY_8:              return SDL_SCANCODE_8;        
            case Key_Code::KEY_9:              return SDL_SCANCODE_9;        
        }

        return 0;
    }
}
