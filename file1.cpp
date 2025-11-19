#include <iostream>
using namespace std;

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

      void getdata(){
          cout << "Enter Bus Id: ";
          cin >> bus_id;
          cout << "The bus number is: ";
          cin >> bus_number;
          cout << "The bus capacity is: ";
          cin >> seats_capacity;
          cout << "The seat availability is: ";
          cin >> seats_availability;
          cout << "The driver name is: ";
          cin >> driver_name;
          cout << "The route is: ";
          cin >> route;
      }
};

class Route{
     int route_id;
     string starting;
     string destination;
     double distance;
};

class Passengers{
     int Passenger_id;
     string Passenger_name;
     string mobile;
     string bus_name;
};

int main(){
     return 0;
}