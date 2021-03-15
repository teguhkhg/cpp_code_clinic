#include "aspect_common.hpp"
#include <chrono>

template <typename R, typename ...Args>
std::function<R(Args...)> logged(std::string name, std::function<R(Args...)> f){
    return [f, name](Args... args){
        std::cout << name << " start" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();

        R result = f(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now();
        auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Elapsed: " << total << " us" << std::endl;

        return result;
    };
}