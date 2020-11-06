#include "../include/queue_item.h"

QueueItem::QueueItem() : vertex(nullptr), cost(0.0f) {}

QueueItem::QueueItem(std::shared_ptr<Vertex> vertex, float cost) : vertex(vertex), cost(cost) {}

QueueItem::QueueItem(const QueueItem& queueItem) : vertex(queueItem.vertex), cost(queueItem.cost) {}

QueueItem::~QueueItem() = default;

std::shared_ptr<Vertex> QueueItem::getVertex()
{
	return this->vertex;
}

float QueueItem::getCost()
{
	return this->cost;
}
