/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once
#include <Component.hpp>
#include <Vector3.hpp>

namespace engine
{
    /**
     * @brief Transfrom Component class
     *
     * @details Component in charge of the position from an Entity in the scene
     */
    class Transform_Component : public Component
    {
    public:

        Vector3 position;
        Vector3 rotation;
        Vector3 scale;

    public:

        Transform_Component(Entity *parent);

        /**
         * @brief Set the transform object
         *
         * @param pos Vector3* position
         * @param scale Vector3* scale
         * @param rot Vector3* rotation
         */
        void set_transform(float x, float y, float z);
        /**
         * @brief Set the transform object
         *
         * @param position Vector3*
         */
        void set_transform(Vector3*);

        /**
         * @brief Set the rotation object
         *
         * @param x
         * @param y
         * @param z
         */
        void set_rotation(float x, float y, float z);
        /**
         * @brief Set the rotation object
         *
         * @param rotation Vector3*
         */
        void set_rotation(Vector3*);

        /**
         * @brief Set the scale object
         *
         * @param x
         * @param y
         * @param z
         */
        void set_scale(float x, float y, float z);
        /**
         * @brief Set the scale object
         *
         * @param Vector3*
         */
        void set_scale(Vector3*);


    private:

        virtual bool initialize() override;
    };
}