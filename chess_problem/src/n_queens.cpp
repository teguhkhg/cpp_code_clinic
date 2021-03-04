#include <n_queens/n_queens.hpp>

namespace constant{
    inline constexpr int N = 8;
}

int main(int argc, char **argv){

    NQueens<constant::N> nq(true);
    nq.compute();

    return 0;
}