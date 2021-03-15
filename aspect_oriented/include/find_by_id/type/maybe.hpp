#include "error.hpp"

template <typename T>
class Maybe{
private:
    const T data;
    const std::shared_ptr<Error> error;

public:
    Maybe() : data(nullptr), error(nullptr){}
    Maybe(T data) : data(std::forward<T>(data)), error(nullptr){}
    Maybe(decltype(nullptr) nothing) : data(nullptr), error(nullptr){}
    Maybe(Error&& error) : data(nullptr), error(std::make_shared<Error>(error)){}

    bool isEmpty(){return (data == nullptr);}
    bool hasError(){return (error != nullptr);}
    T operator()(){return data;}
    std::shared_ptr<Error> getError(){return error;}
};

template <typename T>
Maybe<T> just(T t){
    return Maybe<T>(t);
}

