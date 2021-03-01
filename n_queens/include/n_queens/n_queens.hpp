#include <array>
#include <iostream>
#include <algorithm>

template <int N>
class NQueens{
private:
    std::array<int, N> _board{};
    bool _printAll{false};
    int _count{0};

public:
    NQueens(bool printAll) : _printAll(printAll){}

    void compute();
    void solveNQ(int row);
    bool isSafe(int row, int col);
    void printBoard();
};

template<int N>
void NQueens<N>::compute(){
    solveNQ(0);
    
    if(!_printAll)
        printBoard();

    std::cout << _count << " solutions found" << std::endl;
}

template <int N>
void NQueens<N>::solveNQ(int row){
    if(row >= N){
        _count++;
        if(_printAll)
            printBoard();

        return;
    }

    for(size_t i{0}; i < N; i++){
        if(isSafe(row, i)){
            _board[row] = i;
            solveNQ(row + 1);
        }
    }
}

template <int N>
bool NQueens<N>::isSafe(int row, int col){
    for(size_t i{0}; i < row; i++){
        if(_board[i] == col) 
            return false;
        if(_board[i] == col - (row - i)) 
            return false;
        if(_board[row - 1 - i] == col + i + 1) 
            return false;
    }

    return true;
}

template <int N>
void NQueens<N>::printBoard(){
    std::cout << std::endl;
    for(const auto &row: _board){
        std::cout << row;
    }
    std::cout << std::endl;

    for(const auto &row: _board){
        for(size_t col{0}; col < N; ++col){
            if(row == col) 
                std::cout << 1 << " ";
            else 
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}