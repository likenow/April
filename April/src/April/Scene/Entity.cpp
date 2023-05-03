#include "alpch.h"
#include "Entity.h"

namespace April {

    Entity::Entity(entt::entity handle, Scene* scene)
        : m_EntityHandle(handle), m_Scene(scene)
    {
    }

}