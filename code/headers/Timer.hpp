/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once


#include <cstdint>

namespace engine
{

    /**
     * @brief Timer class
     *
     * @details Create timers for keeping track of time pased inside the engine
     */
    class Timer
    {

        uint32_t start_ticks;

    public:


        Timer()
        {
            start();
        }

        void start();

        float elapsed_seconds() const;

        uint32_t elapsed_milliseconds() const;

    };

}
