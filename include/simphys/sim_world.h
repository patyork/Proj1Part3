#ifndef SIM_WORLD_H
#define SIM_WORLD_H

#include "simphys/simobject2D.h"

#include <memory>
#include <vector>

namespace simphys {

  using std::shared_ptr;
  using simphys::SimObject2D;

  /*
    A container for simulation objects.
    \author Richard Kelley.
  */
  class SimWorld {
  private:
    std::vector<shared_ptr<SimObject2D> > objects;

  public:
    SimWorld();

    /*
      Add an object to the world.
    */
    void add(shared_ptr<SimObject2D> obj);
    
    /*
      Get the objects in the world.
    */
    std::vector<shared_ptr<SimObject2D> > getObjects() const;

  };

}

#endif // SIM_WORLD_H
