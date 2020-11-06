#pragma once

#include "vertex.h"
#include "edge.h"
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <ostream>
#include <limits>
#include "queue.h"
#include "search_return.h"
#include "queue_item.h"

constexpr float MAX = std::numeric_limits<float>::max();

class Graph
{
private:
	int vertexNumber;
	bool valued;
	bool oriented;
	std::vector<std::shared_ptr<Vertex>> vertexs;
	SearchReturn uniformCost(int initialVertex, int endVertex);
	SearchReturn greedy(int initialVertex, int endVertex);
	SearchReturn aStar(int initialVertex, int endVertex);
public:
	Graph(int vertexNumber, bool valued, bool oriented);
	Graph(int vertexNumber, bool valued, bool oriented, std::vector<float> heuristics);
	Graph(const Graph& graph);
	~Graph() = default;
	int getVertexNumber();
	bool getValued();
	bool getOriented();
	bool addEdge(int initialVertex, int endVertex, float weight = 1.0f);
	SearchReturn lessPath(int initialVertex, int endVertex, std::string searchType);
};
