#include <utils/to_function.hpp>
#include <vector>

#include <find_by_id/type/user.hpp>
#include <find_by_id/log_aspect.hpp>
#include <find_by_id/retry_aspect.hpp>

int main(int argc, char **argv){
    std::vector<User> users{make_user(1, "john"), make_user(2, "Bob"), make_user(3, "Max")};

    auto findUser = [&users](int id) -> Maybe<User>{
        for(User user: users){
            if(user->id == id)
                return user;
        }
        return nullptr;
    };

    auto findUserLogged = logged("findUser", to_function(findUser));
    auto findUserRetry = triesTwice(findUserLogged);
    auto user = findUserRetry(1);
    std::cout << (user.hasError() ? user.getError()->message: user()->name) << std::endl;

    return 0;
}