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
    class Kernel;

    /**
     * @brief Task class
     *
     * @details Base class for new Task for the kernel
     */
    class Task
    {

    protected:

        /**
         * @brief Pointer to the kernel
         *
         */
        Kernel *kernel;

        /**
         * @brief Priority in the kernel loop
         *
         */
        int priority;

    public:

        Task(int priority) : priority(priority)
        {
            kernel = nullptr;
        }

        virtual ~Task()
        {
        }

        /**
         * @brief Set the kernel object
         *
         * @param new_kernel
         */
        void set_kernel(Kernel *new_kernel);

    public:

        virtual bool initialize() = 0;
        virtual bool finalize()   = 0;
        virtual bool do_step(float time) = 0;

    public:

        bool operator < (const Task &other) const
        {
            return this->priority < other.priority;
        }

    };
}

