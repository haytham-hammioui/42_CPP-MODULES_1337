#include "Zombie.hpp"

int main(){
    int N = -1;
    Zombie* horde = zombieHorde(N, "OMERTA");
    for(int i = 0; i < N; i++){
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}