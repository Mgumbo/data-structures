/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 23 March 2016
 *
 * Description: A class representing a queue, a data structure
 *				that functions as a list with a "First In, First
 *				Out" policy. The front and back of the queue can
 *				both be accessed, but items can only be added to
 *				the back of the queue, and items can only be 
 *				removed from the front.
 ******************************************************************/
#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#define MAX_CAPACITY 100 //no more than 100 items

/**
 * Namespace containing various customized data structures.
 **/
namespace DataStructures
{
	/**
	 * A class representing a queue; that is, a list that adheres to
	 * a "First In, First Out" policy. The front and back of the queue
	 * can be accessed, but ONLY THE FRONT can be modified. This is a
	 * template class, so any object instance of this class can be of
	 * any data type.
	 **/
	template<class T>
	class Myqueue
	{
	public:
		//Constructor
		Myqueue();

		//Modifiers
		bool push(T item);
		bool pop();
		void clear();

		//Getters
		T getFront() const;
		T getBack() const;
		int getSize() const;
		bool isEmpty() const;
		bool isFull() const;

	private:
		T _queue[MAX_CAPACITY]; //underlying array
		int _front, _back, _size;
	};
} //end namespace

#endif