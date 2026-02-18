#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
    private:
        std::string name;
    public:
    Zombie();
    void setName(std::string name);
    void announce() const;
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif