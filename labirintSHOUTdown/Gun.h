#pragma once
#include<SFML/Graphics.hpp>
class Gun :public sf::Drawable {
protected:
  int type;
  int range;
  int mC;
  int damage;
  sf::Vector2f *pos;
  const float* len;
 public:
  Gun(sf::Vector2f *pos,const float *len);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
  virtual void reload() = 0;
  virtual void shoot() = 0;
};

