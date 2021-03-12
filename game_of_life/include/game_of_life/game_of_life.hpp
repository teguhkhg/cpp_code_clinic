#include <iostream>
#include <array>
#include <memory>

namespace constant{
    inline constexpr int M = 10;
    inline constexpr int N = 10;

    using array2b = std::array<std::array<bool, N>, M>;
}

template <int M, int N>
class GameofLife{
private:
    using array2b = constant::array2b;
    array2b grid{};

public:
    GameofLife() {
        init();
    }

    GameofLife(array2b grid) : grid{grid} {
        init();
    }

    void init(){
        std::cout << "Current Generation : " << std::endl; 
        GameofLife<M, N>::printBoard(grid);
    }

    int checkNeighbours(int x, int y);
    void nextGen();
    static void printBoard(array2b board);
};

template <int M, int N>
int GameofLife<M, N>::checkNeighbours(int x, int y){
    int alive = 0;

    for(int i{-1}; i <= 1; i++)
        for(int j{-1}; j <=1; j++){
            if(!i && !j)
                continue;
            alive += grid[x + i][y + j];
        }

    return alive;
}

template <int M, int N>
void GameofLife<M, N>::nextGen(){
    array2b new_grid{};

    for(int x{1}; x < M - 1; x++)
        for(int y{1}; y < N - 1; y++){
            int alive = checkNeighbours(x, y);

            if(grid[x][y] && alive < 2) 
                new_grid[x][y] = false;
            else if(grid[x][y] && alive > 3)
                new_grid[x][y] = false;
            else if(!grid[x][y] && alive == 3)
                new_grid[x][y] = true;
            else
                new_grid[x][y] = grid[x][y];
        }

    grid = new_grid;
    std::cout << "Next Generation : " << std::endl;
    GameofLife<M, N>::printBoard(grid);
}

template <int M, int N>
void GameofLife<M, N>::printBoard(array2b board){
    for(const auto &row: board){
        for(const auto &col: row){
            if(col)
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}