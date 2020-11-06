#include "../include/edge.h"

Edge::Edge(std::shared_ptr<Vertex> initialVertex, std::shared_ptr<Vertex> endVertex, float weight)
	: initialVertex(initialVertex), endVertex(endVertex), weight(weight)
{
}

Edge::Edge(const Edge& edge)
	: initialVertex(edge.initialVertex), endVertex(edge.endVertex), weight(edge.weight)
{
}

Edge::~Edge() {}

std::shared_ptr<Vertex> Edge::getInitialVertex()
{
	return this->initialVertex;
}

std::shared_ptr<Vertex> Edge::getEndVertex()
{
	return this->endVertex;
}

float Edge::getPeso()
{
	return this->weight;
}

bool operator<(std::shared_ptr<Edge> edge1, std::shared_ptr<Edge> edge2)
{
	return edge1->weight < edge2->weight;
}
