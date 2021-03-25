/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: March/2021
    email: gonigox@gmail.com
*/

#pragma once
#include <Component.hpp>
#include <Input.hpp>
#include <Entity.hpp>

namespace engine
{
    class Script_Component : public Component
    {
    public:

        //virtual void Awake();
        virtual void Start(){};
        virtual void Update(){};

    private:        

        virtual bool initialize() override{ return true; };

    };
}
