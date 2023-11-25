#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "flightticket.h"
Flight_Ticket::Flight_Ticket(string companyName, string flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date)//constructor of the flightticket class
{
   this->companyName=companyName;
    this->flightNumber=flightNumber;
    this->country_of_origin=country_of_origin;
    this->country_of_destination=country_of_destination;
    this->stopOver=stopOver;
    this->price=price;
    this->time_of_departure=time_of_departure;
    this->time_of_arrival=time_of_arrival;
    this->date=date;
}

