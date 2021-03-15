#include <plus/wrap_plus.hpp>

int main(int argc, char** argv){
    auto plus = [](int a, int b){
        std::cout << a + b << std::endl;
    };

    std::cout << "No wrap : " << std::endl;
    plus(3, 1);

    std::cout << "Wrap with static_cast : " << std::endl;
    auto castPlus = wrapLog(static_cast<std::function<void(int, int)>>(plus));
    castPlus(3, 1);

    std::cout << "Wrap with to_function : " << std::endl;
    auto loggedPlus = wrapLog(to_function(plus));
    loggedPlus(3, 1);

    return 0;
}