#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

 class Bus {
    int bus_id;
    char bus_number[30];
    int seats_capacity;
    char driver_name[50];
    char bus_available[10];   

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
        ofstream file("Bus.dat", ios::out | ios::app | ios::binary);

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
        ofstream file("Routes.dat", ios::out | ios::app | ios::binary);

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
        ifstream file("Routes.dat", ios::in | ios::binary);

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
//search route by id
    void searchRouteById() {
        ifstream file("Routes.dat", ios::in | ios::binary);

        if (!file) {
            cout << "No routes file found.\n";
            return;
        }

        int id;
        cout << "Enter Route ID to search: ";
        cin >> id;

        Route r;
        bool found = false;

        while (file.read((char*)&r, sizeof(r))) {
            if (r.route_id == id) {         // allowed: inside same class
                cout << "Route found:\n";
                r.showData();
                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "Route ID not found.\n";
        }
    }
//route updation
    void updateRouteRecord() {
        fstream file("Routes.dat", ios::in | ios::out | ios::binary);

        if (!file) {
            cout << "No routes file found.\n";
            return;
        }
        int id;
        cout << "Enter Route ID to update: ";
        cin >> id;

        Route r;
        bool found = false;

        // read each record
        while (file.read((char*)&r, sizeof(r))) {
            if (r.route_id == id) {
                cout << "\nExisting details:\n";
                r.showData();

                cout << "\nEnter new details for this route:\n";
                r.getData();   // will ask again for ID, starting, destination, distance

                // move the put pointer back one record
                file.seekp(-static_cast<int>(sizeof(r)), ios::cur);
                file.write((char*)&r, sizeof(r));

                cout << "Route updated successfully.\n";
                found = true;
                break;
            }
          }

        file.close();

        if (!found) {
            cout << "Route ID not found. No record updated.\n";
        }
    }

    //delete route
     void deleteRouteRecord() {
        ifstream in("Routes.dat", ios::in | ios::binary);

        if (!in) {
            cout << "No routes file found.\n";
            return;
        }

        ofstream out("Temp.dat", ios::out | ios::binary);

        int id;
        cout << "Enter Route ID to delete: ";
        cin >> id;

        Route r;
        bool deleted = false;

         while (in.read((char*)&r, sizeof(r))) {
            if (r.route_id == id) {
                cout << "Deleting this route:\n";
                r.showData();
                deleted = true;
                // skip writing this record (so it's deleted)
                continue;
            }
            out.write((char*)&r, sizeof(r));
        }

        in.close();
        out.close();

        if (!deleted) {
            cout << "Route ID not found. No record deleted.\n";
            remove("Temp.dat");   // cleanup temp
            return;
        }

        remove("Routes.dat");
        rename("Temp.dat", "Routes.dat");

        cout << "Route deleted successfully.\n";
    }
};

void routeOperations() {
    Route r;
    int choice;

    cout << "\n--- Route Operations ---\n";
    cout << "1. Add Route\n";
    cout << "2. View All Routes\n";
    cout << "3. Search Route by ID\n";
    cout << "4. Update Route by ID\n";
    cout << "5. Delete Route by ID\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            r.addRouteRecord();
            break;
        case 2:
            r.viewAllRoutes();
            break;
        case 3:
            r.searchRouteById();
            break;
        case 4:
            r.updateRouteRecord();
            break;
        case 5:
            r.deleteRouteRecord();
            break;
        default:
            cout << "Invalid Choice\n";
    }
}



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

    cout << "\n===== Bus Management System =====\n";

    cout << "1. Bus related operations\n";
    cout << "2. Route related operations\n";

    cout<<"Enter you choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            busOperations();
            break;
        case 2:
            routeOperations();
            break;
        default:
            cout << "Invalid choice\n";
    }
     
    return 0;
}
