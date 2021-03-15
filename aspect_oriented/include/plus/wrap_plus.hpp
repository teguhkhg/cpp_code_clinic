#include <utils/to_function.hpp>
#include <iostream>

template <typename ...Args>
std::function<void(Args...)> wrapLog(std::function<void(Args...)> f){
    return [f](Args... args){
        std::cout << "start" << std::endl;
        f(args...);
        std::cout << "finish" << std::endl;
    };
}