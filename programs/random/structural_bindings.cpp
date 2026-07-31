#include <iostream>
#include <string>

struct Player{
    std::string name;
    int score;
    double health;
};

Player return_multiple(){
    Player player{}; // create the instance on stack (cuz its just a small struct)
    player.name = "Amogh";
    player.score = 89;
    player.health = 66.6667;
    return player;
}

int main(){
    auto [name,score,health] = return_multiple();
    std::cout<<"Name: "<<name<<"\nScore: "<<score<<"\nHealth: "<<health<<std::endl;
}