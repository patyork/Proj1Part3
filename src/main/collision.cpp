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
#include <cmath>

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
          
          bool penDone = false;
          int penCount = 0;
          
          while( !penDone && penCount < 5 )
          {
          	//Resolve Interpenetration
          	vec3 pos1 = (ps.first)->getPosition(), pos2 = (ps.second)->getPosition();
          	float r1 = (ps.first)->getRadius(), r2 = (ps.second)->getRadius();
          	float d = sqrtf( (pos2.getX() - pos1.getX())*(pos2.getX() - pos1.getX()) + (pos2.getY() - pos1.getY())*(pos2.getY() - pos1.getY()) );
          	float penetration = r1 + r2 - d;
          	
          	if( penetration < 0.01f )
          	{
          		penDone = true;
          		break;
          	}
          	
          	std::cout << "Interpenetration: " << penetration << std::endl;
          
          	vec3 resDir{ pos2.getX() - pos1.getX(), pos2.getY() - pos1.getY(), pos2.getZ() - pos1.getZ() }; // direction to resolve B
          
          	vec3 newPos = pos2 + resDir.normalized() * penetration;
          	std::cout << "Old Position: " << pos2.toString() << std::endl
          		<< "New Position: " << newPos.toString() << std::endl;
          		
          	b->setPosition( newPos );  // resolve the interpenetration
          	penCount++;	//counter to make sure we don't resolve too many times
          }
          
          
          
          
          
          std::cout<< "Contact Normal: " << normal.toString() << std::endl;
          
          
          float dvel = (-e * closingVelocity) - closingVelocity;
          std::cout<< "Closing Velocity: " << closingVelocity << std::endl;
          std::cout<< "Vs': " << (-e * closingVelocity) << std::endl;
          std::cout<< "dVel: " << dvel << std::endl;
          
          float M = (1 / a->getMass()) + (1 / b->getMass());
          std::cout << "Inverse Mass 1: " << (1/a->getMass()) << std::endl
               << "Inverse Mass 2: " << (1/b->getMass()) << std::endl
               << "M: " << M << std::endl;
               
          float impulse = dvel / M;
          vec3 IV = impulse * normal;
          vec3 newa = IV * (1/a->getMass()) + a->getVelocity();
          vec3 newb = b->getVelocity() - IV * (1/b->getMass());
           std::cout << "Impulse: " << impulse << std::endl
          		<< "IV: " << IV.toString() << std::endl
          		<< "Current Velocity (a): " << (a->getVelocity()).toString() << std::endl
          		<< "Current velocity (b): " << (b->getVelocity()).toString() << std::endl
          		<< "New Velocity (a): " << newa.toString() <<std::endl
          		<< "New Velocity (b): " << newb.toString() << std::endl;
          
          //set new velocities directly
          a->setVelocity( newa );
          b->setVelocity( newb );
	}
     
     Collision::Collision( std::shared_ptr<Particle> p1, std::shared_ptr<Particle> p2, vec3 norm, float cor, float vs )
     {
          ps = std::make_pair (p1,p2);
          normal = norm;
          e = cor;
          closingVelocity = vs;
     }

}
