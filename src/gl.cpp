#include <cmath>
#include "include/gl.hpp"

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
