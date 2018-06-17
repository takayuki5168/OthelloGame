#include "include/gl.hpp"

int main(int argc, char **argv) {
  gl::init();
  
  glutInit(&argc, argv);
    
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutCreateWindow("OthelloGame");
    
  glutDisplayFunc(gl::display);
  glutKeyboardFunc(gl::keyboard);
  glutKeyboardUpFunc(gl::keyboardUp);
  glutSpecialFunc(gl::keyboardSpecial);
  glutSpecialFunc(gl::keyboardSpecialUp);

  glutMainLoop();

  return 0;
}
