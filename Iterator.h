/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 13 April 2016
 *
 * Description: A header file defining a customized Iterator class
 *				that can be used to iterate through the custom
 *				LinkedList class. So it can function properly for
 *				the LinkedList class, this Iterator is implemented
 *				as a bidirectional iterator.
 ******************************************************************/
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <iterator>
#include "Node.cpp"

/**
 * Namespace containing various customized data structures. 
 **/
namespace DataStructures
{
	/**
	 * Forward declare LinkedList class so we can utilize
	 * pointers to that class. Since the pointer to this
	 * class is all that is needed, the actual LinkedList
	 * header/implementation does not need to be included
	 * with #include.
	 **/
	template <class T>
	class LinkedList;

	/**
	 * Iterator class derived from the C++ template class iterator.
	 * Used to specify category of iterator being used; in this case,
	 * it is a bidirectional iterator that measures distances between
	 * positions as integers. As a bidirectional iterator, this can
	 * be used to access a sequence of elements both forwards and
	 * backwards.
	 **/
	template <class T>
	class Iterator : public std::iterator<std::bidirectional_iterator_tag, int>
	{
	public:
		//Constructors / Destructor
		Iterator(); //default
		Iterator(const Iterator<T>& original); //copy
		Iterator(const LinkedList<T>* list, Node<T>* initialNode); //regular

		//Overloaded equivalence operators
		bool operator==(const Iterator<T>& comparate) const;
		bool operator!=(const Iterator<T>& comparate) const;

		//Overloaded dereference operator
		T& operator*() const;
		//NOTE: The unary postfix operator (->) is not overloaded

		//Overloaded assignment operator (copy-assignable)
		Iterator<T> operator=(const Iterator<T>& original);

		//Overloaded incrementation operators
		Iterator<T>& operator++(); //prefix
		Iterator<T>& operator--(); //prefix
		Iterator<T> operator++(int ignoredValue); //suffix (post-increment)
		Iterator<T> operator--(int ignoredValue); //suffix (post-increment)

	private:
		const LinkedList<T>* _list; //list associated w/ iterator
		Node<T>* _currIndexPtr; //current location in list
	};
} //end namespace

#endif