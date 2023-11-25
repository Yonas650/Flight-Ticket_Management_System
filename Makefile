myFlightHASHTABLE: main.o myList.o flighthashtable.o flightticket.o
	g++  main.o myList.o flighthashtable.o flightticket.o -o myFlightHASHTABLE
main.o: main.cpp
	g++ -c main.cpp
myList.o: myList.cpp myList.h
	g++ -c myList.cpp
flighthashtable.o: flighthashtable.cpp flighthashtable.h
	g++ -c flighthashtable.cpp
flightticket.o: flightticket.cpp flightticket.h
	g++ -c flightticket.cpp
clean:
	rm *.o myFlightHASHTABLE