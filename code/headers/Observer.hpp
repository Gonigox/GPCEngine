/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once
#include <Message.hpp>

namespace engine
{
    /**
     * @brief Observer class
     *
     * @details Recieve messages and execute an action when recieved
     */
    struct Observer
    {
        /**
         * @brief Define the action to do when recieved message
         *
         * @param message Message listening
         */
        virtual void handle_message(const Message& message) = 0;
    };
}