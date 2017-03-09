/*******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 13 April 2016
 *
 * Description: A file containing all of the implementation for the
 *		Iterator class.
 *******************************************************************/
#include "Iterator.h"

namespace DataStructures
{
	/**
	 * Default constructor. Initializes the associated list as well as
	 * the index pointer to nullptr.
	 **/
	template <class T>
	Iterator<T>::Iterator() :
		_list(nullptr), _currIndexPtr(nullptr)
	{
		//EMPTY
	} //end default constructor

	/**
	 * Copy constructor. Copies the list and index pointer referenced
	 * by the passed parameter.
	 **/
	template <class T>
	Iterator<T>::Iterator(const Iterator<T>& original)
	{
		//set this object's member variables equal to the original
		_list = original._list;
		_currIndexPtr = original._currIndexPtr;
	} //end copy constructor

	/**
	 * Constructor with two arguments: the list that the iterator
	 * is meant to iterate through, and a pointer to an initial Node
	 * in the list for reference.
	 **/
	template <class T>
	Iterator<T>::Iterator(const LinkedList<T>* list, Node<T>* initialNode) :
		_list(list),
		_currIndexPtr(initialNode)
	{
		//EMPTY
	} //end constructor

	/**
	 * Overloads the comparison operator (==). Will only return
	 * true if this iterator references the exact same list and
	 * position as the passed comparate.
	 **/
	template <class T>
	bool Iterator<T>::operator==(const Iterator<T>& comparate) const
	{
		//check both the list itself and the index pointer
		return (_list == comparate._list && _currIndexPtr == comparate._currIndexPtr);
	} //end == comparison operator overload

	/**
	 * Overloads the inequality operator (!=). Will only return
	 * true if this iterator does NOT reference the exact same
	 * list and position as the passed comparate.
	 **/
	template <class T>
	bool Iterator<T>::operator!=(const Iterator<T>& comparate) const
	{
		//check both the list itself and the index pointer
		return (_list != comparate._list || _currIndexPtr != comparate._currIndexPtr);
	} //end != inequality operator overload

	/**
	 * Overloads the derefence operator (*) to make it return
	 * the item reference at the current position of the iterator.
	 **/
	template <class T>
	T& Iterator<T>::operator*() const
	{
		//return the pointed-to Node's item
		return _currIndexPtr->getItem();
	} //end * dereference operator overload

	/**
	 * Overloads the assignment operator (=). Causes this iterator's
	 * associated list and pointer to the list's current index to
	 * become the same as the passed original Iterator.
	 **/
	template <class T>
	Iterator<T> Iterator<T>::operator=(const Iterator<T>& original)
	{
		*this(original); //call copy constructor

		return *this; //return this iterator with set member variables
	} //end assignment operator overload

	/**
	 * Overloads the prefix increment operator (++). Causes the
	 * operator to move the pointer to the current index to the
	 * next index and then return a reference to this object.
	 * This operator goes BEFORE the object.
	 *		Ex:	++iter;
	 **/
	template <class T>
	Iterator<T>& Iterator<T>::operator++()
	{
		_currIndexPtr = _currIndexPtr->getNextNode(); //move forward one element
		return *this; //return this iterator with reference to next position in list
	} //end ++ prefix increment operator overload

	/**
	 * Overloads the prefix decrement operator (--). Causes the
	 * operator to move the pointer to the current index to the
	 * previous index and then return a reference to this object.
	 * This operator goes BEFORE the object.
	 *		Ex: --iter;
	 **/
	template <class T>
	Iterator<T>& Iterator<T>::operator--()
	{
		_currIndexPtr = _currIndexPtr->getPrevNode(); //move back one element
		return *this; //return this iterator with reference to previous position in list
	} //end -- prefix decrement operator overload

	/**
	 * Overloads the suffix increment operator (++). Causes the
	 * operator to move the pointer to the current index to the
	 * next index and then return a reference to this object.
	 * This operator goes AFTER the object.
	 *		Ex: iter++;
	 * The int parameter `ignoredValue` is included so that
	 * this overload is differentiated from the prefix
	 * operator.
	 **/
	template <class T>
	Iterator<T> Iterator<T>::operator++(int ignoredValue)
	{
		Iterator<T> temp(*this); //create new Iterator using copy constructor
		++*this;
		return temp;
	} //end ++ suffix increment operator overload

	/**
	 * Overloads the suffix decrement operator (--). Causes the
	 * operator to move the pointer to the current index to the
	 * previous index and then return a reference to this object.
	 * This operator goes AFTER the object.
	 *		Ex: iter--;
	 * The int parameter `ignoredValue` is included so that
	 * this overload is differentiated from the prefix operator
	 **/
	template <class T>
	Iterator<T> Iterator<T>::operator--(int ignoredValue)
	{
		Iterator<T> temp(*this); //create new Iterator using copy constructor
		--*this;
		return temp;
	} //end -- suffix decrement operator overload
} //end namespace
