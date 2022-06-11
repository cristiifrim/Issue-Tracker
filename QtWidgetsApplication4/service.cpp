#include "service.h"
#include <algorithm>

void Service::add(const std::string& issuer, const std::string& description)
{
	if (this->repo.search(description) != -1)
		throw std::exception("Issue already in repo!");

	Issue s{ description, "open", issuer, "None" };
	this->repo.add(s);
	this->notify();
}

void Service::remove(const std::string& desc)
{
	int index = this->repo.search(desc);
	if (index == -1)
		throw std::exception("Issue not found!");
	if (this->repo[index].getStatus() == "open")
		throw std::exception("Issue is not closed!");
	this->repo.remove(index);
	this->notify();
}

void Service::solve(const std::string& desc, const std::string& solver)
{
	int index = this->repo.search(desc);
	if (index == -1)
		throw std::exception("Issue not found!");
	if(this->repo[index].getStatus() == "closed")
		throw std::exception("Issue already clossed!");
	this->repo[index].solve(solver);
	this->notify();
}

std::vector<Issue> Service::get()
{
	std::vector<Issue> data = this->repo.get();
	std::sort(data.begin(), data.end(), [](Issue a, Issue b) {
		if (a.getStatus().compare(b.getStatus()) != 0)
			return a.getStatus().compare(b.getStatus()) >= 0;
		return (a.getDescription().compare(b.getDescription()) < 0);
		});
	return data;
}
