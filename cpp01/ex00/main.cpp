#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("yoji");
    heapZombie->announce();
    delete heapZombie;

    randomChump("sikoma");
    return 0;
}