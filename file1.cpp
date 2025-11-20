#include <iostream>
#include <fstream>
using namespace std;

<<<<<<< HEAD
class Bus{
     int bus_id;
     string bus_number;
     int seats_capacity; 
     int seats_availability;
     string driver_name;
     string route; 

public:

     Bus(int id, string bus_num, int capacity, int availability, string dri_name, string rout){
          bus_id = id;
          bus_number = bus_num;
          seats_capacity = capacity;
          seats_availability = availability;
          driver_name = dri_name;
          route = rout;
      }
=======
 class Bus {
    int bus_id;
    char bus_number[30];
    int seats_capacity;
    char driver_name[50];
    char bus_available[10];   
>>>>>>> 3dc2313b1e034a03a14c64e9623cbc16c48116bd

  public:

    void getData() {
        cout << "Enter Bus ID: ";
        cin >> bus_id;

        cout << "Enter Bus Number: ";
        cin >> bus_number;

        cout << "Enter Seat Capacity: ";
        cin >> seats_capacity;

        cout << "Enter Driver Name: ";
        cin >> driver_name;

        cout << "Enter Bus Availability (Yes/No): ";
        cin >> bus_available;
    }

    void showData() {
        cout << "Bus ID: " << bus_id << endl;
        cout << "Bus Number: " << bus_number << endl;
        cout << "Seat Capacity: " << seats_capacity << endl;
        cout << "Driver Name: " << driver_name << endl;
        cout << "Bus Availability: " << bus_available << endl;
    }

    void addBusRecord() {
        fstream file("Bus.dat", ios::out | ios::app | ios::binary);

        if (!file) {
            cout << "Failed to open file\n";
            return;
        }

        getData();  
        file.write((char*)this, sizeof(*this));   

        file.close();

        cout << "Record added successfully.\n";
    }

    void viewAll() {
        fstream file("Bus.dat", ios::in | ios::binary);

        if (!file) {
            cout << "No file found.\n";
            return;
        }

        Bus temp;

        bool found = false;

        while (file.read((char*)&temp, sizeof(temp))) {
          found=true;
            temp.showData();
            cout << "------------------------------\n";
        }

        file.close();

        if(!found)
          cout<<"No Record found\n";
    }
};

class Route {
    int route_id;
    char starting[30];
    char destination[30];
    double distance;

 public:

    void getData() {
        cout << "Enter Route ID: ";
        cin >> route_id;
        cout << "Enter Starting Point: ";
        cin >> starting;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Distance (km): ";
        cin >> distance;
    }

    void showData() {
        cout << "Route ID: " << route_id << endl;
        cout << "Starting Point: " << starting << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << " km" << endl;
    }

    void addRouteRecord() {
        fstream file("Routes.dat", ios::out | ios::app | ios::binary);

        if (!file) {
            cout << "Failed to open file." << endl;
            return;
        }

        getData();
        file.write((char*)this, sizeof(*this));
        file.close();

        cout << "Route added successfully.\n";
    }

    void viewAllRoutes() {
        fstream file("Routes.dat", ios::in | ios::binary);

        if (!file) {
            cout << "No routes file found.\n";
            return;
        }

        Route r;

        while (file.read((char*)&r, sizeof(r))) {
            r.showData();
            cout << "------------------------\n";
        }

        file.close();
    }
};



class Passenger {
    int passenger_id;
    char passenger_name[50];

 public:

    void getData() {
        cout << "Enter Passenger ID: ";
        cin >> passenger_id;
        cout << "Enter Passenger Name: ";
        cin >> passenger_name;
    }

    void showData() {
        cout << "Passenger ID: " << passenger_id << endl;
        cout << "Passenger Name: " << passenger_name << endl;
    }

    void addPassengerRecord() {
        fstream file("Passengers.dat", ios::out | ios::app | ios::binary);

        if (!file) {
            cout << "Failed to open file.\n";
            return;
        }

        getData();
        file.write((char*)this, sizeof(*this));
        file.close();

        cout << "Passenger added successfully.\n";
    }

    void viewAllPassengers() {
        fstream file("Passengers.dat", ios::in | ios::binary);

        if (!file) {
            cout << "No passengers file found.\n";
            return;
        }

        Passenger p;

        while (file.read((char*)&p, sizeof(p))) {
            p.showData();
            cout << "------------------------\n";
        }

        file.close();
    }
};

class Schedule {
    int schedule_id;
    int route_id;
    int seats_available;
    char sc_date[20];
    char sc_time[20];

 public:

    void getData() {
        cout << "Enter Schedule ID: ";
        cin >> schedule_id;

        cout << "Enter Route ID: ";
        cin >> route_id;

        cout << "Enter Seats Available: ";
        cin >> seats_available;

        cout << "Enter Schedule Date: ";
        cin >> sc_date;

        cout << "Enter Schedule Time: ";
        cin >> sc_time;
    }

    void showData() {
        cout << "Schedule ID: " << schedule_id << endl;
        cout << "Route ID: " << route_id << endl;
        cout << "Seats Available: " << seats_available << endl;
        cout << "Schedule Date: " << sc_date << endl;
        cout << "Schedule Time: " << sc_time << endl;
    }

    void addScheduleRecord() {
        fstream file("Schedules.dat", ios::out | ios::app | ios::binary);

        if (!file) {
            cout << "Failed to open file.\n";
            return;
        }

        getData();
        file.write((char*)this, sizeof(*this));
        file.close();

        cout << "Schedule added successfully.\n";
    }

    void viewAllSchedules() {
        fstream file("Schedules.dat", ios::in | ios::binary);

        if (!file) {
            cout << "No schedules file found.\n";
            return;
        }

        Schedule s;

        while (file.read((char*)&s, sizeof(s))) {
            s.showData();
            cout << "------------------------\n";
        }

        file.close();
    }
};


void busOperations(){
  Bus b;
  int choice;
  cout<<"Enter 1 for register the bus\n";
  cout<<"Enter 2 for showing add the bus\n";
  cout<<"Enter your choise: ";
  cin>>choice;

  switch(choice){
    case 1:
       b.addBusRecord();
       break;
    case 2:
       b.viewAll();
       break;
    default:
      cout<<"invalid Choice";
  }
  


}






int main(){
    int choice;

    cout<<"Enter 1 for bus related operation\n";

    cout<<"Enter you choice: ";
    cin>>choice;

    switch(choice){
        case 1:
          busOperations();
    }



     return 0;
}
