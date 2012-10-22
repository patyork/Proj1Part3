/*
  Main program.
*/

#include <iostream>
#include <memory>

#include "simphys/sim_world.h"
#include "simphys/sim_engine.h"
#include "simphys/simobject.h"
#include "simphys/simobject2D.h"
#include "simphys/particle.h"
#include "simphys/vec3.h"

int main(int argc, char **argv) {

  // create a simulator
  simphys::SimEngine sim;

  auto clock_ptr = std::make_shared< simphys::Clock<fseconds> >(fseconds{0.0f});
  clock_ptr->setScale(0.01f);
  sim.setClock(clock_ptr);

  // create a world to simulate
  auto world_ptr = std::make_shared<simphys::SimWorld>(); 
  sim.setSimWorld(world_ptr);

  // create and initialize an object
  simphys::Particle p;
  simphys::Sprite s;
  simphys::SimObject2D testObject(p,s);
  auto obj_ptr = std::make_shared<simphys::SimObject2D>(testObject);
  auto objState = testObject.getState();
  objState->setPosition(simphys::vec3{10, 20, 0});
  objState->setVelocity(simphys::vec3{40.0, 60.0, 0});
  objState->setAcceleration(simphys::vec3{0, -9.8, 0});
  
  // create and initialize another object
  simphys::Particle p2;
  simphys::Sprite s2;
  simphys::SimObject2D testObject2(p2,s2);
  auto obj_ptr2 = std::make_shared<simphys::SimObject2D>(testObject2);
  auto objState2 = testObject2.getState();
  objState2->setPosition(simphys::vec3{500, 20, 0});
  objState2->setVelocity(simphys::vec3{-40.0, 60.0, 0});
  objState2->setAcceleration(simphys::vec3{0, -9.8, 0});

  // add objects to the world.
  world_ptr->add(obj_ptr);
  world_ptr->add(obj_ptr2);

  // initialize the simulator and run it.
  sim.init();
  sim.run();

}