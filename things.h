/*
#ifndef VIR_T_THINGS_H
#define VIR_T_THINGS_H

#include <iostream>

using namespace std;

class Food {
public:
    Food(const string);
    friend ostream &operator<<(ostream &, const Food &);
private:
    string name;
};

class Event {
public:
    Event(const string, int);
    friend ostream &operator<<(ostream &, const Event &);
private:
    string name;
    int data;
};

#endif //VIR_T_THINGS_H
*/