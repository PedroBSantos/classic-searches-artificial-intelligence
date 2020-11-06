#include "../include/search_return.h"

SearchReturn::SearchReturn(int vertexNumber) :
	vertexNumber(vertexNumber), paths(new std::string[vertexNumber]), costs(new float[vertexNumber]) {}

SearchReturn::SearchReturn(const SearchReturn& searchReturn) :
	paths(searchReturn.paths), costs(searchReturn.costs), vertexNumber(searchReturn.vertexNumber), solution(searchReturn.solution) {}

SearchReturn::~SearchReturn() {}

std::string* SearchReturn::getPaths()
{
	return this->paths;
}

void SearchReturn::setPaths(std::string* paths)
{
	delete[] this->paths;
	this->paths = paths;
}

float* SearchReturn::getCosts()
{
	return this->costs;
}

void SearchReturn::setCosts(float* costs)
{
	delete[] this->costs;
	this->costs = costs;
}

std::vector<std::string>& SearchReturn::getSolution()
{
	return this->solution;
}
