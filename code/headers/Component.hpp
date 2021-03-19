/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once
#include <string>

namespace engine
{
    class Entity;

    /**
     * @brief Base class for new component types
     *
     */
    class Component
    {
    protected:

        Entity *parent;

    public:

        /**
         * @brief Construct a new Component object
         *
         * @param parent
         */
        Component(Entity *parent) : parent(parent)
        {
            this->parent = parent;
        }

        virtual ~Component()
        {
        }

        virtual bool initialize() = 0;
    };
}