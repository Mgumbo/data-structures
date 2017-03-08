/******************************************************************
 * Author: Mgumbo
 *
 * Date Completed: 27 February 2016
 *
 * Description: A class representing a stack, a data structure that
 *		functions as a list with a "First In, Last Out"
 *		policy. Only the top of the stack can be accessed;
 *		items below the top cannot be accessed until
 *		everything above them has been removed.
 ******************************************************************/
#ifndef _MYSTACK_H_
#define _MYSTACK_H_

#define SIZE 20 //maximum size of the stack

namespace DataStructures
{
	template <class T>
	class Mystack
	{
	private:
		T m_list[SIZE]; //an array representing the stack
		int m_topIndex; //points to next available index of stack
	public:
		Mystack(); //default constructor

		//Modify the stack
		bool push(T);
		bool pop();
		void clear();

		//Get information about the stack
		bool isFull() const;
		bool isEmpty() const;
		T top() const;
		int size() const;
	}; //end class Mystack
} //end namespace

#endif
