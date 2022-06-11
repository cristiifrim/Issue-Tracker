#pragma once
#include "Repository.h"
#include <string>
#include "Subject.h"

class Service : public Subject
{
	Repository& repo;

public:
	Service(Repository& repo) : repo{ repo } {}
	void add(const std::string& issuer, const std::string& description);
	void remove(const std::string& desc);
	void solve(const std::string& desc, const std::string& solver);
	std::vector<Issue> get();
};

