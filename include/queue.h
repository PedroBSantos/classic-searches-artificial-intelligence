#pragma once

template <typename T>
class Queue
{
private:
	T* elements;
	int numberElements;
	int length;
	int left(int i);
	int right(int i);
	int father(int i);
	void upHeap(int i);
	void downHeap(int i);
	void increaseLength();

public:
	Queue(int length = 5);
	Queue(const Queue<T>& queue);
	~Queue();
	int size();
	void add(T element);
	T remove();
	bool empty();
};

template <typename T>
inline Queue<T>::Queue(int length)
{
	this->length = length;
	this->elements = new T[this->length];
	this->numberElements = 0;
}

template <typename T>
inline Queue<T>::Queue(const Queue<T>& queue)
{
	this->elements = queue.elements;
	this->numberElements = queue.numberElements;
	this->length = queue.length;
}

template <typename T>
inline Queue<T>::~Queue()
{
	if (this->elements != nullptr)
	{
		delete[] this->elements;
	}
}

template <typename T>
inline int Queue<T>::size()
{
	return this->numberElements;
}

template <typename T>
inline int Queue<T>::left(int i)
{
	return (2 * i) + 1;
}

template <typename T>
inline int Queue<T>::right(int i)
{
	return (2 * i) + 2;
}

template <typename T>
inline int Queue<T>::father(int i)
{
	return (i - 1) / 2;
}

template <typename T>
inline void Queue<T>::upHeap(int i)
{
	int p = this->father(i);
	if (i > 0 && this->elements[i] < this->elements[p])
	{
		T aux = this->elements[p];
		this->elements[p] = this->elements[i];
		this->elements[i] = aux;
		this->upHeap(p);
	}
}

template <typename T>
inline void Queue<T>::downHeap(int i)
{
	int l = this->left(i);
	int r = this->right(i);
	int bigger;
	if (l < this->numberElements && this->elements[l] < this->elements[i])
	{
		bigger = l;
	}
	else
	{
		bigger = i;
	}
	if (r < this->numberElements && this->elements[r] < this->elements[bigger])
	{
		bigger = r;
	}
	if (bigger != i)
	{
		T aux = this->elements[i];
		this->elements[i] = this->elements[bigger];
		this->elements[bigger] = aux;
		this->downHeap(bigger);
	}
}

template <typename T>
inline void Queue<T>::add(T element)
{
	if (this->numberElements == this->length)
	{
		this->increaseLength();
	}
	this->elements[this->numberElements] = element;
	this->upHeap(this->numberElements);
	this->numberElements++;
}

template <typename T>
inline T Queue<T>::remove()
{
	if (this->numberElements == 0)
	{
		return T();
	}
	T bigger = this->elements[0];
	if (this->numberElements != 1)
	{
		this->elements[0] = this->elements[this->numberElements - 1];
		this->downHeap(0);
	}
	this->numberElements--;
	return bigger;
}

template <typename T>
inline bool Queue<T>::empty()
{
	return this->numberElements == 0;
}

template <typename T>
inline void Queue<T>::increaseLength()
{
	T* newElements = new T[this->length * 2];
	for (int i = 0; i < this->length; i++) {
		newElements[i] = this->elements[i];
	}
	this->elements = newElements;
	this->length *= 2;
}
