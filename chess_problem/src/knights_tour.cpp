#include <knights_tour/knights_tour.hpp>

namespace constant{
    inline constexpr int N = 8;
}

int main(int argc, char **argv){
    KnightsTour<constant::N> knights_tour;
    knights_tour.solveKT();

    return 0;
}