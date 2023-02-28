#pragma once
#include<SFML/Graphics.hpp>
class Gun :public sf::Drawable {
  int type;
  int range;
  int mC;
  int damage;
 public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
  virtual void reload() = 0;
  virtual void shoot() = 0;
};

