#include "common.hpp"

class UserData{
public:
    const int id;
    const std::string name;
    UserData(int id, std::string name) : id(id), name(name){}
};

using User = std::shared_ptr<UserData>;

User make_user(int id, std::string name){
    User user = std::make_shared<UserData>(id, name);
    return user;
}
