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
    /**
     * @brief Vector3 class
     *
     * @details Class to use in the Transform_componet to keep track of the transform variables
     */
    struct Vector3
    {
        float x, y, z;

    public:

        Vector3()
        {
            x = 0;
            y = 0;
            z = 0;
        }

        Vector3(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
    };
}