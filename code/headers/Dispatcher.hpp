/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once
#include <map>
#include <string>
#include <list>
#include <Observer.hpp>
#include <Message.hpp>

namespace engine
{
    /**
     * @brief Class in charge of manage messages and observers
     *
     */
    class Dispatcher
    {
        std::map< std::string, std::list< Observer* > > observers;

    public:

        /**
         * @brief Create new observer for a message
         *
         * @param message_id
         * @param observer
         */
        void register_listener(const std::string& message_id, Observer& observer)
        {
            observers[message_id].push_back(&observer);
        }

        /**
         * @brief Delete observer for a message
         *
         * @param message_id
         * @param observer
         */
        void unregister_listener(const std::string& message_id, Observer& observer)
        {
            observers[message_id].remove(&observer);
        }

        /**
         * @brief Deliver a message to the observers
         *
         * @param message
         */
        void multicast(const Message& message);

    };
}