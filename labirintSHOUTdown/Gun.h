#pragma once
#include"Bullet.h"
#include"TimeMonitor.h"
#include<SFML/Graphics.hpp>
class Gun :public sf::Drawable,public Tickable {
protected:
  int type;
  int range;
  const float *dir;
  int mC;
  TimeMonitor shootMon;
  TimeMonitor reloadMon;
  float speed;
  int bc;
  float bul_radius;
  int damage;
  bool vis;
  const sf::Vector2f *pos;//top left 
  const float* len;
 public:
  Gun(const sf::Vector2f *pos,const float *len,const float *dir);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
  virtual void reload() = 0;
  virtual void tick(float delta)override;
  virtual void shoot() = 0;
};

