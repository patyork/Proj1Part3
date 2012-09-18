#include "simphys/simobject2D.h"
#include "simphys/sprite.h"
#include "simphys/particle.h"

#include <GL/glew.h>
#include <GL/gl.h>

namespace simphys {

  void Sprite::setOwner(shared_ptr<SimObject2D> newOwner) {
    owner = newOwner;
  }
  
  void Sprite::draw() const {
    
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    
    shared_ptr<Particle> p = owner->getState();
    auto pos = p->getPosition();
    float x = pos.getX();
    float y = pos.getY();
    
    // set texture stuff.
    
    // draw
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0f);
    glVertex2f(x, y);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(x + 64, y);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(x + 64, y + 64);
    glTexCoord2f(0.0, 1.0);
    glVertex2f(x, y + 64);
    glEnd(); 
  }
}
