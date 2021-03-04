#include <array>
#include <queue>
#include <iostream>
#include <iomanip>

namespace piece_move{
    inline constexpr std::array<std::pair<int, int>, 8> knight = {
        std::make_pair(2, 1),
        std::make_pair(1, 2),
        std::make_pair(-1, 2),
        std::make_pair(-2, 1),
        std::make_pair(-2, -1),
        std::make_pair(-1, -2),
        std::make_pair(1, -2),
        std::make_pair(2, -1),
    };
}

template <int N>
class KnightsTour{
private:
    std::array<std::array<int, N>, N> board{};

public:
    KnightsTour() {
        for(auto &row: board)
            for(auto &col: row)
                col = -1;
    }

    void solveKT();
    bool solveKTUtil(int x, int y, int k);
    bool isSafe(int x, int y);
    void printBoard() const;
};

template <int N>
void KnightsTour<N>::solveKT(){
    board[0][0] = 0;
    if(solveKTUtil(0, 0, 1))
        printBoard();
    else
        std::cout << "Solution does not exist" << std::endl;
}

template <int N>
bool KnightsTour<N>::solveKTUtil(int x, int y, int k){
    if(k == N * N)
        return true;

    int next_x, next_y;
    for(const auto &move : piece_move::knight){
        if(!board[0][0])
            printBoard();

        next_x = x + move.first;
        next_y = y + move.second;

        if(isSafe(next_x, next_y)){
            board[next_x][next_y] = k;
            if(solveKTUtil(next_x, next_y, k + 1))
                return true;
            else
                board[next_y][next_y] = -1;

        }
    }

    return false;
}

template <int N>
bool KnightsTour<N>::isSafe(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

template <int N>
void KnightsTour<N>::printBoard() const {
    for(const auto &row: board){
        for(const auto &col : row){
            std::cout << " " << std::setw(2) << col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}