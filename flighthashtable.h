#ifndef FlightHASHTABLE_H
#define FlightHASHTABLE_H

#include<iostream>
#include "flightticket.h"
#include "myList.h"
// include additional header files as needed

using namespace std;

class HashNode
{
	private:
		string key; // key = companyName+','+flightNumber
		Flight_Ticket* value;
	public:
		HashNode(string key, Flight_Ticket* value)
		{
			this->key = key;
			this->value = value;
		}
		string getKey() { return this->key;}
		void print()
		{
		cout<<" Company Name: "<<HashNode(key,value).value->companyName<<endl;
		cout<<"  Flight Number: "<<HashNode(key,value).value->flightNumber<<endl;
		cout<<"  Country of origin: "<<HashNode(key,value).value->country_of_origin<<endl;
		cout<<"  Country of Destination: "<<HashNode(key,value).value->country_of_destination<<endl;
		cout<<"  Stopover: "<<HashNode(key,value).value->stopOver<<endl;
		cout<<"  Price: "<<HashNode(key,value).value->price<<endl;
		cout<<"  Time of Departure: "<<HashNode(key,value).value->time_of_departure<<endl;
		cout<<"  Time of Arrival: "<<HashNode(key,value).value->time_of_arrival<<endl;
		cout<<"  Date: "<<HashNode(key,value).value->date<<endl;
		}
		friend class FlightHASHTABLE;
};

//=============================================================================
class FlightHASHTABLE
{
	private:
		MyList<HashNode>* buckets;		//List of Buckets, Please create your own Linked List Class called MyList
		int size;					    //Current Size of HashTable
		int capacity;				    // Total Capacity of HashTable
		int collisions;
		// add more attributes as needed
	public:
		FlightHASHTABLE();						//constructor
		~FlightHASHTABLE();						//destructor
		long hashCode(string key); 				//implement and test different hash functions 
		int importCSV(string path); 			//Load all the flight-tickets from the CSV file to the HashTable
		int exportCSV(string path); 			//Export all the flight-tickets from the HashTable to a CSV file in an ascending order		
		int count_collisions();					//return the number of collisions in the HashTable
		int add(Flight_Ticket* data);			//add new flight to the HashTable
		void removeRecord (string companyName, string flightNumber);	//Delete a record with key from the hashtable
		void find(string companyName, string flightNumber);		//Find and Display records with same key entered 
		void allinday(string date);  					//Find and Display records with same day entered
		void printASC(string companyName, string flightNumber);  		//display the collisions for the entered key in an ascending order 
        int getCollision() { return this->collisions;}
		void setCollision(int s) {this->collisions=s;}
      
		// add more methods as needed	
};

#endif
