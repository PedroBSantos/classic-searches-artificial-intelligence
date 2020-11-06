#include "../include/graph.h"

Graph::Graph(int vertexNumber, bool valued, bool oriented) : vertexNumber(vertexNumber), valued(valued), oriented(oriented)
{
	for (int i = 0; i < this->vertexNumber; i++) {
		std::shared_ptr<Vertex> vertex(new Vertex(i));
		this->vertexs.push_back(vertex);
	}
}

Graph::Graph(int vertexNumber, bool valued, bool oriented, std::vector<float> heuristics) : Graph(vertexNumber, valued, oriented)
{
	for (int i = 0; i < this->vertexNumber; i++) {
		this->vertexs[i]->setHeuristic(heuristics[i]);
	}
}

Graph::Graph(const Graph& graph) : vertexNumber(graph.vertexNumber), valued(graph.valued), oriented(graph.oriented), vertexs(graph.vertexs) {}

int Graph::getVertexNumber()
{
	return this->vertexNumber;
}

bool Graph::getValued()
{
	return this->valued;
}

bool Graph::getOriented()
{
	return this->oriented;
}

bool Graph::addEdge(int initialVertex, int endVertex, float weight)
{
	if (initialVertex < 0 || initialVertex >= this->vertexNumber || endVertex < 0 || endVertex >= this->vertexNumber) {
		return false;
	}
	std::shared_ptr<Edge> edge1(new Edge(this->vertexs[initialVertex], this->vertexs[endVertex], weight));
	this->vertexs[initialVertex]->getEdges().push_back(edge1);
	if (this->oriented) {
		return true;
	}
	std::shared_ptr<Edge> edge2(new Edge(this->vertexs[endVertex], this->vertexs[initialVertex], weight));
	this->vertexs[endVertex]->getEdges().push_back(edge2);
	return true;
}

SearchReturn Graph::lessPath(int initialVertex, int endVertex, std::string searchType)
{
	if (searchType == "Custo Uniforme") {
		return this->uniformCost(initialVertex, endVertex);
	}
	else if (searchType == "Gulosa") {
		return this->greedy(initialVertex, endVertex);
	}
	return this->aStar(initialVertex, endVertex);
}

SearchReturn Graph::uniformCost(int vertex1, int vertex2)
{
	SearchReturn searchReturn(this->vertexNumber);
	if (vertex1 < 0 || vertex1 >= this->vertexNumber || vertex2 < 0 || vertex2 >= this->vertexNumber) {
		return searchReturn;
	}
	float* dists = new float[this->vertexNumber];
	std::string* paths = new std::string[this->vertexNumber];
	bool* visited = new bool[this->vertexNumber];
	for (int i = 0; i < this->vertexNumber; i++) {
		dists[i] = MAX;
		paths[i] = "NE";
		visited[i] = false;
	}
	dists[vertex1] = 0.0f;
	paths[vertex1] = std::to_string(vertex1);
	Queue<QueueItem> queue(this->vertexNumber);
	queue.add(QueueItem(this->vertexs[vertex1], 0.0f));
	float cost;
	float newCost;
	std::shared_ptr<Vertex> vertex;
	while (!queue.empty()) {
		auto queueItem = queue.remove();
		vertex = queueItem.getVertex();
		if (vertex->getNumber() == vertex2) {
			break;
		}
		cost = queueItem.getCost();
		if (!visited[vertex->getNumber()]) {
			visited[vertex->getNumber()] = true;
			for (std::shared_ptr<Edge> edge : vertex->getEdges()) {
				newCost = cost + edge->getPeso();
				if (dists[edge->getEndVertex()->getNumber()] > newCost) {
					dists[edge->getEndVertex()->getNumber()] = newCost;
					paths[edge->getEndVertex()->getNumber()] = std::to_string(vertex->getNumber());
					queue.add(QueueItem(edge->getEndVertex(), newCost));
				}
			}
		}
	}
	searchReturn.setPaths(paths);
	searchReturn.setCosts(dists);
	int aux = vertex2;
	searchReturn.getSolution().push_back(std::to_string(aux).append(" "));
	do
	{
		searchReturn.getSolution().push_back(searchReturn.getPaths()[aux].append(" "));
		aux = std::stoi(searchReturn.getPaths()[aux]);
	} while (aux != vertex1);
	delete[]visited;
	return searchReturn;
}

