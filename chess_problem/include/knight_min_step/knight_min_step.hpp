#include <iostream>
#include <array>
#include <queue>

namespace utils{
    using pos2d = std::pair<int, int>;

    struct cell{
        int x, y, dis;
        cell(){}
        cell(int x, int y, int dis) : x(x), y(y), dis(dis){}
    };
}



template <size_t N>
class KnightMinStep{
private:
    using cell = utils::cell;
    using pos2d = utils::pos2d;

    std::queue<cell> q{};

    std::array<std::array<bool, N>, N> board{};
    std::array<pos2d, 8> moves{
        std::make_pair(-2, -1),
        std::make_pair(-1, -2),
        std::make_pair(1, -2),
        std::make_pair(2, -1),
        std::make_pair(-2, 1),
        std::make_pair(-1, 2),
        std::make_pair(1, 2),
        std::make_pair(2, 1),
    };

public:
    KnightMinStep(){}

    int solveMinStep(const pos2d &knightPos, const pos2d &targetPos);
    bool isSafe(const pos2d &pos);
};

template <size_t N>
int KnightMinStep<N>::solveMinStep(const pos2d &knightPos, const pos2d &targetPos){
    if(!isSafe(knightPos) && !isSafe(targetPos)){
        std::cout << "Both knight position and target position must be within board" << std::endl;
        return -1;
    }

    q.push(cell(knightPos.first, knightPos.second, 0));

    cell curr;
    int x, y;
    while(!q.empty()){
        curr = q.front();
        q.pop();

        if(curr.x == targetPos.first && curr.y == targetPos.second){
            return curr.dis;
        }
        
        for(const auto &move: moves){
            x = curr.x + move.first;
            y = curr.y + move.second;

            if(isSafe(std::make_pair(x, y)) && !board[x][y]){
                board[x][y] = true;
                q.push(cell(x, y, curr.dis + 1));
            }
        }
    }

    return -1;
}

template <size_t N>
bool KnightMinStep<N>::isSafe(const pos2d &pos){
    return (
        pos.first >= 0 &&
        pos.first < N &&
        pos.second >= 0 &&
        pos.second < N
    );
}