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
      std::vector<Collision> collisionList;
      detectCollisions( collisionList );
      
      // for each collision, resolve
      for( auto i : collisionList)
      {
           i.resolve();
      }
     
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
  	auto obs = sw->getObjects();			//obs is a vector of simobject2D's
  	std::vector<shared_ptr<Particle>> p1;	//first vector of particles
  	std::vector<shared_ptr<Particle>> p2;	//copy of that vector of particles
  	
  	for( auto ob : obs )
  	{
  		p1.push_back( ob->getState() );
  	}
  	p2 = p1;
  	
  
  	
  	for( unsigned int x=0; x<p1.size(); x++ )
  	{
  		for( unsigned int y=x+1; y<p2.size(); y++ )
  		{
               auto i = p1[x];
               auto j = p2[y];
               
               // don't compare to itself
  			if( i != j )
  			{
  				float distanceSQ = ( j->getPosition().getX() - i->getPosition().getX() );
  				distanceSQ = distanceSQ * distanceSQ;
  				distanceSQ += (j->getPosition().getY() - i->getPosition().getY())*(j->getPosition().getY() - i->getPosition().getY());
  				
  				float radii = i->getRadius() + j->getRadius();
  				radii = radii * radii;
  				
  				if( distanceSQ <= radii ) // collision
  				{
                         float v1 = i->getVelocity().getX(), v2 = j->getVelocity().getX(), vs;
                         if( v1 < 0 ) v1=-v1;
                         if( v2 < 0 ) v2=-v2;
                         vs = (v1+v2);
                         
                         //Determine contact normal
                         vec3 posA = i->getPosition();
                         //posA.normalize();
                         vec3 posB = j->getPosition();
                         //posB.normalize();
                         vec3 contactNorm = posA - posB;
                         contactNorm.normalize();
                         if( contactNorm.getX() < 0 ) contactNorm.setX( -contactNorm.getX() );
                         
                         //add collision
                         collisionList.push_back( Collision{i, j, contactNorm, 1.0f, vs } );
  				}
  			}
  		}
  	}
  }

}
