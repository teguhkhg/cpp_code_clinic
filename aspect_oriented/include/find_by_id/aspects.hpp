#include <string>
#include <functional>
#include <iostream>
#include <chrono>
#include <tuple>
#include <mutex>

#include "type/maybe.hpp"

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

template <typename R, typename ...Args>
std::function<Maybe<R>(Args...)> triesTwice(std::function<Maybe<R>(Args...)> f){
    return[f](Args... args){
        Maybe<R> result = f(std::forward<Args>(args)...);
        if(result.hasError())
            return f(std::forward<Args>(args)...);
        return result;
    };
}

template <typename R, typename C, typename ...Args>
std::function<Maybe<R>(Args...)> cached(C &cache, std::function<Maybe<R>(Args...)> f)
{
    return [f,&cache](Args... args){
        auto key = std::make_tuple(args...);
        
        if (cache.count(key) > 0)
            return just(cache[key]);
        else
        {
            Maybe<R> result = f(std::forward<Args>(args)...);
            if (!result.hasError())
                cache.insert(std::pair<decltype(key), R>(key, result()));
            return result;
        }
    };
}

template <typename R, typename ...Args, typename S>
std::function<Maybe<R>(Args...)> secured(S session, std::function<Maybe<R>(Args...)> f){
    return [f, &session](Args... args) -> Maybe<R>{
        if(session.isValid())
            return f(std::forward<Args>(args)...);
        else
            return Error(403, "Forbidden");
    };
}

template <typename R, typename ...Args>
std::function<Maybe<R>(Args...)> notEmpty(std::function<Maybe<R>(Args...)> f){
    return[f](Args... args) -> Maybe<R>{
        Maybe<R> result = f(std::forward<Args>(args)...);
        if(!result.hasError() && result.isEmpty())
            return Error(404, "Not Found");
        return result;
    };
}

template <typename R, typename ...Args>
std::function<Maybe<R>(Args...)> locked(std::mutex &m, std::function<Maybe<R>(Args...)> f){
    return [f, &m](Args... args){
        std::unique_lock<std::mutex> lock(m);
        return f(std::forward<Args>(args)...);
    };
}