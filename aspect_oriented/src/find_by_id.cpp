#include <find_by_id/user.hpp>
#include <find_by_id/maybe.hpp>

#include <vector>
#include <iostream>

int main(int argc, char **argv){
    std::vector<User> users{make_user(1, "john"), make_user(2, "Bob"), make_user(3, "Max")};

    auto findUser = [&users](int id) -> Maybe<User>{
        for(User user: users){
            if(user->id == id){
                std::cout << user ->name << std::endl;
                return user;
            }
        }
        return nullptr;
    };

    findUser(1);

    return 0;
}