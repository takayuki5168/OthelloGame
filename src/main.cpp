#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

class OthelloGame
{
public:
  struct Board{
    std::array<std::array<int, 8>, 8> stones;
    Board() {
      stones.at(3).at(3) = -1;
      stones.at(4).at(4) = -1;
      stones.at(3).at(4) = 1;
      stones.at(4).at(3) = 1;
    }
  };
  
  explicit OthelloGame() {}
  
  void setPlayer(std::function<std::pair<int, int>(Board)> player)
  {
    if (m_players.size() == 2) {
      std::cerr << "[Error] Players could not be more than 2." << std::endl;
      return;
    }
    m_players.push_back(player);
  }

  void update()
  {
  }

  std::array<std::array<int, 8>, 8> getBoardStones() { return m_board.stones; }
  
private:
  std::vector<std::function<std::pair<int, int>(Board)>> m_players;
  Board m_board;
};

namespace gl
{
  OthelloGame othello_game;
  void init()
  {
    othello_game = OthelloGame{};
    
    othello_game.setPlayer([](OthelloGame::Board board){ return std::pair<int, int>(1, 1); });
    othello_game.setPlayer([](OthelloGame::Board board){ return std::pair<int, int>(1, 1); });
  }
  
  void display()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw board
    {
      glTranslatef(0, 0, 0);
      
      glBegin(GL_QUADS);
      glColor3f(0.0, 1.0, 0.0);
      glVertex2d(-160. / 640 * 2, -160. / 480 * 2);
      glVertex2d(160. / 640 * 2, -160. / 480 * 2);    
      glVertex2d(160. / 640 * 2, 160. / 480 * 2);
      glVertex2d(-160. / 640 * 2, 160. / 480 * 2);
      glEnd();

      glBegin(GL_LINE_LOOP);
      glColor3f(0.0, 0.0, 0.0);
      glVertex2d(-160. / 640 * 2, -160. / 480 * 2);
      glVertex2d(160. / 640 * 2, -160. / 480 * 2);    
      glVertex2d(160. / 640 * 2, 160. / 480 * 2);
      glVertex2d(-160. / 640 * 2, 160. / 480 * 2);
      glEnd();

      for (int i = 0; i < 8 - 1; i++) {
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2d(-160. / 640 * 2, (-160. + 160 / 8 * (i + 1) * 2) / 480 * 2);
	glVertex2d(160. / 640 * 2, (-160. + 160 / 8 * (i + 1) * 2) / 480 * 2);
	glEnd();
      }
      for (int i = 0; i < 8 - 1; i++) {
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2d((-160. + 160 / 8 * (i + 1) * 2) / 640 * 2, -160. / 480 * 2);
	glVertex2d((-160. + 160 / 8 * (i + 1) * 2) / 640 * 2, 160. / 480 * 2);
	glEnd();
      }
    }

    auto board = othello_game.getBoardStones();
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
	if (board.at(i).at(j) == 0) {
	  continue;
	}

	std::cout << i << " " << j << " " << board.at(i).at(j) << std::endl;

	glBegin(GL_TRIANGLE_FAN);

	int color = static_cast<unsigned int>(board.at(i).at(j));
	glColor3d(color, color, color);
	for (int k = 0; k < 100; k++) {
	  GLfloat angle = k * 2.0f * 3.14 / 100;
	  GLfloat x0 = (-160. + 160. / 8 * (i + 0.5) * 2.) / 640 * 2;
	  GLfloat y0 = (-160. + 160. / 8 * (j + 0.5) * 2.) / 480 * 2;
	  glVertex2f(x0 + std::cos(angle) * 30 / 640, y0 + std::sin(angle) * 30 / 480);
	}
	glEnd();
      }
    }
    
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
