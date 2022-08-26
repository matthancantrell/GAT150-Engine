#include "CollisionComponent.h"
#include "Engine.h"

namespace Engine
{
    void CollisionComponent::Initialize()
    {
        auto component = owner_->GetComponent<RBPhysicsComponent>();
        if (component)
        {
            physics_g.SetCollisionBox(component->body_, data, owner_);
        }
    }

    void CollisionComponent::Update()
    {
    }

    bool CollisionComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool CollisionComponent::Read(const rapidjson::Value& value)
    {
        READ_DATA(value, data.size);
        READ_DATA(value, data.density);
        READ_DATA(value, data.friction);
        READ_DATA(value, data.restitution);
        READ_DATA(value, data.is_trigger);

        return true;
    }

    void CollisionComponent::OnCollisionEnter(Actor* other)
    {
        if (enterFunction_) enterFunction_(other);
    }

    void CollisionComponent::OnCollisionExit(Actor* other)
    {
        if(enterFunction_) exitFunction_(other);
    }
}