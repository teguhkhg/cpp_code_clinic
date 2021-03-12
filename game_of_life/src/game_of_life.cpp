#include <game_of_life/game_of_life.hpp>

int main(){
    constant::array2b grid{};
    grid[1][3] = true;
    grid[1][4] = true;
    grid[2][4] = true;
    grid[5][3] = true;
    grid[5][4] = true;
    grid[6][2] = true;
    grid[6][3] = true;
    grid[7][5] = true;
    grid[8][4] = true;

    GameofLife<constant::M, constant::N> gol{grid};

    for(int i{0}; i < 10; i ++ ){
        std::cout << std::endl << std::endl;
        gol.nextGen();
    }

    return 0; 
}