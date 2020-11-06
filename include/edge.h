#pragma once

#include "vertex.h"
#include <memory>

class Edge
{
private:
	std::shared_ptr<Vertex> initialVertex;
	std::shared_ptr<Vertex> endVertex;
	float weight;
public:
	Edge(std::shared_ptr<Vertex> initialVertex, std::shared_ptr<Vertex> endVertex, float weight = 1.0f);
	Edge(const Edge& edge);
	~Edge();
	std::shared_ptr<Vertex> getInitialVertex();
	std::shared_ptr<Vertex> getEndVertex();
	float getPeso();
	friend bool operator==(const Edge& aresta1, const Edge& aresta2) {
		return aresta1.initialVertex->getNumber() == aresta2.initialVertex->getNumber() &&
			aresta1.endVertex->getNumber() == aresta2.endVertex->getNumber();
	}
	friend bool operator<(std::shared_ptr<Edge> aresta1, std::shared_ptr<Edge> aresta2);
};
