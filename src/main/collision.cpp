/*
	Implementation of the Collision class
	
*/

/* the collision object has these members:

	1. 2 particles that were involved in the colission [?? two pointers to particles that are a part of the world?]
	2. the contact normal [vec3]
	3. the coefficient of restitution [float between 0 and 1 inclusive]
	4. their closing velocities (Vs) [vec3]
*/

// Vs = (Va dot Vb) dot (direction a-b)
//	where Va = velocity of object a
//		 Vb = velocity of object b



#include "simphys/collision.h"
#include <utility>
#include "simphys/vec3.h"
#include <iostream>
#include <memory>

namespace simphys
{
	std::pair <std::shared_ptr<Particle>, std::shared_ptr<Particle>> Collision::getParticles() const
	{
		return ps;
	}
	
	vec3 Collision::getNormal() const
	{
		return normal;
	}
	
	float Collision::getCoR() const
	{
		return e;
	}
	
	vec3 Collision::getClosingVelocity() const
	{
		return closingVelocity;
	}
	
	
	void Collision::setParticles( std::pair <std::shared_ptr<Particle>, std::shared_ptr<Particle>> particles )
	{
		
	}
	
	void Collision::setNormal( vec3 norm )
	{
	
	}
	
	void Collision::setCoR( float cor )
	{
	
	}
	
	void Collision::setClosingVelocity( vec3 vs )
	{
	
	}
	
	void resolve()
	{
	
	}

}
