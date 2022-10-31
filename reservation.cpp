#include "reservation.h"
#include "dll.h"

//Simranjit Bhella
//4/29/2022
//CS202
//The purpose of this file is to implement the functions from the classes in the reservation.h file.
//Functions include constructors, copy connstructors, create reservation functions, add to master list,
//display master list, assignment operators, relational operators, and output operators.

//constructor
Reservation::Reservation() {}

//constructor
Hotel::Hotel() {}

//constructor
Food::Food() {}

//constructor
Event::Event() {}

//Add reservation to master list given name, date, and time
void Reservation::add_to_list(string name, string date, int time) {

    //combine date and time into string
    string dateandtime = date + " at " + to_string(time);

    //Exception handling to check if reservation date and time are already booked
     for (auto itr = reservation_list.find(dateandtime); itr != reservation_list.end(); itr++) {
            throw(dateandtime);
        }

     //Add to list
    reservation_list[dateandtime] = name;
}

//Display master list
void Reservation::display_list() {

    //Iterate through list to display
    for (auto &item: reservation_list) {
        cout << item.second << ": " << item.first << endl;
    }

    cout << endl;
}

//Hotel copy constructor
Hotel::Hotel(const Hotel &obj) {
    date = obj.date;
    time = obj.time;
    location = obj.location;
    name = obj.name;
    room_number = obj.room_number;

}

//Create hotel reservation function
void Hotel::create_reservation(string date, string location, int time, string name, int room_number) {

    this->date = date;
    this->location = location;
    this->time = time;
    this->name = name;
    this->room_number = room_number;

}

//Overloaded output operator
ostream & operator<<(ostream &os, const Hotel &h) {
    os << "Hotel name: " << h.name << endl << "Hotel location: " << h.location << endl << "Reservation date: " << h.date
       << endl << "Reservation time: " << h.time << endl << "Room number: " << h.room_number << endl << endl;
    return os;
}

//Assignment operators for hotel:
Hotel Hotel::operator+ (const int i) {

    Hotel copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Hotel Hotel::operator+= (const int i) {

    Hotel copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Hotel Hotel::operator- (const int i) {

    Hotel copy(*this);
    copy.time -= i;

    if (time < 0) {

        copy.time = 0;

    }

    return copy;
}

//Relational Operators for hotel:
bool Hotel::operator==(const Hotel &op2) const {

    if (this->time == op2.time) {
        return true;
    }

    return false;
}

bool Hotel::operator!=(const Hotel &op2) const {

    if (this->time == op2.time) {
        return false;
    }

    return true;
}

bool Hotel::operator<(const Hotel &op2) const {

    if (this->time < op2.time) {
        return true;
    }

    return false;
}

bool Hotel::operator<=(const Hotel &op2) const {

    if (this->time <= op2.time) {
        return true;
    }

    return false;
}

bool Hotel::operator>(const Hotel &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

bool Hotel::operator>=(const Hotel &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

//Food copy constructor
Food::Food(const Food &obj) {
    date = obj.date;
    time = obj.time;
    location = obj.location;
    type = obj.type;
    dietary_restrictions = obj.dietary_restrictions;
}


//Create food reservation function
void Food::create_reservation(string date, string location, int time, string type, vector<string> dietary_restrictions ) {

    this->date = date;
    this->location = location;
    this->time = time;
    this->type = type;
    this->dietary_restrictions = dietary_restrictions;

}

//Overloaded output operator
ostream & operator<<(ostream &os, const Food &f) {
    os << "Reservation Type: " << f.type << endl << "Restaurant location: " << f.location << endl << "Reservation date: " << f.date
       << endl << "Reservation time: " << f.time << endl << "Dietary Restrictions: ";

    //Loop for vector, adding each entry to the output.
    for (string dietary_restriction: f.dietary_restrictions) {
        os << dietary_restriction << ", ";
    }

    os << endl << endl;

    return os;
}

//Assignment operators:
Food Food::operator+ (const int i) {

    Food copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Food Food::operator+= (const int i) {

    Food copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Food Food::operator- (const int i) {

    Food copy(*this);
    copy.time -= i;

    if (time < 0) {
        copy.time = 0;
    }

    return copy;
}

Food Food::operator-= (const int i) {

    Food copy(*this);
    copy.time += i;

    if (time > 2400) {
        copy.time = 0;
    }

    return copy;
}

//Relational operators:
bool Food::operator==(const Food &op2) const {

    if (this->time == op2.time) {
        return true;
    }

    return false;
}

bool Food::operator!=(const Food &op2) const {

    if (this->time == op2.time) {
        return false;
    }

    return true;
}

bool Food::operator<(const Food &op2) const {

    if (this->time < op2.time) {
        return true;
    }

    return false;
}

bool Food::operator<=(const Food &op2) const {

    if (this->time <= op2.time) {
        return true;
    }

    return false;
}

bool Food::operator>(const Food &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

bool Food::operator>=(const Food &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

//Event copy constructor
Event::Event(const Event &obj) {

    date = obj.date;
    time = obj.time;
    location = obj.location;
    type = obj.type;
    event_length = obj.event_length;
}

//Create event reservation
void Event::create_reservation(string date, string location, int time, string type, int event_length) {

    this->date = date;
    this->location = location;
    this->time = time;
    this->type = type;
    this->event_length = event_length;
}

//Overloaded output operator
ostream & operator<<(ostream &os, const Event &e) {
    os << "Event Type: " << e.type << endl << "Event location: " << e.location << endl << "Reservation date: " << e.date
       << endl << "Reservation time: " << e.time << endl << "Event Length: " << e.event_length << " Hours" << endl << endl;
    return os;
}

//Assignment operators:
Event Event::operator+(const int i) {

    Event copy(*this);
    copy.time += i;

    if (time > 2400) {
        copy.time = 0;
    }

    return copy;
}

Event Event::operator+= (const int i) {

    Event copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Event Event::operator-(const int i) {

    Event copy(*this);
    copy.time -= i;

    if (time < 0) {

        copy.time = 0;

    }


    return copy;
}

Event Event::operator-=(const int i) {

    Event copy(*this);
    copy.time -= i;

    if (time < 0) {
        copy.time = 0;
    }

    return copy;
}

//Relational Operators:
bool Event::operator==(const Event &op2) const {

    if (this->time == op2.time) {
        return true;
    }

    return false;
}

bool Event::operator!=(const Event &op2) const {

    if (this->time == op2.time) {
        return false;
    }

    return true;
}

bool Event::operator<(const Event &op2) const {

    if (this->time < op2.time) {
        return true;
    }

    return false;
}

bool Event::operator<=(const Event &op2) const {

    if (this->time <= op2.time) {
        return true;
    }

    return false;
}

bool Event::operator>(const Event &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

bool Event::operator>=(const Event &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}