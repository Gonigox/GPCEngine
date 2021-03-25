/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once

#include <Transform_Component.hpp>
#include <string>
#include <memory>
#include <map>
#include <list>

namespace engine
{
    /**
     * @brief Class Entity
     *
     * @details Base class for objects in the engine
     *
     */
    class Entity
    {
        Transform_Component  transform;

        std::list< Entity* > childs;
        
        std::string          model_path;
        std::map< std::string, std::shared_ptr< Component > > components;

    public:

        Entity();

        /**
         * @brief Construct a new Entity object
         *
         * @param model Model_path of this entity
         */
        Entity(std::string model);

        bool initialize();

        /**
         * @brief Add new component to the entity
         *
         * @param type Name component
         * @param component Reference of the component
         * @return true
         * @return false
         */
        bool add_component
        (
            const std::string &type,
            std::shared_ptr< Component > &component
        );

        /**
         * @brief Get the transform component object
         *
         * @return Transform_Component*
         */
        Transform_Component* get_transform_component()
        {
            return &transform;
        }

        /**
         * @brief Get the model path object
         *
         * @return model_path of the entity
         */
        std::string get_model_path()
        {
            return model_path;
        }

        /**
         * @brief Delete component from the Entity
         *
         * @param type Component to delete name
         */
        void delete_component(const std::string &type);

        Component * get_Component(const std::string &type);

        /**
         * @brief Set the parent object
         *
         * @param parent New parent of the Entity
         */
        bool set_parent(Entity* parent);

        std::list<Entity*> & get_childs();
       
    };
}