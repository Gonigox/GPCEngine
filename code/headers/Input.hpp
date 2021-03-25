/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once

namespace engine
{
    enum Key_Code
    {
        KEY_UNKOWN,
        
        KEY_RETURN,
        KEY_ESCAPE,
        KEY_BACKSPACE,
        KEY_TAB,
        KEY_SPACE,
        
        KEY_A, KEY_B, KEY_C, KEY_D, KEY_E,
        KEY_F, KEY_G, KEY_H, KEY_I, KEY_J,
        KEY_K, KEY_L, KEY_M, KEY_N, KEY_O,
        KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T,
        KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y,
        KEY_Z,
        
        KEY_0,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,
        

        KEY_NUM = 45 //Based in SDL_NUM_SCANCODES
        //...
    };


    class Input
    {
    public:

        static bool GetKey    (Key_Code key);

        static bool GetKeyDown(Key_Code key);

        static bool GetKeyUp  (Key_Code key);

    protected:

        Input() = delete;

        //friend class Kernel;
    };
    
}