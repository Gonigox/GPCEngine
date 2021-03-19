#include "Transform_Component.hpp"


engine::Transform_Component::Transform_Component(Entity *parent) : Component(parent)
{
    position.x = 0;
    position.y = 0;
    position.z = 0;

    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;

    scale.x = 1;
    scale.y = 1;
    scale.z = 1;
}

void engine::Transform_Component::set_transform(float x, float y, float z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void engine::Transform_Component::set_transform(Vector3* vec)
{
    position.x = vec->x;
    position.y = vec->y;
    position.z = vec->z;
}

void engine::Transform_Component::set_rotation(float x, float y, float z)
{
    rotation.x = x;
    rotation.y = y;
    rotation.z = z;
}

void engine::Transform_Component::set_rotation(Vector3* vec)
{
    rotation.x = vec->x;
    rotation.y = vec->y;
    rotation.z = vec->z;
}

void engine::Transform_Component::set_scale(float x, float y, float z)
{
    scale.x = x;
    scale.y = y;
    scale.z = z;
}

void engine::Transform_Component::set_scale(Vector3* vec)
{
    scale.x = vec->x;
    scale.y = vec->y;
    scale.z = vec->z;
}

bool engine::Transform_Component::initialize()
{
    return false;
}
