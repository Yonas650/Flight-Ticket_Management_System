
//================================================================================
// Author       : Yonas Atinafu
// Version      : 1.0
// Date Created : 22-Nov-2022
// Date Modified: 
// Description  : Starter Code for Flight-Ticket Management System using HASH TABLE in C++
//=================================================================================
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <regex>
#include "myList.h"
#include "flightticket.h"
#include "flighthashtable.h"
using namespace std;
//==========================================================
void listCommands()
{
	cout<<"\n----------------------------------"<<endl;
	cout<<"import <path>      	:Import flight-tickets from a CSV file"<<endl
		<<"export <path>      	:Export flight-tickets to a CSV file"<<endl
		<<"count_collisions   	:Print number of collisions"<<endl
		<<"add                	:Add a new flight-ticket"<<endl
		<<"delete <key>       	:Delete a flight-ticket"<<endl
		<<"find <key>         	:Find a flight-ticket's details"<<endl
		<<"allinday <date>    	:Display all flight-tickets in a day"<<endl
		<<"printASC <key>     	:Print flight-tickets in ascending order"<<endl
		<<"exit               	:Exit the program"<<endl;
}
//==========================================================

// to be completed with any necessary method definitions

//==========================================================
int main(void)
{
	FlightHASHTABLE myFlightHASHTABLE;
    listCommands();
	string user_input;
	string command;
	string key;
	while(true)
	{
	cout<<">";
		getline(cin,user_input);
		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,key);

		if(command == "add")
		{
		string companyName; string flightNumber; string country_of_origin; string country_of_destination; string stopOver; string price; string time_of_departure; string time_of_arrival; string date;
		 cout<<"Please enter the details of the flight-ticket: "<<endl; //collects user input
         cout<<"Company Name: "; //company name
         getline(cin,companyName);
		 const regex compsample("[a-zA-Z]+");
		 while (!regex_match(companyName,compsample))
		 {
			cout<<"Please enter a valid company name again: ";
			getline(cin,companyName);
		 }
         cout<<"Flight Number: ";   //flight number
         getline(cin,flightNumber);
		 const regex flinumsample("[0-9]+");
		while (!regex_match(flightNumber,flinumsample))
		 {
			cout<<"Please enter a valid flight number again: ";
			cin>>flightNumber;
		 }
		 cout<<"Country of Origin: "; //country of origin
         getline(cin,country_of_origin);
		 const regex counosample("[a-zA-Z]+");
		 while (!regex_match(country_of_origin,counosample))
		 {
			cout<<"Please enter a valid country of origin again: ";
			getline(cin,country_of_origin);
		 }
		 cout<<"Country of destination: "; //country of destination
         getline(cin,country_of_destination);
		 const regex coundsample("[a-zA-Z]+");
		 while (!regex_match(country_of_destination,coundsample))
		 {
			cout<<"Please enter a valid country again: ";
			getline(cin,country_of_destination);
		 }
		 cout<<"Stop over: "; //stop over
         getline(cin,stopOver);
		 const regex stopsample("[a-zA-Z]+");
		 while (!regex_match(stopOver,stopsample))
		 {
			cout<<"Please enter a valid stop over again: ";
			getline(cin,stopOver);
		 }
		 cout<<"Price: "; //price
         getline(cin,price);
		 const regex pricesample("[0-9]+");
		 while (!regex_match(price,pricesample))
		 {
			cout<<"Please enter a valid price again: ";
			getline(cin,price);
		 }
		 cout<<"Time of departure: "; //time of departure
         getline(cin,time_of_departure);
		 const regex todsample("([01]?[0-9]|2[0-3]):[0-5][0-9]");
		 while (!regex_match(time_of_departure,todsample))
		 {
			cout<<"Please enter a valid time again: ";
			getline(cin,time_of_departure);
		 }
         cout<<"Time of arrival: "; //time of arrival
         getline(cin,time_of_arrival);
		 const regex toasample("([01]?[0-9]|2[0-3]):[0-5][0-9]");
		 while (!regex_match(time_of_arrival,toasample))
		 {
			cout<<"Please enter a valid time again: ";
			getline(cin,time_of_arrival);
		 }
         cout<<"Date: "; //date
         getline(cin,date);
		 const regex dsample("[0-9][a-zA-Z]+|[0-9][0-9][a-zA-Z]+|");//
		 while (!regex_match(date,dsample))
		 {
			cout<<"Please enter a valid date again: ";
			getline(cin,date);
		 }
		 Flight_Ticket* data=new Flight_Ticket(companyName,flightNumber,country_of_origin,country_of_destination,stopOver,price,time_of_departure,time_of_arrival,date);
		 int z;
		 z=myFlightHASHTABLE.add(data);
		 if (z==1)
		 {
			cout<<"Flight-ticket has been successfully added!!"<<endl;
		 }
		 else if(z==-1)
		 {
			cout<<"Warning! Flight-ticket already exists in the system!"<<endl;
		 }


		}
		else if(command == "find")
		{
		 string  arr[2];
		 int i=0;
		 stringstream st(key);
		 while(st.good())
		 {
			string ns;
			getline(st,ns,',');
			arr[i++]=ns;
		 }
		 clock_t yt;//Calculates the time taken
		 yt = clock();
		  myFlightHASHTABLE.find(arr[0],arr[1]);
		  yt = clock() - yt;
		  double tt = ((double)yt)/CLOCKS_PER_SEC;
          cout<<"Time taken: "<<tt<<" seconds"<<endl;
		}
		else if(command == "delete")	 
		{
	      string  arr[2];
		 int i=0;
		 stringstream st(key);
		 while(st.good())
		 {
			string ns;
			getline(st,ns,',');
			arr[i++]=ns;
		 }
		 myFlightHASHTABLE.removeRecord(arr[0],arr[1]);
		 fflush(stdin);
		}
		else if( command =="import" or command=="im")//comand to import
		
		{ 
			int l;
			l=myFlightHASHTABLE.importCSV(key);
			cout<<l<<endl;
			
		}
		else if( command =="export" or command=="ex")//comand to import
		
		{ 
			int m;
			m=myFlightHASHTABLE.exportCSV(key);
			cout<<m<<endl;
		}	
		else if( command =="printASC" or command=="pa")	//command for the printASC method
		{ 
			string  arr[2];
		 int i=0;
		 stringstream st(key);
		 while(st.good())
		 {
			string ns;
			getline(st,ns,',');
			arr[i++]=ns;
		 }
		 myFlightHASHTABLE.printASC(arr[0],arr[1]);
		 fflush(stdin);
		} 
		else if (command=="allinday")//command for allinday
		{
			myFlightHASHTABLE.allinday(key);
		}
		else if (command=="count_collisions" or command=="cc")//command for count_colissions
		{
			int u;
			u=myFlightHASHTABLE.count_collisions();
			cout<<"Total number of collisions is "<<u<<endl;
			myFlightHASHTABLE.setCollision(0);
		}
		else if( command == "help") listCommands();//comman for displaying list of commands
		else if( command =="exit" or command =="quit" or command =="q") break;
		else cout<<"Invalid command !!!"<<endl;

	}

	return 0;
}
