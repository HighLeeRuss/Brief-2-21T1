#include "Rabbit.h"
#include "app.h"

Rabbit::Rabbit()
{
	m_sprite = kage::TextureManager::getSprite("data/zazaka.png");
	kage::centreOrigin(m_sprite);
	m_tags.add("Rabbit");

	// Make a Box2D body
	m_body = kage::Physics::BodyBuilder()
				.pos(0, 0)
				.userData(this)	// This lets the body know which GameObject owns it
				.build();

	// Make a fixture (collision shape) for the body
	kage::Physics::CircleBuilder()
		.radius(0.4f)
		.mass(1)
		.build(m_body); // We need to tell the builder which body to attach to
}

Rabbit::~Rabbit()
{

}

void Rabbit::update(float deltaT)
{
	// Do logic here
}

void Rabbit::onCollision(GameObject *obj)
{
	//if (obj->m_tags.has("enemy"))
	//{
		//m_dead = true;		// kills itself
		//obj->m_dead = true;	// kills the other object
	//}
}

void Rabbit::onCollision(b2Fixture *fix)
{
	//if ((int)(fix->GetUserData()) == 1234) // Fake ID value 1234
	//{
	//}
}

#pragma region Optional
//void Rabbit::onCollisionStop(GameObject* obj)
//{
//}

//void Rabbit::onCollisionStop(b2Fixture* fix)
//{
//}

//void Rabbit::render(sf::RenderTarget& rt)
//{
//	// Do custom rendering here. Not normally needed.
//}
#pragma endregion
