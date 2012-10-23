#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <memory>
#include <chrono>
#include "collision.h"
#include "particle.h"
#include <vector>

namespace simphys {

  class SimWorld;
  using std::shared_ptr;
  
  typedef std::chrono::duration<float, std::ratio<1,1> > fseconds;

  class PhysicsEngine {
  private:
    shared_ptr<SimWorld> sw;

    fseconds lastTick;

  public:
    PhysicsEngine()
      : lastTick{fseconds{0.016}} { }

    /*
      Update state.
    */
    void tick(fseconds dt);

    void setSimWorld(shared_ptr<SimWorld> simworld);
    shared_ptr<SimWorld> getSimWorld() const;
    
    // Detects collisions in the world
    void detectCollisions( std::vector<Collision>& collisionList );
  };

}

#endif // PHYSICS_ENGINE_H
