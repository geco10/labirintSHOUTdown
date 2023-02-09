#include "ControlHero.h"

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