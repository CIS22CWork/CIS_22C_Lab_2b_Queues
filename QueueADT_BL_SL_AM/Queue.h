/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2b

Used Microsoft Visual Studio 2017

Queue Class
queues are a type of container adaptor, 
specifically designed to operate in a FIFO context (first-in first-out), 
where elements are inserted into one end of the container and extracted from the other.
*/

#ifndef STACK_H
#define STACK_H
#include "List.h"

template <class T>
class Queue : protected List<T>
{
public:
	//******************************************************
	// Default Constructor        
	//******************************************************
	Queue () { List (); }
	//******************************************************
	// Destructor          
	//******************************************************
	~Queue () { clear (); }

	//******************************************************
	// pop        
	//
	// removes the top element     
	//******************************************************
	bool pop ()
	{
		return erase (size () - 1);
	}

	//******************************************************
	// push        
	//
	// inserts element at the top     
	//******************************************************
	bool push (T newEntry)
	{
		return push_back (newEntry);
	}

	//******************************************************
	// empty        
	//
	// checks whether the underlying container is empty     
	//******************************************************
	bool empty () { return List::empty (); }

	//******************************************************
	// size         
	//
	// returns the number of elements     
	//******************************************************
	int size () { return List::size (); }

	//******************************************************
	// clear          
	//
	// Removes all elements from the list container
	// and leaving the container with a size of 0.
	//******************************************************
	void clear () { List::clear (); }

	//******************************************************
	// top        
	//
	// accesses the top element     
	//******************************************************
	T top ()
	{
		return getValue (size () - 1);
	}
	//******************************************************
	// operator<<        
	//******************************************************
	template <class T>
	friend std::ostream& operator<< (std::ostream &foo, Queue<T> *ListPtr);
};

#endif