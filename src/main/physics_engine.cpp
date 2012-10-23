#include "simphys/physics_engine.h"
#include "simphys/sim_world.h"

#include <memory>
#include <chrono>
#include <iostream>
#include <vector>

namespace simphys {

  using std::shared_ptr;
  typedef std::chrono::duration<float, std::ratio<1,1> > fseconds;

  void PhysicsEngine::tick(fseconds dt) {

    if (dt - lastTick > fseconds{0.0}) {
      lastTick = dt;
      auto objects = sw->getObjects();
      for (auto& obj : objects) {
		auto p = obj->getState();
	
		// really cheap way of testing for collisions with ground.
		if (p->getPosition().getY() - p->getRadius() > 0.0f) {
	  		p->integrate(dt);
		} 
      }
      
      // check for collisions
      
      // for each collision, resolve
     
      // check for more colisions, (loop)
      
    } 
  }

  void PhysicsEngine::setSimWorld(shared_ptr<SimWorld> simworld) {
    sw = simworld;
  }

  shared_ptr<SimWorld> PhysicsEngine::getSimWorld() const {
    return sw;
  }
  
  void PhysicsEngine::detectCollisions( std::vector<Collision>& collisionList )
  {
  	auto obs = sw->getObjects();
  	std::vector<shared_ptr<Particle>> p1;	//first vector of particles
  	std::vector<shared_ptr<Particle>> p2;	//copy of that vector of particles
  	
  	for( auto ob : obs )
  	{
  		//ob->getState(); will get each particle
  		p1.push_back( ob->getState() );
  	}
  	p2 = p1;
  	
  	for( auto i : p1 )
  	{
  		for( auto j : p2 )
  		{
  			// don't compare to itself
  			if( i->getPosition().getX() != j->getPosition().getX()
  				&& i->getPosition().getY() != j->getPosition().getY() )
  			{
  				float distanceSQ = ( j->getPosition().getX() - i->getPosition().getX() );
  				distanceSQ = distanceSQ * distanceSQ;
  				distanceSQ += (j->getPosition().getY() - i->getPosition().getY())*(j->getPosition().getY() - i->getPosition().getY());
  				
  				float radii = i->getRadius() + j->getRadius();
  				radii = radii * radii;
  				
  				if( distanceSQ <= radii ) // collision
  				{
  				
  				}
  			}
  		}
  	}
  }

}
