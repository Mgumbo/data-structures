/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 13 April 2016
 *
 * Description: A file containing all of the implementation for the
 *				LinkedList class.
 *******************************************************************/
#include "LinkedList.h"
#include <assert.h>

namespace DataStructures
{
	/**
	 * Default constructor. Creates a sentinel Node that,
	 * until more items are added, just links to itself.
	 **/
	template <class T>
	LinkedList<T>::LinkedList()
	{
		//create a sentinel Node that points to itself and has no value
		_sentinelNode = new Node<T>();
		_sentinelNode->setNextNode(_sentinelNode);
		_sentinelNode->setPrevNode(_sentinelNode);
	} //end constructor

	/**
	 * Copy constructor. Resets the sentinel Node, and then copies each
	 * element from the passed LinkedList to this one.
	 **/
	template <class T>
	LinkedList<T>::LinkedList(const LinkedList& original)
	{
		//reset this LinkedList's sentinel Node
		_sentinelNode = new Node<T>();
		_sentinelNode->setNextNode(_sentinelNode);
		_sentinelNode->setPrevNode(_sentinelNode);

		//move through each item in the original list
		for (Node<T>* move = original._sentinelNode->getNextNode();
			move != original._sentinelNode; move = move->getNextNode())
		{
			//create new Node at end of LinkedList
			Node<T>* temp = new Node<T>(move->getItem(),
				_sentinelNode,
				_sentinelNode->getPrevNode());

			//attach new Node
			temp->getPrevNode()->setNextNode(temp);
			temp->getNextNode()->setPrevNode(temp);
		} //end for
	} //end constructor

	/**
	 * Destructor; this is called when the object is destroyed.
	 * Loops through the entire LinkedList and deletes all of
	 * the pointers, freeing up memory.
	 **/
	template <class T>
	LinkedList<T>::~LinkedList()
	{
		clear(); //delete everything but sentinel

		//delete sentinel
		delete _sentinelNode;
	} //end destructor

	/**
	 * Returns the front element in the LinkedList. 
	 **/
	template <class T>
	T LinkedList<T>::getFront() const
	{
		//Node AFTER sentinel Node is the front
		return _sentinelNode->getNextNode()->getItem();
	} //end getFront

	/**
	 * Returns the back element in the LinkedList. 
	 **/
	template <class T>
	T LinkedList<T>::getBack() const
	{
		//Node BEFORE sentinel Node is the back
		return _sentinelNode->getPrevNode()->getItem();
	} //end getBack

	/**
	 * Returns an Iterator that points to the Node AFTER
	 * the sentinel Node. Since the sentinel Node is connected
	 * to the front and back of the LinkedList, the Node
	 * after the sentinel Node holds the front item in the
	 * LinkedList.
	 **/
	template <class T>
	Iterator<T> LinkedList<T>::begin() const
	{
		return Iterator<T>(this, _sentinelNode->getNextNode());
	} //end begin

	/**
	 * Returns an Iterator that points to the sentinel Node of
	 * the LinkedList. The Node that is pointed to does not
	 * have a value and serves only as a mark for the end of
	 * the LinkedList.
	 **/
	template <class T>
	Iterator<T> LinkedList<T>::end() const
	{
		return Iterator<T>(this, _sentinelNode);
	} //end end

	/**
	 * Pushes a specified item to the front of the LinkedList.
	 * Takes a generic-type parameter, and then creates an
	 * associating Node, which is then added to the front of
	 * the LinkedList.
	 **/
	template <class T>
	void LinkedList<T>::pushFront(T item)
	{
		assert(!isFull()); //make sure the LinkedList isn't full

		//create new Node that points forward to sentinel's next node
		//and backward to sentinel
		Node<T>* temp = new Node<T>(item, _sentinelNode->getNextNode(), _sentinelNode);

		//link the new Node to the next Node...
		temp->getNextNode()->setPrevNode(temp);

		//...then link the new Node to the previous Node
		temp->getPrevNode()->setNextNode(temp);
	} //end pushFront

	/**
	 * Pushes a specified item to the back of the LinkedList.
	 * Takes a generic-type parameter, and then creates an 
	 * associating Node, which is then added to the back of
	 * the LinkedList.
	 **/
	template <class T>
	void LinkedList<T>::pushBack(T item)
	{
		assert(!isFull()); //make sure the LinkedList isn't full

		//create new Node that points forward to sentinel and
		//backward to sentinel's previous Node
		Node<T>* temp = new Node<T>(item, _sentinelNode, _sentinelNode->getPrevNode());

		//link new Node to the next Node...
		temp->getNextNode()->setPrevNode(temp);

		//...then link new Node to the previous Node
		temp->getPrevNode()->setNextNode(temp);
	} //end pushBack

