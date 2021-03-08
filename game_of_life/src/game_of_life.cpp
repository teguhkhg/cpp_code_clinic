#include <game_of_life/game_of_life.hpp>

namespace constant{
    inline constexpr int M = 10;
    inline constexpr int N = 10;
}

int main(){
    std::cout << "test" << std::endl;
    GameofLife<constant::M, constant::N> gol;
    gol.nextGen();

    return 0; 
}