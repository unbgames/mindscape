//TODO discover how overwrite static attribute

#ifndef FOX_H
#define FOX_H

#include "../engine/include/game_object.hpp"
#include "../engine/include/image.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace engine {

  class Fox : public GameObject {
    public:
      Fox(std::string p_name, std::pair<int, int> position, int p):GameObject(p_name, position, p,
      {
          {71,"MOVE_LEFT"},
          {72,"MOVE_RIGHT"},
          {73,"JUMP"},
          {74,"CROUCH"},
      }){};

      ~Fox(){};

      bool load();
      void free();
      void update();
      void on_event(GameEvent game_event);

  };

}

#endif
