#pragma once

#include <vector>
#include <memory>

class Vertex
{
private:
	int number;
	float heuristic;
	std::vector<std::shared_ptr<class Edge>> edges;
public:
	Vertex(int number);
	Vertex(int number, float heuristic);
	Vertex(const Vertex& vertex);
	~Vertex();
	int getNumber();
	float getHeuristic();
	void setHeuristic(float heuristic);
	std::vector<std::shared_ptr<class Edge>>& getEdges();
	friend bool operator==(const Vertex& vertex1, const Vertex& vertex2) {
		return vertex1.number == vertex2.number;
	}
};
