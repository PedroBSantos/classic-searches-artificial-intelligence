#pragma once

#include "vertex.h"
#include <memory>

class QueueItem
{
private:
	std::shared_ptr<Vertex> vertex;
	float cost;
public:
	QueueItem();
	QueueItem(std::shared_ptr<Vertex> vertex, float cost);
	QueueItem(const QueueItem& queueItem);
	~QueueItem();
	std::shared_ptr<Vertex> getVertex();
	float getCost();
	friend bool operator<(const QueueItem& queueItem1, const QueueItem& queueItem2) {
		return queueItem1.cost < queueItem2.cost;
	}
};
