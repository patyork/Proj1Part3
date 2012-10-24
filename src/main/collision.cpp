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
	
	float Collision::getClosingVelocity() const
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
	
	void Collision::setClosingVelocity( float vs )
	{
	
	}
	
	void Collision::resolve()
	{
          std::shared_ptr<Particle> a = ps.first;
          std::shared_ptr<Particle> b = ps.second;
          
          
          /*//Resolve Interpenetration
          vec3 pos1 = (ps.first)->getPosition(), pos2 = (ps.second)->getPosition();
          float r1 = (ps.first)->getRadius(), r2 = (ps.second)->getRadius();
          while(  )*/
          
          vec3 acurr = a->getPosition();
          a->setPosition( vec3{acurr.getX() - 2.0f, acurr.getY(), acurr.getZ()} );
          
          
          
          
          float dvel = (-e * closingVelocity) - closingVelocity;
          float M = 1 / a->getMass() + 1 / b->getMass();
          float impulse = dvel / M;
          vec3 IV = impulse * normal;
          vec3 newa = IV * (1/a->getMass()) + a->getVelocity();
          vec3 newb = b->getVelocity() - IV * (1/b->getMass());
          
          a->setVelocity( newa + a->getVelocity() );
          b->setVelocity( newb + b->getVelocity() );
          
          std::cout  << std::endl;
	}
     
     Collision::Collision( std::shared_ptr<Particle> p1, std::shared_ptr<Particle> p2, vec3 norm, float cor, float vs )
     {
          ps = std::make_pair (p1,p2);
          normal = norm;
          e = cor;
          closingVelocity = vs;
     }

}