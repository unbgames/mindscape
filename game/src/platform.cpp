#include "platform.hpp"
#include "game.hpp"

using namespace mindscape;

Platform::Platform(
  std::string name,
  std::pair<int, int> position,
  int priority)
  :engine::GameObject(name, position, priority,
      {{engine::KeyboardEvent::LEFT,"MOVE_LEFT"},
      {engine::KeyboardEvent::RIGHT,"MOVE_RIGHT"}}
  ){};

void Platform::on_event(GameEvent game_event){
  std::string event_name = game_event.game_event_name;
  if(event_name == "MOVE_LEFT" && !engine::GameObject::on_limit_of_level){
    set_position_x(get_position_x() + 10);
  }else if(event_name == "MOVE_RIGHT" && !engine::GameObject::on_limit_of_level){
    set_position_x(get_position_x() - 10);
  }
  // First Level Limiter
  if(name == "clown_tree"){
    if(get_position_x() > 13350){
      engine::GameObject::on_limit_of_level = true;
      set_position_x(13350);
    }else if(get_position_x() < -1300){
      engine::GameObject::on_limit_of_level = true;
      set_position_x(-1300);
    }else{
      engine::GameObject::on_limit_of_level = false;
    }
  }
  // Second Level Limiter
  if(name == "limiter"){
    if(get_position_x() > 3000){
      engine::GameObject::on_limit_of_level = true;
      set_position_x(3000);
    }else if(get_position_x() < 0){
      engine::GameObject::on_limit_of_level = true;
      set_position_x(0);
    }else{
      engine::GameObject::on_limit_of_level = false;
    }
  }

}
