/*
    Started by Gonzalo Pintos Cuesta on June of 2019
    Author: Gonzalo Pintos Cuesta
    Copyright © 2020 Gonzalo Pintos Cuesta
    Last Update: June/2020
    email: gonigox@gmail.com
*/

#pragma once
#include <Entity.hpp>
#include <Kernel.hpp>
#include <string>
#include <memory>
#include <map>
#include <Window.hpp>
#include <Render_Task.hpp>

namespace engine
{
    /**
     * @brief Class Scene
     *
     * @details The class who tracks all the entities wich are being used and rendering
     */
    class Scene
    {
        typedef std::map< std::string, std::shared_ptr< Entity > > Entity_Map;

        /**
         * @brief Map with all the entities in this scene
         *
         */
        Entity_Map  entity_Map;
        /**
         * @brief Kernel of the engine
         *
         */
        Kernel      kernel;
        /**
         * @brief Root entity who is the base parent of the rest of entities
         *
         */
        Entity      root;
        /**
         * @brief Window where all is rendering
         *
         */
        Window      window;

    public:

        Scene(const std::string& title, int width, int height, bool fullscreen);

    public:

        /**
         * @brief Init game loop
         *
         */
        void start_game();

        /**
         * @brief Add new entity to the scene
         * @details Add a new entity with his parent being the root entity an his transform_component being default
         *
         * @param name Entity name
         * @param new_Entity Pointer of the new Entity
         */
        void add_Entity(const std::string&, Entity*);

        /**
         * @brief Add new entity with transform_component custom
         *
         * @param name Name of the new entity
         * @param new_Entity Pointer of the new entity
         * @param pos Transform_component values for position
         * @param rot Transform_component values for rotation
         * @param scale Transform_component values for scale
         */
        void add_Entity(const std::string&, Entity*, Vector3* pos, Vector3* rot, Vector3* scale);

        /**
         * @brief Get the entity Map object
         *
         * @return Entity_Map*
         */
        Entity_Map* get_entity_Map()
        {
            return &entity_Map;
        }
    };
}