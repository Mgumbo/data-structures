/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 23 March 2016
 *
 * Description: File containing the implementation for
 *				the Myqueue class.
 ******************************************************************/
#include "Myqueue.h"
#include <iostream>

namespace DataStructures
{
	/**
	* Default constructor. Initializes the front and back indexes of
	* the queue to their default values, as well as the size to 0.
	**/
	template<class T>
	Myqueue<T>::Myqueue() : _front(0), _back(-1), _size(0)
	{
		//EMPTY
	} //end constructor

	/**
	* Adds an item to the back of the queue if it is not already full.
	* Treats the underlying array as a circular array; if the back index
	* is at max value, it resets.
	**/
	template<class T>
	bool Myqueue<T>::push(T item)
	{
		if (isFull()) //make sure there is room in the queue
		{
			std::cout << "Error: Queue full, unable to push\n";
			return false;
		} //end if

		//loop the back index to the front of the array if needed
		_back = (_back + 1) % MAX_CAPACITY;
		_queue[_back] = item;
		_size++;

		return true;
	} //end push

	/**
	* Removes an item from the front of the queue if it is not already empty.
	* Treats the underlying array as a circular array; if the front index
	* is at max value, it resets.
	**/
	template<class T>
	bool Myqueue<T>::pop()
	{
		if (isEmpty()) //make sure there's something to remove
		{
			std::cout << "Error: Queue empty, no elements to pop\n";
			return false;
		} //end if

		//treat underlying array as a circular array
		_front = (_front + 1) % MAX_CAPACITY;
		_size--;

		return true;
	} //end pop

	/**
	* "Clears" the queue by resetting its indices and size to default values.
	* Memory occupied by items in the queue will simply be overwritten.
	**/
	template<class T>
	void Myqueue<T>::clear()
	{
		_front = _size = 0;
		_back = -1;
	} //end clear

	/**
	* Returns the front item of the queue if it exists. Otherwise, it
	* returns NULL.
	**/
	template<class T>
	T Myqueue<T>::getFront() const
	{
		return (isEmpty()) ? NULL : _queue[_front];
	} //end getFront

	/**
	* Returns the back item of the queue if it exists. Otherwise, it
	* returns NULL.
	**/
	template<class T>
	T Myqueue<T>::getBack() const
	{
		return (isEmpty()) ? NULL : _queue[_back];
	} //end getBack

	/**
	* Returns the number of elements in the queue.
	**/
	template<class T>
	int Myqueue<T>::getSize() const
	{
		return _size;
	} //end getSize

	/**
	* Returns true if there are no items in the queue.
	**/
	template<class T>
	bool Myqueue<T>::isEmpty() const
	{
		return (_size == 0);
	} //end isEmpty

	/**
	* Returns true if the queue is at max capacity.
	**/
	template<class T>
	bool Myqueue<T>::isFull() const
	{
		return (_size == MAX_CAPACITY);
	} //end isEmpty
} //end namespace