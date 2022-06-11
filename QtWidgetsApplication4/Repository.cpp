#include "Repository.h"
#include <fstream>

void Repository::loadData()
{
	std::ifstream f("issues.txt");
	while (!f.eof()) {
		Issue s;
		f >> s;
		this->data.push_back(s);
	}
}

void Repository::saveData()
{
	std::ofstream f("issues.txt");
	for (int i = 0; i < this->data.size() - 1; ++i)
		f << this->data[i] << "\n";
	f << this->data[this->data.size() - 1];
}

void Repository::add(Issue s)
{
	this->data.push_back(s);
}

void Repository::remove(int index)
{
	this->data.erase(this->data.begin() + index);
}

int Repository::search(const std::string& desc)
{
	for (int i = 0; i < this->data.size(); ++i)
		if (this->data[i].getDescription() == desc)
			return i;
	return -1;
}
