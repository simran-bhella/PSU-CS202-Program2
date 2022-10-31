#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <exception>
#include "dll.h"
using namespace std;

//Simranjit Bhella
//4/29/2022
//CS202
//The purpose of this code is to set up hierarchy of reservation classes for the reservation management program.
//This file includes the reservation base class with the hotel, food, and event subclasses.
//The reservation class has base data and a master list of reservations.
//The hotel, food, and event subclasses all have additional data as well as a create reservation function.
//The subclasses also all have operator overloading, with the most important being the output operator allowing seamless display
//with the template based DLL.





//Reservation base class
class Reservation {
public:
    Reservation(); //constructor
    void add_to_list(string name, string date, int time); //Add reservation to master list
    void display_list(); //Display master list

protected:
    string location;
    int time;
    string date;

    map<string, string> reservation_list; //STL map list of all reservations with their dates and times



};

//Hotel subclass from reservation
class Hotel : public Reservation {
public:
    Hotel(); //constructor
    Hotel(const Hotel &copy); //copy constructor
    void create_reservation(string date, string location, int time, string name, int room_number); //Create hotel reservation

    //Overloaded Operators
    friend ostream & operator << (ostream & out, const Hotel & h);
    Hotel operator+ (const int i);
    Hotel operator+= (const int i);
    Hotel operator- (const int i);
    Hotel operator-= (const int i);
    bool operator== (const Hotel & h) const;
    bool operator!= (const Hotel & h) const;
    bool operator< (const Hotel & h) const;
    bool operator<= (const Hotel & h) const;
    bool operator> (const Hotel & h) const;
    bool operator>= (const Hotel & h) const;

protected:
    string name;
    int room_number;
};

class Food : public Reservation {
public:
    Food(); //constructor
    Food(const Food &copy); //copy constructor
    void create_reservation(string date, string location, int time, string type, vector<string> dietary_restrictions); //Create food reservation

    //Overloaded Operators
    friend ostream &operator<<(ostream &, const Food & f);
    Food operator+ (const int i);
    Food operator+= (const int i);
    Food operator- (const int i);
    Food operator-= (const int i);
    bool operator== (const Food & f) const;
    bool operator!= (const Food & f) const;
    bool operator< (const Food & f) const;
    bool operator<= (const Food & f) const;
    bool operator> (const Food & f) const;
    bool operator>= (const Food & f) const;


protected:
    string type;
    vector<string> dietary_restrictions; //STL vector list for dietary restrictions
};

class Event : public Reservation {
public:
    Event(); //constructor
    Event(const Event &copy); //copy constructor
    void create_reservation(string date, string location, int time, string type, int event_length); //create event reservation

    //Overloaded Operators
    friend ostream & operator<< (ostream & out, const Event & e);
    Event operator+ (const int i);
    Event operator+= (const int i);
    Event operator- (const int i);
    Event operator-= (const int i);
    bool operator== (const Event & e) const;
    bool operator!= (const Event & e) const;
    bool operator< (const Event & e) const;
    bool operator<= (const Event & e) const;
    bool operator> (const Event & e) const;
    bool operator>= (const Event & e) const;

protected:
    string type;
    int event_length;
};
