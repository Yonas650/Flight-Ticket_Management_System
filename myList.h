#ifndef MyList_H
#define MyList_H
#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
template <typename T>
class Node
{
	private:
		T elem; //data element 
		Node* next; //Link (pointer) to the next Node
		
	public:
		Node(T elem) : elem(elem), next(NULL)
		{}
		template <typename T2> friend class MyList ;
		friend class FlightHASHTABLE;
};
//=====================================
template <typename T>
class MyList
{
	private:
		Node<T>* head; // pointer to the head of list
	public:
		MyList (); // empty list constructor
		~MyList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		void addFront(T elem); // add a new Node at the front of the list
		void removeFront(); // remove front Node from the list
		unsigned int countElem(int elem); //count frequency of an element in the list
		int getIndexOf(int elem); //returns first index of an element in the list, -1 if the element is not present
		void display() const;
		void sort();  // sort the elements of the list
		void erase(T elem);
		friend class FlightHASHTABLE;
};
#endif