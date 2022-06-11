#pragma once
#include "Issue.h"
#include <vector>

class Repository
{
	std::vector<Issue> data;
	void loadData();
	void saveData();
public:
	Repository() { this->loadData(); }
	void add(Issue s);
	void remove(int index);
	int search(const std::string& desc);
	int size() { return this->data.size(); }
	std::vector<Issue> get() { return this->data; }
	Issue& operator[](int index) { if (index < 0 || index >= this->data.size()) throw std::exception("Invalid index!"); return this->data[index]; }
	~Repository() { this->saveData(); }
};