	/**
	 * Removes the front element from the LinkedList. 
	 **/
	template <class T>
	void LinkedList<T>::popFront()
	{
		assert(!isEmpty()); //make sure the LinkedList isn't empty

		//temporary Node representing front Node in LinkedList
		Node<T>* temp = _sentinelNode->getNextNode();

		//link the previous Node to the next Node...
		temp->getPrevNode()->setNextNode(temp->getNextNode());

		//...then link the next Node to the previous Node
		temp->getNextNode()->setPrevNode(temp->getPrevNode());

		//delete the now unlinked Node to free memory
		delete temp;
	} //end popFront

	/**
	 * Removes the back element from the LinkedList. 
	 **/
	template <class T>
	void LinkedList<T>::popBack()
	{
		assert(!isEmpty()); //make sure the LinkedList isn't empty

		//temporary Node representing the back Node in LinkedList
		Node<T>* temp = _sentinelNode->getPrevNode();

		//link the previous Node to the next Node...
		temp->getPrevNode()->setNextNode(temp->getNextNode());

		//...then link the next Node to the previous Node
		temp->getNextNode()->setPrevNode(temp->getPrevNode());

		//delete the now unlinked Node to free memory
		delete temp;
	} //end popBack

	/**
	 * Inserts a new element into the LinkedList at a specified
	 * index. If the specified index is too large, the new item
	 * is added to the back of the LinkedList; if the specified
	 * index is too small, the new item is added to the front.
	 **/
	template <class T>
	void LinkedList<T>::insert(T item, int index)
	{
		assert(!isFull()); //make sure the LinkedList isn't full

		//if specified index is...
		if (index > getSize()) //larger than LinkedList size
			pushBack(item); //just add to the back
		else if (index <= 0) //zero or negative index
			pushFront(item); //just add to the front
		else //somewhere in the middle
		{
			//temp Node to loop through elements, starting with first
			Node<T>* temp = _sentinelNode->getNextNode();

			//loop through until one Node before appropriate index
			for (int i = 0; i < (index - 1); i++)
				temp = temp->getNextNode(); //move forward one Node

			//create new Node attached to temp's next Node and temp
			Node<T>* newNode = new Node<T>(item, temp->getNextNode(), temp);

			//link the next Node to the new Node
			temp->getNextNode()->setPrevNode(newNode);

			//link the Node pointed to by temp to the new Node
			temp->setNextNode(newNode);
		} //end else
	} //end insert

	/**
	 * Loops through and removes the first occurrence of a specified
	 * item in the LinkedList. If the specified item is not found,
	 * does nothing.
	 **/
	template <class T>
	void LinkedList<T>::erase(T item)
	{
		assert(!isEmpty()); //make sure the LinkedList isn't empty

		//temp Node to loop through elements, starting with first
		Node<T>* temp = _sentinelNode->getNextNode();

		//move through elements until temp points to Node with 
		//specified value or moves through the entire list
		while (temp->getItem() != item && temp != _sentinelNode)
			temp = temp->getNextNode();

		//if not pointing to sentinel, item was found
		if (temp != _sentinelNode)
		{
			//link previous Node to next Node
			temp->getPrevNode()->setNextNode(temp->getNextNode());

			//link next Node to previous Node
			temp->getNextNode()->setPrevNode(temp->getPrevNode());

			delete temp; //remove the now unlinked element
		} //end if
	} //end erase

	/**
	 * Erases the element of the LinkedList at the specified index.
	 * If the index is larger than the size of the LinkedList, this
	 * function just erases the last item. If the index is smaller
	 * than 0, this function erases the first item.
	 **/
	template <class T>
	void LinkedList<T>::eraseIndex(int index)
	{
		//if the specified index is...
		if (index > getSize()) //larger than this list
			popBack(); //just remove back element
		else if (index < 0) //negative
			popFront(); //just remove front element
		else //somewhere in the middle
		{
			//temp Node to loop through elements, starting with first
			Node<T>* temp = _sentinelNode->getNextNode();

			//loop through until at desired Node
			for (int i = 0; i < index; i++)
				temp = temp->getNextNode();

			//link previous Node to next Node
			temp->getPrevNode()->setNextNode(temp->getNextNode());

			//link next Node to previous Node
			temp->getNextNode()->setPrevNode(temp->getPrevNode());

			delete temp; //remove the now unlinked element
		} //end else
	} //end eraseIndex

