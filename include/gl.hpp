#pragma once

#include <GL/glut.h>
#include "include/othello_game.hpp"

namespace gl
{
  extern OthelloGame othello_game;
  
  void init();
  void display();
  void keyboard(unsigned char key, int, int);
  void keyboardUp(unsigned char key, int, int);
  void keyboardSpecial(int key, int, int);
  void keyboardSpecialUp(int key, int, int);
}
