#include "ContactListener.h"
#include "Framework/Actor.h"
#include "Components/CollisionComponent.h"
#include <iostream>

namespace Engine
{
	void ContactListener::BeginContact(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if (fixtureA->GetUserData().pointer && fixtureB->GetUserData().pointer)
		{
			Actor* actorA = (Actor*)(fixtureA->GetUserData().pointer);
			Actor* actorB = (Actor*)(fixtureB->GetUserData().pointer);
			
			if (!actorA->GetDestroy() && actorA->GetComponent<CollisionComponent>())
			{
				actorA->GetComponent<CollisionComponent>()->OnCollisionEnter(actorB);
			}
			if (!actorB->GetDestroy() && actorB->GetComponent<CollisionComponent>())
			{
				actorB->GetComponent<CollisionComponent>()->OnCollisionEnter(actorA);
			}
		}
	}
	void ContactListener::EndContact(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if (fixtureA->GetUserData().pointer && fixtureB->GetUserData().pointer)
		{
			Actor* actorA = (Actor*)(fixtureA->GetUserData().pointer);
			Actor* actorB = (Actor*)(fixtureB->GetUserData().pointer);

			if (actorA->GetComponent<CollisionComponent>())
			{
				actorA->GetComponent<CollisionComponent>()->OnCollisionExit(actorB);
			}
			if (actorB->GetComponent<CollisionComponent>())
			{
				actorB->GetComponent<CollisionComponent>()->OnCollisionExit(actorA);
			}
		}
	}
}

