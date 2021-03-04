#include <knight_min_step/knight_min_step.hpp>

namespace constant{
    inline constexpr int N = 8;
}

int main(int argc, char **argv){
    utils::pos2d knightPos = std::make_pair(0, 0);
    utils::pos2d targetPos = std::make_pair(7, 7);

    KnightMinStep<constant::N> knightMinStep;
    int res = knightMinStep.solveMinStep(knightPos, targetPos);
    if(res < 0){
        std::cout << "No solution found" << std::endl;
    }
    else{
        std::cout << "Step needed to reach target : " << res << std::endl;
    }

    return 0;
}