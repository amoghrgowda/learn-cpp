#include <iostream>

class Entity{
public:
    virtual void PrintName(){
    std::cout<<"I'm an entity"<<std::endl;
    }

    virtual ~Entity(){
        std::cout<<"Cleaning up Entity virtually"<<std::endl;
    }
};

class Player : public Entity{
public:
    void PrintName() override{
        std::cout<<"I'm a player"<<std::endl;
    }
};

int main(){

    Entity* e = new Entity();
    e->PrintName();

    Player* p = new Player();
    p->PrintName();

    Entity* ptr_p = p;
    ptr_p->PrintName(); // Without Virtual function prints "I'm an entity", even though p is a Player type.

    delete e;
    delete p;

    return 0;
}