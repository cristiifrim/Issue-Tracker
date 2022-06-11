#include "Issue.h"
#include <vector>
#include <sstream>

Issue::Issue(const std::string& description, const std::string& status, const std::string& reporter, const std::string& solver)
	: description{ description }, status{ status }, reporter{ reporter }, solver{ solver }
{
}

std::istream& operator>>(std::istream& in, Issue& issue)
{
    std::string line, token;
    std::vector<std::string> result;
    std::getline(in, line);

    std::stringstream ss{ line };
    while (std::getline(ss, token, ',')) {
        result.push_back(token);
    }
    if (result.size() != 4)
        return in;

    issue.description = result[0];
    issue.status = result[1];
    issue.reporter = result[2];
    issue.solver = result[3];
    return in;
}

std::ostream& operator<<(std::ostream& in, Issue issue)
{
    in << issue.description << ',' << issue.status << ',' << issue.reporter << ',' << issue.solver;
    return in;
}
