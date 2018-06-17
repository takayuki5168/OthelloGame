#pragma once

#include <iostream>
#include <vector>
#include <functional>

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
