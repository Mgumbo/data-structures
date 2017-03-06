/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 13 April 2016
 *
 * Description: A file containing all of the implementation for the
 *		Node class.
 ******************************************************************/
#include "Node.h"

namespace DataStructures
{
	/**
	 * Default constructor. Sets the pointers to nullptr and does
	 * not initialize this Node's item value.
	 **/
	template <class T>
	Node<T>::Node() :
		_nextNode(nullptr),
		_prevNode(nullptr)
	{
		//EMPTY
	} //end default constructor

	/**
	 * Item-only constructor. Assigns the item value based on
	 * passed parameter and sets pointers to nullptr.
	 **/
	template <class T>
	Node<T>::Node(const T& item) :
		_item(item),
		_nextNode(nullptr),
		_prevNode(nullptr)
	{
		//EMPTY
	} //end constructor

	/**
	 * Item and forward Node constructor. Assigns the item value
	 * and pointer to next Node based on passed parameters and
	 * sets the previous Node pointer to nullptr.
	 **/
	template <class T>
	Node<T>::Node(const T item, Node<T>* nextNode) :
		_item(item),
		_nextNode(nextNode),
		_prevNode(nullptr)
	{
		//EMPTY
	} //end constructor

	/**
	 * Full constructor. Assigns all member variable values based
	 * on passed parameters.
	 **/
	template <class T>
	Node<T>::Node(const T item, Node<T>* nextNode, Node<T>* prevNode) :
		_item(item),
		_nextNode(nextNode),
		_prevNode(prevNode)
	{
		//EMPTY
	} //end constructor

	/**
	 * Assigns the value of this Node's item. 
	 **/
	template <class T>
	void Node<T>::setItem(const T& item)
	{
		_item = item;
	} //end setItem

	/**
	 * Assigns a location to the pointer to the next Node.
	 **/
	template <class T>
	void Node<T>::setNextNode(Node<T>* nextNode)
	{
		_nextNode = nextNode;
	} //end setNextNode

	/**
	 * Assigns a location to the pointer to the previous Node. 
	 **/
	template <class T>
	void Node<T>::setPrevNode(Node<T>* prevNode)
	{
		_prevNode = prevNode;
	} //end setPrevNode

	/**
	 * Returns the item value of this Node. 
	 **/
	template <class T>
	T& Node<T>::getItem()
	{
		return _item;
	} //end getItem

	/**
	 * Returns a pointer to the next Node in a list,
	 * if any.
	 **/
	template <class T>
	Node<T>* Node<T>::getNextNode() const
	{
		return _nextNode;
	} //end getNextNode

	/**
	 * Returns a pointer to the previous Node in a list,
	 * if any.
	 **/
	template <class T>
	Node<T>* Node<T>::getPrevNode() const
	{
		return _prevNode;
	} //end getPrevNode
} //end namespace
