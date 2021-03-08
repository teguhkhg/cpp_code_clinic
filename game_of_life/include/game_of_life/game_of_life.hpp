#include <iostream>
#include <array>

template <int M, int N>
class GameofLife{
private:
    using array2b = std::array<std::array<bool, N>, M>;
    array2b grid{};

public:
    GameofLife() {
        grid[1][3] = true;
        grid[1][4] = true;
        grid[2][4] = true;
        grid[5][3] = true;
        grid[5][4] = true;
        grid[6][2] = true;
        grid[6][3] = true;
        grid[7][5] = true;
        grid[8][4] = true;

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

    std::cout << "Next Generation : " << std::endl;
    GameofLife<M, N>::printBoard(new_grid);
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