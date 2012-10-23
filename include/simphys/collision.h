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
			vec3	closingVelocity;
			
		public:
			//getters
			std::pair <std::shared_ptr<Particle>,std::shared_ptr<Particle>> getParticles() const;
			vec3 getNormal() const;
			float getCoR() const;
			vec3 getClosingVelocity() const;
			
			//setters
			void setParticles( std::pair <std::shared_ptr<Particle>,std::shared_ptr<Particle>> particles );
			void setNormal( vec3 norm );
			void setCoR( float cor );
			void setClosingVelocity( vec3 vs );
			
			void resolve();
	
	}; // end Collision



} // end namespace simphys


#endif
