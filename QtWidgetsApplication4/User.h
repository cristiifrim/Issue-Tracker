#pragma once
#include <string>
#include <iostream>

class User
{
	std::string name;
	std::string type;

public:
	User() {}
	User(const std::string& name, const std::string& type) : name{ name }, type{ type } {}
	std::string getName() const { return this->name; }
	std::string getType() const { return this->type; }
	friend std::istream& operator>>(std::istream& in, User& user);
};

