#include <functional>

template <typename Function>
struct function_traits 
: public function_traits<decltype(&Function::operator())>
{};

template <typename ClassType, typename ReturnType, typename ...Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>
{
    typedef ReturnType (*pointer)(Args...);
    typedef std::function<ReturnType(Args...)> function;
};

template <typename Function>
typename function_traits<Function>::function
to_function(Function &lambda){
    return typename function_traits<Function>::function(lambda);
}