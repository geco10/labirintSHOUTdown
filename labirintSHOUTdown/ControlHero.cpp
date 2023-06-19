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
      sf::Keyboard::Numpad9,{0,HeroAction::RELOAD}
    },
    {
      sf::Keyboard::Numpad4,{0,HeroAction::TURN_LEFT}
    },
    {
      sf::Keyboard::Numpad6,{0,HeroAction::TURN_RIGHT}
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
      sf::Keyboard::F,{1,HeroAction::SHOOT}
    },
     {
      sf::Keyboard::Y,{1,HeroAction::RELOAD}
    },
    {
      sf::Keyboard::G,{1,HeroAction::TURN_LEFT}
    },
    {
      sf::Keyboard::H,{1,HeroAction::TURN_RIGHT}
    },
};
Hero* ControlHero::createHero(const char* path){
    heros.push_back(new Hero(path));
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
ControlHero::ControlHero() {
    initColor();
}

void ControlHero::tick(float delta)
{
    
}

void ControlHero::keyPressed(sf::Keyboard::Key key, bool isPressed){
    if (keyMap.contains(key)) {
        ActionInfo event = keyMap[key];
        heros[event.id]->addAction(event.event,isPressed);
    }
}
