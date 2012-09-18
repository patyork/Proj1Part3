#ifndef SPRITE_H
#define SPRITE_H

#include <memory>

namespace simphys {

  class SimObject2D;
  using std::shared_ptr;

  class Sprite {
  private:
    shared_ptr<SimObject2D> owner;

    // texture data.

  public:
    /*
      Set the owner of this sprite.
    */
    void setOwner(shared_ptr<SimObject2D> newOwner);

    /*
      Code responsible for drawing the sprite to the screen.
    */
    void draw() const;
  };

}


#endif // SPRITE_H
