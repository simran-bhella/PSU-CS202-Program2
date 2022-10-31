#include "reservation.h"
#include "dll.h"

//Simranjit Bhella
//5/4/2022
//CS202
//The purpose of this file is to test the functionality of the program using the DLL and Reservation classes.
//In this code under main, this testing takes place through a dummy application with a user nav menu that allows for the
//tesing of different functions. For this program this includes adding Hotel, Food, and Event reservations,
//displaying these reservations, and displaying the master list.


int main() {

    int loop = 0;
    int menu = 0;
    Reservation r;
    DLL<Hotel> hlist;
    DLL<Food> flist;
    DLL<Event> elist;



    //Only thing untestable here are all operators except output, these were tested in the testing suite commented out below
    do {
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please choose an option below: " << endl;
        cout << "[1] Add Hotel Reservation" << endl;
        cout << "[2] Add Food Reservation" << endl;
        cout << "[3] Add Event Reservation" << endl;
        cout << "[4] Display Hotel Reservations" << endl;
        cout << "[5] Display Food Reservations" << endl;
        cout << "[6] Display Event Reservations" << endl;
        cout << "[7] Display Master List" << endl;
        cout << "[Anything Else] Quit the program" << endl << endl;
        cin >> menu;
        cin.ignore(100, '\n');

        //If the user wants to enter a Hotel Reservation
        if (menu == 1) {
            Hotel h;
            string date;
            string location;
            int time;
            string name;
            int room_number;

            cout << "Enter the Hotel name: ";
            cin >> name;

            cout << "Enter the location: ";
            cin >> location;

            cout << "Enter the reservation date: ";
            cin >> date;

            cout << "Enter the reservation time: ";
            cin >> time;

            cout << "Enter the room number: ";
            cin >> room_number;

            //Exception handeling to check for overlapping reservations
            try {
                r.add_to_list(name, date, time);
                h.create_reservation(date, location, time, name, room_number);

                hlist.insert(h);

            } catch (string dateandtime) {
                cout << "Warning: " << dateandtime << " already has a reservation!" << endl;
            }
        }

        //If the user wants to add a Food Reservation
        else if (menu == 2) {
            Food f;
            string date;
            string location;
            int time;
            string type;
            vector<string> dietary_restrictions;

            cout << "Enter the meal type: ";
            cin >> type;

            cout << "Enter the location: ";
            cin >> location;

            cout << "Enter the reservation date: ";
            cin >> date;

            cout << "Enter the reservation time: ";
            cin >> time;

            //While loop to fill vector
            int dietary_restrictions_loop = 1;

            while (dietary_restrictions_loop == 1) {
                string dietary_restriction;
                cout << "Enter dietary restriction: ";
                cin >> dietary_restriction;
                dietary_restrictions.push_back(dietary_restriction);

                cout << "Add another? 1 for Yes and 0 for No: ";
                cin >> dietary_restrictions_loop;
            }

            //Exception handeling to check for overlapping reservations
            try {
                r.add_to_list(type, date, time);
                f.create_reservation(date, location, time, type, dietary_restrictions);

                flist.insert(f);

            } catch (string dateandtime) {
                cout << "Warning: " << dateandtime << " already has a reservation!" << endl;
            }
        }

        //If the user wants to add an Event Reservation
        else if (menu == 3) {
            Event e;
            string date;
            string location;
            int time;
            string type;
            int length;

            cout << "Enter the Event: ";
            cin >> type;

            cout << "Enter the location: ";
            cin >> location;

            cout << "Enter the reservation date: ";
            cin >> date;

            cout << "Enter the reservation time: ";
            cin >> time;

            cout << "Enter the event length: ";
            cin >> length;

            //Exception handeling to check for overlapping reservations
            try {
                r.add_to_list(type, date, time);
                e.create_reservation(date, location, time, type, length);

                elist.insert(e);

            } catch (string dateandtime) {
                cout << "Warning: " << dateandtime << " already has a reservation!" << endl;
            }
        }

        //
        else if (menu == 4) {

            //Method for the following cout's:
            //Uses DLL class output operator which outputs one of the reservation subclass objects,
            // this causes the program to then use that subclass's output operator.
            cout << hlist;
        }

        //
        else if (menu == 5) {

            cout << flist;
        }

        //
        else if (menu == 6) {

            cout << elist;
        }

        //
        else if (menu == 7) {

            r.display_list();
        }

            //If anything else then change quite loop
        else {
            loop = 1;
        }
    } while (loop != 1);

    return 0;
}




//Old test suite
/*
    cout << "-- start --" << endl << endl;

    vector<string> dietary_restricitons;
    string foods[] {"apple", "yogurt", "bread"};

    for (string food: foods) {
        dietary_restricitons.push_back(food);
    }

    Reservation r;


    DLL<Hotel> hlist;
    Hotel h1;
    Hotel h2;
    try {
        r.add_to_list("Hotel1", "March 1", 1);
        h1.create_reservation("March 1", "Camas", 1, "Hotel1", 101);

        hlist.insert(h1);
        h2 = h1 + 1;
        hlist.insert(h2);

    } catch (string dateandtime) {

        cout << "Warning: " << dateandtime << " already has a reservation!" << endl;

    }
    cout << hlist;


    DLL<Food> flist;
    Food f;
    try {
        r.add_to_list("Breakfast", "March 2", 1);
        f.create_reservation("March 2", "Camas", 1, "Breakfast",dietary_restricitons);
        flist.insert(f);
        flist.insert(f);
    } catch (string dateandtime) {

        cout << "Warning: " << dateandtime << " already has a reservation!" << endl;

    }

    cout << flist;


    DLL<Event> elist;
    Event e;
    try {
        r.add_to_list("PAX", "March 3", 1);
        e.create_reservation("March 3", "Camas", 1, "PAX", 5);
        elist.insert(e);
        elist.insert(e);
    } catch (string dateandtime) {

        cout << "Warning: " << dateandtime << " already has a reservation!" << endl;

    }

    //Method for this: Uses DLL class output operator which outputs an event object, this causes the program to use the event class output operator
    cout << elist;


    r.display_list();

    if (h1 != h2) {
        puts("working");
    }
*/

