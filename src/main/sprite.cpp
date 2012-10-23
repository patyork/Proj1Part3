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
    Color newColor = p->getColor();
    
    // set texture stuff.
    
    // draw
    glColor3f(newColor.r,newColor.g,newColor.b);
    glTranslatef( x+p->getRadius(),y+p->getRadius(),0.0f );
    gluDisk(gluNewQuadric(), 0, p->getRadius(), 32, 32); //pointer, radius, slices, loops
    
  }
}
