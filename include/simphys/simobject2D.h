#ifndef SIM_OBJECT_2D_H
#define SIM_OBJECT_2D_H

#include <memory>

#include "particle.h"
#include "sprite.h"
#include "simobject.h"

namespace simphys {

  using std::shared_ptr;

  // forward declarations
  class Sprite;
  class Particle;

  class SimObject2D : public SimObject {
  private:
    // coordinates in world. Assume z = 0.
    shared_ptr<Particle> state;
    
    // visual representation.
    shared_ptr<Sprite> sprite;

  public:

    SimObject2D(Particle p, Sprite s);

    /*
      Return a shared pointer to the physics state of this object.
    */
    shared_ptr<Particle> getState() const;
    
    /*
      Set the sprite for this object.
    */
    void setSprite(shared_ptr<Sprite> spr_ptr);

    /*
      Return a shared pointer to this sprite.
    */
    shared_ptr<Sprite> getSprite() const;

  };

}

#endif // SIM_OBJECT_2D_H
