/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 13 April 2016
 *
 * Description: A header file defining a customized LinkedList
 *				class. This LinkedList functions as a doubly-
 *				linked list; that is, each Node in the list is
 *				attached to the Node before it as well as the
 *				Node following it. This LinkedList is managed
 *				with a sentinel Node, a Node that is attached
 *				to the first and last elements in the LinkedList,
 *				but does not contain a value. This LinkedList is
 *				also traversable by using the customized Iterator
 *				class.
 ******************************************************************/
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#define MAX_CAPACITY 300

#include "Iterator.cpp"

/**
 * Namespace containing various customized data structures. 
 **/
namespace DataStructures
{
	/**
	 * A class representing a list comprised of Nodes. Each
	 * Node contains two pointers: one pointing to the Node
	 * before it, and one pointing to the Node after. These
	 * pointers are what "link" the list together, creating
	 * the LinkedList.
	 **/
	template <class T>
	class LinkedList
	{
	public:
		//Constructors / Destructor
		LinkedList(); //default
		LinkedList(const LinkedList& original); //copy constructor
		~LinkedList(); //destructor

		//Accessors
		T getFront() const;
		T getBack() const;

		//Iteration
		Iterator<T> begin() const;
		Iterator<T> end() const;

		//Modifiers
		void pushFront(T item);
		void pushBack(T item);
		void popFront();
		void popBack();
		void insert(T item, int index);
		void erase(T item);
		void eraseIndex(int index);
		void remove(T item);
		void clear();

		//Capacity
		int getSize() const;
		const int getMaxSize() const;
		bool isEmpty() const;
		bool isFull() const;

		//Operator overloads
		LinkedList<T> operator=(const LinkedList<T>& original);
		LinkedList<T>& operator+=(const LinkedList<T>& addend);
		LinkedList<T>& operator-=(const LinkedList<T>& subtrahend);

	private:
		Node<T>* _sentinelNode; //Node marking end of LinkedList
	}; //end class LinkedList
} //end namespace

#endif