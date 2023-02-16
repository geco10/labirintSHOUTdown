#include "ControlHero.h"
#include"ActionInfo.h"
#include<map>
static std::map< sf::Keyboard::Key, ActionInfo> keyMap= {
    {
      sf::Keyboard::Up,{0,HeroAction::MOVE_UP}
    },
    {
      sf::Keyboard::Left,{0,HeroAction::MOVE_LEFT}
    },
    {
      sf::Keyboard::Down,{0,HeroAction::MOVE_DOWN}
    },
    {
      sf::Keyboard::Right,{0,HeroAction::MOVE_RIGHT}
    },
    {
      sf::Keyboard::Numpad5,{0,HeroAction::SHOOT}
    },


    {
      sf::Keyboard::W,{1,HeroAction::MOVE_UP}
    },
    {
      sf::Keyboard::A,{1,HeroAction::MOVE_LEFT}
    },
    {
      sf::Keyboard::S,{1,HeroAction::MOVE_DOWN}
    },
    {
      sf::Keyboard::D,{1,HeroAction::MOVE_RIGHT}
    },
     {
      sf::Keyboard::V,{1,HeroAction::SHOOT}
    },
};
Hero* ControlHero::createHero(const char* path){
    heros.push_back(new Hero(map,path));
    heros[heros.size()-1]->setColor(color[heros.size() - 1]);
    return heros[heros.size() - 1];
}
void ControlHero::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < heros.size(); i++)
    {
        target.draw(*heros[i]);
    }
}
ControlHero::~ControlHero(){
    for (int i = 0; i < heros.size(); i++)
    {
        delete heros[i];
    }
}
void ControlHero::initColor(){
    color[0] = sf::Color::Green;
    color[1] = sf::Color::Blue;
    color[2] = sf::Color::Red;
}
ControlHero::ControlHero(Map* map) {
    this->map = map;
    initColor();
}

void ControlHero::tick(float delta)
{
    for (int i = 0; i < heros.size(); i++){
        heros[i]->tick(delta);
    }
}

void ControlHero::keyPressed(sf::Keyboard::Key key){
    if (keyMap.contains(key)) {
        ActionInfo event = keyMap[key];
        heros[event.id]->addAction(event.event);
    }
}
