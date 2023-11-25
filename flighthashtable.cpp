#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "flighthashtable.h"
#include "myList.h"
using namespace std;
FlightHASHTABLE::FlightHASHTABLE()//constructor
{
	this->capacity=122263;
    buckets = new MyList<HashNode>[capacity];
	this->size = 0;
	this->collisions = 0;
}
FlightHASHTABLE::~FlightHASHTABLE()//destructor
{

for (int k=0;k<capacity;k++)//traverses and removes flight tickets
{
	while(buckets[k].head!=NULL)
	{
		buckets[k].removeFront();
	}
}
delete [] buckets;
}
long FlightHASHTABLE::hashCode(string key)//hashfunction to generate a non colliding index number
{
   unsigned int ft=0;
   for (int i=0;i<key.length();i++)
   {
    ft=(ft<<5)|(ft>>27);
    ft+=(unsigned int)key[i];
   }
   int ind=(ft)%capacity;
   return ind;
}
int FlightHASHTABLE::importCSV(string path)//imports flight tickets
{
    int countter=0;
	ifstream fin;
	fin.open(path);
	if(!fin){
		cout<<"Can not open the file...!"<<endl;
		return -1;
	}
	string line;
	getline(fin,line);  //skip first line
	while(!fin.eof())
	{
		string companyName; string flightNumber; string country_of_origin; string country_of_destination; string stopOver; string price; string time_of_departure; string time_of_arrival; string date;
		getline(fin,companyName,',');
		getline(fin,flightNumber,',');
		getline(fin,country_of_origin,',');
		getline(fin,country_of_destination,',');
		getline(fin,stopOver,',');
		getline(fin,price,',');
		getline(fin,time_of_departure,',');
		getline(fin,time_of_arrival,',');
		getline(fin,date);
		Flight_Ticket* data=new Flight_Ticket(companyName,flightNumber,country_of_origin,country_of_destination,stopOver,price,time_of_departure,time_of_arrival,date);//creating a new flight object for each line
        add(data);//adding the created object to the hashtable
    countter++;	
	}
	fin.close();
return countter;
}
int FlightHASHTABLE::exportCSV(string path)//exports flight tickets
{
int counterr;
fstream myFile;
myFile.open(path,ios::out);
if (myFile.is_open())
{
	Node<HashNode>* z;

for (int i=0;i<capacity;i++)//displays the number of flights in a day
{
	        z=buckets[i].head;
			if (!buckets[i].empty())
			{
			while(z!=NULL)
			{
			
			myFile<<z->elem.value->companyName<<","<<z->elem.value->flightNumber<<","<<z->elem.value->country_of_origin<<","<<z->elem.value->country_of_destination<<","<<z->elem.value->stopOver<<","<<z->elem.value->price<<","<<z->elem.value->time_of_departure<<","<<z->elem.value->time_of_arrival<<","<<z->elem.value->date<<endl;
	        counterr++;
			z=z->next;
			}
			}
	
}
}
myFile.close();
return counterr;
}
int FlightHASHTABLE::count_collisions()//counts the number of collisions in the hashtable
{
return collisions;
}
int FlightHASHTABLE::add(Flight_Ticket* data)//adds flight ticket object to the hashtable
{
	    int r;
        string fn=data->flightNumber;
        string key=data->companyName+","+fn;
		for (int q=0; q<key.length(); q++)//changes the key to lower case
           {tolower(key[q]);}


        int hashValue=hashCode(key);
        bool keyexist=false;
		if (buckets[hashValue].empty())//if the hash node is empty just add it to the front
			{
			  buckets[hashValue].addFront(HashNode(key,data));
			  r=1;
			}
	   else{
		Node<HashNode>* tmp=buckets[hashValue].head;
		while(tmp!=NULL)
		{
			if(tmp->elem.key==key)//if the key is the same
			{
			if ((tmp->elem.value->companyName==data->companyName)&&(tmp->elem.value->country_of_destination==data->country_of_destination)&&(tmp->elem.value->country_of_origin==data->country_of_origin)&&(tmp->elem.value->date==data->date)&&(tmp->elem.value->flightNumber==data->flightNumber)&&(tmp->elem.value->price==data->price)&&(tmp->elem.value->stopOver==data->stopOver)&&(tmp->elem.value->time_of_arrival==data->time_of_arrival)&&(tmp->elem.value->time_of_departure==data->time_of_departure)) //if entry has the same key and value as the existing hashnode
			{
             r=-1;
			}
			else//if the key is the same but has a different value
			{
				buckets[hashValue].addFront(HashNode(key,data));
				r=1;
			}
			keyexist=true;
			break;
			}
			else{
				tmp=tmp->next;
			}
	     }

		if (keyexist==false)//if the entry has a different key than the existing hashnodes
		{
			buckets[hashValue].addFront(HashNode(key,data));
			r=1;
			collisions++;
		}
		}
		size++;
	return r;
}
void FlightHASHTABLE::removeRecord (string companyName, string flightNumber)//removes a flight ticket with a given key
{   Node<HashNode>* tmp;
    string key=companyName+","+flightNumber;
    for (int q=0; q<key.length(); q++)//changes the key to lower case
           {tolower(key[q]);}

	int hashValue=hashCode(key);
	int j=0;
	int reco=0;
	Node<HashNode>* n=buckets[hashValue].head;
	while(n!=NULL)//counts the number of records with the same key
	{
		if(n->elem.key==key)
		{
         reco++;
		}
		
		n=n->next;
	
	}
	n=buckets[hashValue].head;
	cout<<reco<<" records found:"<<endl;
	while(n!=NULL)//prints out the values with the given key
	{ 

		
		if(n->elem.key==key)
		{
		j++;
		cout<<"  "<<j<<".";
		n->elem.print();
		}
		n=n->next;
	
	}	
	cout<<endl;
	int r;
	cout<<"Please select the record you want to delete: ";
	cin>>r;
	int u=0;
	n=buckets[hashValue].head;
	if (buckets[hashValue].head->elem.key==key)//if the hashnode to be removed is the head
	{
		buckets[hashValue].removeFront();
		cout<<"The flight-ticket has been successfully deleted!"<<endl;
	}
   else{
	while(n!=NULL) //if the hashnode to be removed is not the head
	{ 
		if(n->elem.key==key)
		{
		u++;
		if (r==u-1)
		{
			
			tmp=n->next;
			n->next=n->next->next;
			delete tmp;
			break;
		}
		}
		n=n->next;
	
	}
	cout<<"The flight-ticket has been successfully deleted!"<<endl;
   }	
}
void FlightHASHTABLE::find(string companyName, string flightNumber)//finds a flight ticket with a given key
{
    string key=companyName+","+flightNumber;
	for (int q=0; q<key.length(); q++)//changes the key to lower case
           {tolower(key[q]);}
	int hashValue=hashCode(key);
	int j=0;
	int reco=0;
	Node<HashNode>* n=buckets[hashValue].head;
	while(n!=NULL)//counting records with the same key
	{
		if(n->elem.key==key)
		{
         reco++;
		}
		
		n=n->next;
	
	}
	if (reco==0)
	{
		cout<<"Not Found!"<<endl;
	}
	else{
	n=buckets[hashValue].head;
	cout<<reco<<" records found:"<<endl;
	while(n!=NULL)//displays records with the same key
	{ 

		if(n->elem.key==key)
		{
		j++;
		cout<<"  "<<j<<".";
		n->elem.print();
		}
		n=n->next;
	
	}	
	}
		
	
}
void FlightHASHTABLE::allinday(string date)//prints out flights in the sameday
{
Node<HashNode>* r;
Node<HashNode>* o;
int coun=0;
int b=0;

for (int k=0;k<capacity;k++)//counts the number of flights in a day
{
	for (o=buckets[k].head;o!=NULL;o=o->next)
	{
		if (o->elem.value->date==date)
		{
			coun++;
		}
	}
}
cout<<coun<<" records found:"<<endl;


for (int i=0;i<capacity;i++)//displays the number of flights in a day
{
	
	for (r=buckets[i].head;r!=NULL;r=r->next)
	{   
		if (r->elem.value->date==date)
		{   
			cout<<r->elem.value->companyName<<","<<r->elem.value->flightNumber<<","<<r->elem.value->country_of_origin<<","<<r->elem.value->country_of_destination<<","<<r->elem.value->stopOver<<","<<r->elem.value->price<<","<<r->elem.value->time_of_departure<<","<<r->elem.value->time_of_arrival<<","<<r->elem.value->date<<endl;
		}

	}
}
}
void FlightHASHTABLE::printASC(string companyName, string flightNumber)//prints out flights with the same key in ascending order of their country of destination
{
    string key=companyName+","+flightNumber;
	for (int q=0; q<key.length(); q++)//changes the key to lower case
           {tolower(key[q]);}
	int hashValue=hashCode(key);
	Node<HashNode>* n;
	Node<HashNode>* m;
	Node<HashNode>* z;
	for (n=buckets[hashValue].head;n!=NULL;n=n->next)//bubble sort to sort the flights in ascending order of their country of destination
	{
		for (m=n->next;m!=NULL;m=m->next)
		{
		 
			if ((n->elem.value->country_of_destination > m->elem.value->country_of_destination)&&(m->elem.key==n->elem.key))
			{    
				Flight_Ticket tmp=*(m->elem.value);
				
                m->elem.value->companyName=n->elem.value->companyName;
				m->elem.value->country_of_destination=n->elem.value->country_of_destination;
                m->elem.value->country_of_origin=n->elem.value->country_of_origin;
				m->elem.value->date=n->elem.value->date;
				m->elem.value->flightNumber=n->elem.value->flightNumber;
				m->elem.value->price=n->elem.value->price;
				m->elem.value->stopOver=n->elem.value->stopOver;
				m->elem.value->time_of_arrival=n->elem.value->time_of_arrival;
				m->elem.value->time_of_departure=n->elem.value->time_of_departure;
    

				n->elem.value->companyName=(tmp).companyName;
				n->elem.value->country_of_destination=(tmp).country_of_destination;
                n->elem.value->country_of_origin=(tmp).country_of_origin;
				n->elem.value->date=(tmp).date;
				n->elem.value->flightNumber=(tmp).flightNumber;
				n->elem.value->price=(tmp).price;
			    n->elem.value->stopOver=(tmp).stopOver;
				n->elem.value->time_of_arrival=(tmp).time_of_arrival;
				n->elem.value->time_of_departure=(tmp).time_of_departure;
        

			}
		}
	}

for (z=buckets[hashValue].head;z!=NULL;z=z->next)//displays the result the sorted
{
	if (z->elem.key==key)
	{
		cout<<z->elem.value->companyName<<","<<z->elem.value->flightNumber<<","<<z->elem.value->country_of_origin<<","<<z->elem.value->country_of_destination<<","<<z->elem.value->stopOver<<","<<z->elem.value->price<<","<<","<<z->elem.value->time_of_departure<<","<<z->elem.value->time_of_arrival<<","<<z->elem.value->date<<endl;
	}

}

}