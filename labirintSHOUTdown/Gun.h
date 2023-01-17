#pragma once
class Gun{
  int type;
  int range;
  int mC;
  int damage;
  virtual void reload() = 0;
  virtual void shoot() = 0;
};

