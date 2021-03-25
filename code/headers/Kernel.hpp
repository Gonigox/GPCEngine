/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once

// & direccion / * referencia

#include <set>
#include <Task.hpp>
#include <Timer.hpp>
#include <Render_Task.hpp>
#include <Input_Task.hpp>
#include <Script_Task.hpp>

namespace engine
{
    /**
     * @brief Kernel class
     *
     * @details Class in charge of the main loop from the engine
     */
    class Kernel
    {
    private:

        typedef std::multiset< Task* > Task_List;

    public:

        Task_List   tasks;

        bool exit;
        bool paused;
        
    protected:
        /**
         * @brief Task in charge of rendering all entities in the scene
         *
         */
        Render_Task renderer;
        Input_Task  input_task;

        Script_Task script_task;

        

    public:

        Kernel(Window &win, Scene &scene);

        /**
         * @brief Add new task to the engine
         *
         * @param task Reference to the new task
         */
        void add_task(Task &task);

        /**
         * @brief Execute main loop
         *
         */
        void execute();


        void stop()
        {
            exit = true;
        }

        void pause()
        {
            paused = true;
        }

        void resume()
        {
            paused = false;
        }

    };
}