SearchReturn Graph::greedy(int vertex1, int vertex2)
{
	SearchReturn searchReturn(this->vertexNumber);
	if (vertex1 < 0 || vertex1 >= this->vertexNumber || vertex2 < 0 || vertex2 >= this->vertexNumber) {
		return searchReturn;
	}
	float* dists = new float[this->vertexNumber];
	std::string* paths = new std::string[this->vertexNumber];
	bool* visited = new bool[this->vertexNumber];
	for (int i = 0; i < this->vertexNumber; i++) {
		dists[i] = MAX;
		paths[i] = "NE";
		visited[i] = false;
	}
	dists[vertex1] = this->vertexs[vertex1]->getHeuristic();
	paths[vertex1] = std::to_string(vertex1);
	Queue<QueueItem> queue;
	queue.add(QueueItem(this->vertexs[vertex1], this->vertexs[vertex1]->getHeuristic()));
	float cost;
	std::shared_ptr<Vertex> initialVertex;
	std::shared_ptr<Vertex> endVertex;
	while (!queue.empty()) {
		auto queueItem = queue.remove();
		initialVertex = queueItem.getVertex();
		if (initialVertex->getNumber() == vertex2) {
			break;
		}
		cost = queueItem.getCost();
		if (!visited[initialVertex->getNumber()]) {
			visited[initialVertex->getNumber()] = true;
			for (std::shared_ptr<Edge> edge : initialVertex->getEdges()) {
				endVertex = edge->getEndVertex();
				if (dists[endVertex->getNumber()] > endVertex->getHeuristic()) {
					dists[endVertex->getNumber()] = endVertex->getHeuristic();
					paths[endVertex->getNumber()] = std::to_string(initialVertex->getNumber());
					queue.add(QueueItem(endVertex, endVertex->getHeuristic()));
				}
			}
		}
	}
	searchReturn.setPaths(paths);
	searchReturn.setCosts(dists);
	int aux = vertex2;
	searchReturn.getSolution().push_back(std::to_string(aux).append(" "));
	do
	{
		searchReturn.getSolution().push_back(searchReturn.getPaths()[aux].append(" "));
		aux = std::stoi(searchReturn.getPaths()[aux]);
	} while (aux != vertex1);
	delete[]visited;
	return searchReturn;
}

SearchReturn Graph::aStar(int vertex1, int vertex2)
{
	SearchReturn searchReturn(this->vertexNumber);
	if (vertex1 < 0 || vertex1 >= this->vertexNumber || vertex2 < 0 || vertex2 >= this->vertexNumber) {
		return searchReturn;
	}
	float* dists = new float[this->vertexNumber];
	float* auxV = new float[this->vertexNumber];
	std::string* paths = new std::string[this->vertexNumber];
	bool* visited = new bool[this->vertexNumber];
	for (int i = 0; i < this->vertexNumber; i++) {
		dists[i] = MAX;
		paths[i] = "NE";
		visited[i] = false;
		auxV[i] = MAX;
	}
	auxV[vertex1] = 0.0f;
	dists[vertex1] = 0.0f;
	paths[vertex1] = std::to_string(vertex1);
	Queue<QueueItem> queue;
	queue.add(QueueItem(this->vertexs[vertex1], 0.0f));
	float cost;
	std::shared_ptr<Vertex> initialVertex;
	std::shared_ptr<Vertex> endVertex;
	while (!queue.empty()) {
		auto queueItem = queue.remove();
		initialVertex = queueItem.getVertex();
		if (initialVertex->getNumber() == vertex2) {
			break;
		}
		cost = queueItem.getCost();
		if (!visited[initialVertex->getNumber()]) {
			visited[initialVertex->getNumber()] = true;
			for (std::shared_ptr<Edge> edge : initialVertex->getEdges()) {
				endVertex = edge->getEndVertex();
				if (dists[endVertex->getNumber()] > auxV[initialVertex->getNumber()] + edge->getPeso() + endVertex->getHeuristic()) {
					auxV[endVertex->getNumber()] = auxV[initialVertex->getNumber()] + edge->getPeso();
					dists[endVertex->getNumber()] = auxV[initialVertex->getNumber()] + edge->getPeso() + endVertex->getHeuristic();
					paths[endVertex->getNumber()] = std::to_string(initialVertex->getNumber());
					queue.add(QueueItem(endVertex, auxV[initialVertex->getNumber()] + edge->getPeso() + endVertex->getHeuristic()));
				}
			}
		}
	}
	searchReturn.setPaths(paths);
	searchReturn.setCosts(dists);
	int aux = vertex2;
	searchReturn.getSolution().push_back(std::to_string(aux).append(" "));
	do
	{
		searchReturn.getSolution().push_back(searchReturn.getPaths()[aux].append(" "));
		aux = std::stoi(searchReturn.getPaths()[aux]);
	} while (aux != vertex1);
	delete[]visited;
	delete[]auxV;
	return searchReturn;
}
