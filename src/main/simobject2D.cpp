#include <chrono>
#include <memory>
#include <string>

#include "simphys/particle.h"
#include "simphys/simobject2D.h"
#include "simphys/sprite.h"

namespace simphys {

  using std::shared_ptr;
  
  SimObject2D::SimObject2D(Particle p, Sprite s)
    : SimObject{std::to_string((std::chrono::high_resolution_clock::now()).time_since_epoch().count())}
    , state{std::make_shared<Particle>(p)} 
    , sprite{std::make_shared<Sprite>(s)} {
      
      sprite->setOwner(std::shared_ptr<SimObject2D>{this});

    }

  shared_ptr<Particle> SimObject2D::getState() const {
    return state;
  }

  void SimObject2D::setSprite(shared_ptr<Sprite> sprite_ptr) {
    sprite = sprite_ptr;
    sprite->setOwner(shared_ptr<SimObject2D>{this});
  }

  shared_ptr<Sprite> SimObject2D::getSprite() const {
    return sprite;
  }

}


