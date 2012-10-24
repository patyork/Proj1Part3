#ifndef COLLISION_H
#define COLLISION_H

#include "vec3.h"
#include "simphys/particle.h"
#include <utility>
#include <iostream>
#include <memory>

namespace simphys {

	class Collision
	{
		private:
			// A pair of particles that have collided
			std::pair <std::shared_ptr<Particle>,std::shared_ptr<Particle>> ps;
			
			// The contact normal
			vec3 normal;
			
			// The Coefficient of Restitution
			float e;
			
			// The closing velocity of the two particles
			float closingVelocity;
               
			
		public:
			//getters
			std::pair <std::shared_ptr<Particle>,std::shared_ptr<Particle>> getParticles() const;
			vec3 getNormal() const;
			float getCoR() const;
			float getClosingVelocity() const;
			
			//setters
			void setParticles( std::pair <std::shared_ptr<Particle>,std::shared_ptr<Particle>> particles );
			void setNormal( vec3 norm );
			void setCoR( float cor );
			void setClosingVelocity( float vs );
			
			void resolve();
               Collision( std::shared_ptr<Particle> p1, std::shared_ptr<Particle> p2, vec3 norm, float cor, float vs );
	
	}; // end Collision



} // end namespace simphys


#endif