	/**
	 * Loops through and removes all occurrences of a specified item
	 * in the LinkedList.
	 **/
	template <class T>
	void LinkedList<T>::remove(T item)
	{
		assert(!isEmpty()); //make sure the LinkedList isn't empty

		//temp Node to loop through elements, starting with first
		Node<T>* temp = _sentinelNode->getNextNode();

		//loop through all of the elements
		while (temp != _sentinelNode)
		{
			//hold position of next Node
			Node<T>* nextNode = temp->getNextNode();

			//if the current pointed-to Node matches the specified item
			if (temp->getItem() == item)
			{
				//link previous Node to next Node
				temp->getPrevNode()->setNextNode(temp->getNextNode());

				//link next Node to previous Node
				temp->getNextNode()->setPrevNode(temp->getPrevNode());
			
				delete temp; //remove the now unlinked element
			} //end if

			temp = nextNode; //move forward one Node
		} //end while
	} //end remove

	/**
	 * Deletes all elements of the LinkedList except the sentinel
	 * Node, which is set to its default state of pointing to
	 * itself (as there is nothing left in the LinkedList).
	 **/
	template <class T>
	void LinkedList<T>::clear()
	{
		//temp Node to loop through elements, starting with first
		Node<T>* temp = _sentinelNode->getNextNode();

		//loop through all Nodes
		while (temp != _sentinelNode)
		{
			Node<T>* nextNode = temp->getNextNode();
			delete temp; //remove the Node
			temp = nextNode; //move onto the next
		} //end while

		//set sentinel to point to itself again
		_sentinelNode->setNextNode(_sentinelNode);
		_sentinelNode->setPrevNode(_sentinelNode);
	} //end clear

	/**
	 * Iterates through the LinkedList, counting each iteration
	 * until the end is reached, and then returns the number of
	 * iterations.
	 **/
	template <class T>
	int LinkedList<T>::getSize() const
	{
		int count = 0; //count number of elements

		//iterate through all elements and count each incrementation
		for (Iterator<T> it = begin(); it != end(); ++it)
			count++;

		return count;
	} //end getSize

	/**
	 * Returns the maximum possible capacity of a LinkedList. 
	 **/
	template <class T>
	const int LinkedList<T>::getMaxSize() const
	{
		return MAX_CAPACITY;
	} //end getMaxSize

	/**
	 * Returns true if the LinkedList contains no elements. If
	 * the sentinel Node is not attached to any other Nodes, then
	 * the LinkedList must be empty.
	 **/
	template <class T>
	bool LinkedList<T>::isEmpty() const
	{
		//if the sentinel points to itself, there are no items
		return (_sentinelNode->getNextNode() == _sentinelNode);
	} //end isEmpty

	/**
	 * Checks to see if the LinkedList's current size is equal
	 * to the maximum possible capacity. If true, then the
	 * LinkedList is full and can no longer hold any items.
	 **/
	template <class T>
	bool LinkedList<T>::isFull() const
	{
		return (getSize() == getMaxSize());
	} //end isFull

	/**
	 * Overloads the assignment operator (=). Clears the LinkedList,
	 * then creates and returns a copy of the specified original,
	 * using the copy constructor.
	 **/
	template <class T>
	LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& original)
	{
		clear(); //clear list

		LinkedList<T> newList(original); //create copy of passed original

		return newList;
	} //end = assignment operator overload

	/**
	 * Overloads the compound addition operator (+=). Takes the contents
	 * of a specified list and pushes those contents to the back of this
	 * one, then returning this object.
	 **/
	template <class T>
	LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T>& addend)
	{
		//iterate through other list
		//(auto keyword infers return type and makes declared variable that type)
		for (auto it = addend.begin(); it != addend.end(); ++it)
			pushBack(*it); //push that list's items onto this list

		return *this;
	} //end += compound addition operator overload

	/**
	 * Overloads the compound subtraction operator (-=). Removes any
	 * elements from this list that it shares in common with a specified
	 * other list.
	 **/
	template <class T>
	LinkedList<T>& LinkedList<T>::operator-=(const LinkedList<T>& subtrahend)
	{
		//iterate through other list
		//(auto keyword infers return type and makes declared variable that type)
		for (auto it = subtrahend.begin(); it != subtrahend.end(); ++it)
			remove(*it); //remove the first instance of common element

		return *this;
	} //end -= compound subtraction operator overload
} //end namespace