/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 13 April 2016
 *
 * Description: A header file defining a customized Node class.
 *		This Node is meant to serve as an element in the
 *		custom LinkedList class, and has pointers to two
 *		other Nodes: the next Node in the LinkedList, and
 *		the previous Node in the LinkedList. This Node is
 *		implemented in this way so that the LinkedList can
 *		function as a doubly-linked list.
 ******************************************************************/
#ifndef _NODE_H_
#define _NODE_H_

/**
 * Namespace containing various customized data structures. 
 **/
namespace DataStructures
{
	/**
	 * A class that represents an element in a doubly-linked
	 * list, linked via pointers to both the next and previous
	 * Nodes in the list.
	 **/
	template <class T>
	class Node
	{
	public:
		//Constructors
		Node(); //default
		Node(const T& item);
		Node(const T item, Node<T>* nextNode);
		Node(const T item, Node<T>* nextNode, Node<T>* prevNode);

		//Modifiers
		void setItem(const T& item);
		void setNextNode(Node<T>* nextNode);
		void setPrevNode(Node<T>* prevNode);

		//Accessors
		T& getItem();
		Node<T>* getNextNode() const;
		Node<T>* getPrevNode() const;

	private:
		T _item; //the data of the Node
		Node<T>* _nextNode, * _prevNode;
	}; //end class Node
} //end namespace

#endif
