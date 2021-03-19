/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once
#include <string>
#include <map>
#include <Variant.hpp>

namespace engine
{
    /**
     * @brief Message class
     *
     */
    class Message
    {
        std::map< std::string, Variant > params;

    public:

        std::string id;

        Message(std::string id) : id(id){}

        /**
         * @brief Add new parameter to the message
         *
         * @param id
         * @param value
         */
        void add_parameter(const std::string& id, const Variant& value)
        {
            params.insert(std::pair<string, Variant>(id, value));
        }

    };
}