#include "User.h"
#include <sstream>
#include <vector>

std::istream& operator>>(std::istream& in, User& user)
{
    std::string line, token;
    std::vector<std::string> result;
    std::getline(in, line);

    std::stringstream ss{ line };
    while (std::getline(ss, token, ',')) {
        result.push_back(token);
    }
    if (result.size() != 2)
        return in;
    if (result[0].empty() || result[1].empty())
        return in;

    user.name = result[0];
    user.type = result[1];
    return in;
}
