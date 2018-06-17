#include<GL/glut.h>
#include<iostream>
#include<functional>

class OthelloGame
{
public:
  explicit OthelloGame() {}
  void setPlayer(std::function<void()> player)
  {
    if (m_players.size() == 2) {
      std::cerr << "[Error] Players could not be more than 2." << std::endl;
      return;
    }
    m_players.at(m_players.size()) = player;
  }
  
private:
  std::array<std::function<void()>, 2> m_players;
};


namespace gl
{
  void display()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glutSwapBuffers();
  }
  
  void keyboard(unsigned char key, int, int)
  {
  }

  void keyboardUp(unsigned char key, int, int)
  {
  }

  void keyboardSpecial(int key, int, int)
  {
  }
  
  void keyboardSpecialUp(int key, int, int)
  {
  }
}

int main(int argc, char **argv) {
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
