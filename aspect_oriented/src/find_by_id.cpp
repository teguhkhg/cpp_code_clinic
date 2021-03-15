#include <utils/to_function.hpp>
#include <vector>
#include <map>

#include <find_by_id/type/user.hpp>
#include <find_by_id/aspects.hpp>

int main(int argc, char **argv){
    std::vector<User> users{make_user(1, "john"), make_user(2, "Bob"), make_user(3, "Max")};
    std::map<std::tuple<int>, User> userCache;
    std::mutex m_user;

    class Session{
    public:
        bool isValid(){return true;}
    } session;

    auto findUser = [&users](int id) -> Maybe<User>{
        for(User user: users){
            if(user->id == id)
                return user;
        }
        return nullptr;
    };

    auto findUserLogged = logged("findUser", to_function(findUser));
    auto findUserRetry = triesTwice(findUserLogged);
    auto findUserCached = cached(userCache, findUserRetry);
    auto findUserSecured = secured(session, findUserCached);
    auto findUserNotEmpty = notEmpty(findUserSecured);
    auto findUserFinal = locked(m_user, findUserNotEmpty);
    auto user = findUserFinal(1);
    std::cout << (user.hasError() ? user.getError()->message: user()->name) << std::endl;

    return 0;
}