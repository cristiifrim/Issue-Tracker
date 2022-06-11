#pragma once
#include <string>

class Issue
{
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;

public:
	Issue() {}
	Issue(const std::string& description, const std::string& status, const std::string& reporter, const std::string& solver);
	std::string getStatus() const { return this->status; }
	std::string getDescription() const { return this->description; }
	std::string getReporter() const { return this->reporter; }
	std::string getSolver() const { return this->solver; }
	void solve(const std::string& solver) { this->status = "closed"; this->solver = solver; }
	friend std::istream& operator>>(std::istream& in, Issue& issue);
	friend std::ostream& operator<<(std::ostream& in, Issue issue);
};

