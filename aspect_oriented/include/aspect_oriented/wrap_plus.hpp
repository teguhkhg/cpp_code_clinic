#include <iostream>
#include <functional>

#include "to_function.hpp"

template <typename ...Args>
std::function<void(Args...)> wrapLog(std::function<void(Args...)> f){
    return [f](Args... args){
        std::cout << "start" << std::endl;
        f(args...);
        std::cout << "finish" << std::endl;
    };
}