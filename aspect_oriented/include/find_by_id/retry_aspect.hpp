#include "aspect_common.hpp"
#include "type/maybe.hpp"

template <typename R, typename ...Args>
std::function<Maybe<R>(Args...)> triesTwice(std::function<Maybe<R>(Args...)> f){
    return[f](Args... args){
        Maybe<R> result = f(std::forward<Args>(args)...);
        if(result.hasError())
            return f(std::forward<Args>(args)...);
        return result;
    };
}