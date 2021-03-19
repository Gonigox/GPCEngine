/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once

#include <string>
#include <cassert>
#include <internal/declarations.hpp>

namespace engine
{

    /**
     * @brief Window class
     *
     * @details Class in charge of creating windows with SDL2
     */
    class Window
    {
    private:

        SDL_Window   *window;
        SDL_GLContext gl_context;

    public:

        /**
         * @brief Construct a new Window object
         *
         * @param title
         * @param width
         * @param height
         * @param fullscreen
         */
        Window(const std::string& title, int width, int height, bool fullscreen = false);


        ~Window();


        void set_fullscreen();

        void set_windowed();

        void set_position(int new_left_x, int new_top_y);

        void set_size(int new_width, int new_height);

        void get_window_dimensions(int* width, int* height);

        void clear();

        void swap_buffers();

    };
}
