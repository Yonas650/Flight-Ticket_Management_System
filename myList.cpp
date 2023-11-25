#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
#include "myList.h"
#include "flighthashtable.h"
using namespace std;
// constructor
template<typename T> MyList<T>::MyList ()
{
	this->head = NULL;
}
template MyList<HashNode>::MyList();
//====================================
// destructor to clean up all nodes
template<typename T> MyList<T>::~MyList () 
{
	while (!empty()) removeFront();
}
template MyList<HashNode>::~MyList();
//====================================
// Check if the list is empty or not
template<typename T> bool MyList<T>::empty() const 
{
	return head==NULL;
}
template bool MyList<HashNode>::empty() const;
//====================================
// add a node at the front of the list
template<typename T> void MyList<T>::addFront(T elem)
{
	Node<T>* a=new Node<T>(elem);
	a->elem=elem;
	a->next=head;
	head=a;
}
template void MyList<HashNode>::addFront(HashNode elem);

//====================================
// remove the first node from the list
template<typename T> void MyList<T>::removeFront()
{
	Node<T>* old=head;
	head=old->next;
	delete old;
}
template void MyList<HashNode>::removeFront();
//====================================
// count frequency of an element in the list
template<typename T> unsigned int MyList<T>::countElem(int elem)
{
	int counter=0;
	Node<T>* n=head;
	while(n!=NULL)
	{
		if (elem==n->elem)
		{
			counter+=1;
			return counter;
		}
		n=n->next;
    
	}
return 0;
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
template<typename T> int MyList<T>::getIndexOf(int elem)
{
	int counter=0;
	Node<T>* n=head;
	while(n!=NULL)
	{
		if (elem!=n->elem)
		{
			counter+=1;
		}
		
		else {
			return counter;
			break;
			
		}
		n=n->next;
	}
	return -1;
}
//==============================================
// display all nodes of the linked list
template<typename T> void MyList<T>::display() const
{
	Node<T>* n=head;
	cout<<"Head->";
	while(n!=NULL)
	{
		
		cout<<n->elem<<"->";
		n=n->next;
	
	}
	cout<<"NULL"<<endl;
}
//====================================
// sort the elments of the list using bubble_sort
template<typename T> void MyList<T>::sort()
{
	Node<T>* n;
	Node<T>* m;
	int tmp;
	for (n=head;n!=NULL;n=n->next)
	{
		for (m=n->next;m!=NULL;m=m->next)
		{
			if (n->elem>m->elem)
			{
				tmp=m->elem;
				m->elem=n->elem;
				n->elem=tmp;

			}
		}
	}
	

	
	
}
//erases a node at a particular location
template<typename T> void MyList<T>::erase(T elem)
{
	Node<T>* tmp;
   if (head->elem==elem)
   {
	removeFront();
   }
   else
   {
	Node<T>* curr=head;
	while(curr->next!=NULL)
	{
		if(curr->next->elem==elem)
		{
          tmp=curr->next;
		  curr->next=curr->next->next;
		  delete tmp;
		  break;
		}
		else{
			curr=curr->next;
		}
	}
   }
}

//==================================================

