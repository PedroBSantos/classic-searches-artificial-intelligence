#include "../include/vertex.h"
#include "../include/edge.h"

Vertex::Vertex(int number) : number(number), heuristic(0.0f)
{
}

Vertex::Vertex(int number, float heuristic) : heuristic(heuristic), number(number)
{
}

Vertex::Vertex(const Vertex& vertex) : number(vertex.number), heuristic(vertex.heuristic), edges(vertex.edges)
{
}

Vertex::~Vertex() {}

int Vertex::getNumber()
{
	return this->number;
}

float Vertex::getHeuristic()
{
	return this->heuristic;
}

void Vertex::setHeuristic(float heuristic)
{
	this->heuristic = heuristic;
}

std::vector<std::shared_ptr<Edge>>& Vertex::getEdges()
{
	return this->edges;
}
