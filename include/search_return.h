#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <limits>

class SearchReturn
{
private:
	std::string* paths;
	float* costs;
	std::vector<std::string> solution;
	int vertexNumber;

public:
	SearchReturn(int vertexNumber);
	SearchReturn(const SearchReturn& searchReturn);
	~SearchReturn();
	std::string* getPaths();
	void setPaths(std::string* paths);
	float* getCosts();
	void setCosts(float* costs);
	std::vector<std::string>& getSolution();
	friend std::ostream& operator<<(std::ostream& os, const SearchReturn& searchReturn)
	{
		for (int i = 0; i < searchReturn.vertexNumber; i++)
		{
			os << "Vertex: ";
			os << i << "\tCusto do Caminho: ";
			if (searchReturn.costs[i] == std::numeric_limits<float>::max()) {
				os << "INF";
			}
			else {
				os << searchReturn.costs[i];
			}
			os << "\tCaminho: " << searchReturn.paths[i] << std::endl;
		}
		os << "Solucao: ";
		for (int i = signed(searchReturn.solution.size()) - 1; i >= 0; i--) {
			os << searchReturn.solution[i];
		}
		return os;
	}
};
