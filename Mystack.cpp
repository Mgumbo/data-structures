/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 27 February 2016
 *
 * Description: File containing the implementation for
 *		the Myqueue class.
 ******************************************************************/
#include <iostream>
#include "Mystack.h"

namespace DataStructures
{
	/**
	* Default constructor. Initializes the index for the top
	* of the stack to the 0th index.
	**/
	template <class T>
	Mystack<T>::Mystack()
	{
		m_topIndex = 0;
	} //end constructor

	/**
	* Push an item onto the top of the stack. First checks
	* if the stack is full, and if it is, then it prints an
	* error message and does not add an item to the stack.
	* If the stack is not full, an item is added to the top
	* of the stack and the top index is incremented.
	**/
	template <class T>
	bool Mystack<T>::push(T item)
	{
		//make sure the stack isn't already full
		if (isFull())
		{
			std::cout << "ERROR: Stack full, unable to add item.\n";
			return false;
		} //end if
		else
		{
			m_list[m_topIndex++] = item;
			return true;
		} //end else
	} //end push

	/**
	* Remove the top item of the stack. If the stack is empty,
	* print an error message and do not modify the stack.
	* Otherwise, simply decrements the top index (without
	* actually removing anything), as if more items are added,
	* the previous values will simply be written over.
	**/
	template <class T>
	bool Mystack<T>::pop()
	{
		//make sure the stack isn't already empty
		if (isEmpty())
		{
			std::cout << "ERROR: Stack empty, no items to remove.\n";
			return false;
		} //end if
		else
		{
			m_topIndex--;
			return true;
		} //end else
	} //end pop

	/**
	* Remove all the items from the stack. Sets the top index
	* to 0 (as adding more items will write over any previous
	* items that would have been at a given index on the stack).
	**/
	template <class T>
	void Mystack<T>::clear()
	{
		m_topIndex == 0;
	} //end clear

	/**
	* Check whether or not the stack is at capacity.
	**/
	template <class T>
	bool Mystack<T>::isFull() const
	{
		return m_topIndex == SIZE;
	} //end isFull

	/**
	* Check whether or not the stack has any items in it
	* at all.
	**/
	template <class T>
	bool Mystack<T>::isEmpty() const
	{
		return m_topIndex == 0;
	} //end isEmpty

	/**
	* Return the top item of the stack. If the top index is
	* 0 (meaning there are no items on the stack), this
	* returns NULL.
	**/
	template <class T>
	T Mystack<T>::top() const
	{
		return m_topIndex == 0 ? NULL : m_list[m_topIndex - 1];
	} //end top

	/**
	* Return the size of the stack. Since the top index always
	* points to the next available index of the stack, then
	* returning the top index indicates the number of items
	* in the stack.
	**/
	template <class T>
	int Mystack<T>::size() const
	{
		return m_topIndex;
	} //end size
} //end namespace
