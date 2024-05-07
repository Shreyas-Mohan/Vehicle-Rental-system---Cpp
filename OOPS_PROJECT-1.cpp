#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int generaterandom()
{
    srand(time(0));
    int random_variable = rand() % 900000 + 100000;
    return random_variable;
}

class Vehicle
{
public:
    string type;
    string regis_num;
    string model;
    int seats;
    int rate_per_km;
};

class User
{
public:
    string name;
    string contact;
};

class Trip
{
public:
    int id;
    User user;
    Vehicle vehicle;
    int startOdometer;
    int endOdometer;
    double fare;
    int days;
};

class VehicleRentalSystem
{
private:
    vector<Vehicle> vehicles;
    vector<User> users;
    vector<Trip> trips;

public:
    void operatorMenu();
    void addNewVehicle();
    void viewVehicleDetails();
    void editVehicleDetails();
    void addNewUser();
    void addNewTrip();
    void viewTrip();
    void startTrip();
    void completeTrip();
};

void VehicleRentalSystem::operatorMenu()
{

    int choice;
    while (true)
    {
        int option;

        cout << "\n1.Edit Vehicles\n"
             << "2.Rent Vehicles \n";
        cout << "Enter Choice :";
        cin >> option;

        if (option == 1)
        {
            cout << "\n10. Add new vehicle\n";
            cout << "11. View vehicle details\n";
            cout << "12. Edit vehicle details\n";
            cout << "\nChoose an Option:\n";
            cin >> choice;
            cin.ignore();
        }

        else if (option == 2)
        {

            cout << "\n21. Add new user\n";
            cout << "22. Add new trip\n";
            cout << "23. View trip\n";
            cout << "24. Start trip\n";
            cout << "25. Complete trip\n";
            cout << "26. Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
        }

        switch (choice)
        {
        case 10:
            addNewVehicle();
            break;
        case 11:
            viewVehicleDetails();
            break;
        case 12:
            editVehicleDetails();
            break;
        case 21:
            addNewUser();
            break;
        case 22:
            addNewTrip();
            break;
        case 23:
            viewTrip();
            break;
        case 24:
            startTrip();
            break;
        case 25:
            completeTrip();
            break;
        case 26:
            cout << "Exiting the system. Goodbye!\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void VehicleRentalSystem::addNewVehicle()
{
    Vehicle newVehicle;
    cout << "***************Adding new Vehicle***************\n";
    cout << "Enter vehicle type: ";
    cin >> newVehicle.type;
    cout << "Enter vehicle registration number: ";
    cin >> newVehicle.regis_num;
    cout << "Enter vehicle model: ";
    cin >> newVehicle.model;
    cout << "Enter number of seats: ";
    cin >> newVehicle.seats;
    cout << "Enter rate per km: ";
    cin >> newVehicle.rate_per_km;
    vehicles.push_back(newVehicle);
    cout << "Vehicle added successfully!\n";
}

void VehicleRentalSystem::viewVehicleDetails()
{
    cout << "***************Viewing Vehicle details***************\n";
    string regis_num;
    cout << "Enter the registration number\n";
    cin >> regis_num;
    for (const auto &vehicle : vehicles)
    {
        if (vehicle.regis_num == regis_num)
        {
            cout << "Vehicle type: " << vehicle.type << "\n";
            cout << "Vehicle model: " << vehicle.model << "\n";
            cout << "Number of seats: " << vehicle.seats << "\n";
            cout << "Rate per km: " << vehicle.rate_per_km << "\n";
            return;
        }
    }
    cout <<"Vehicle with the above registration number not found";
}

void VehicleRentalSystem::editVehicleDetails()
{
    cout << "***************Editing vehicle details***************\n";
    string regis_num;
    cout << "Enter vehicle registration number to edit: ";
    cin >> regis_num;
    for (auto &vehicle : vehicles)
    {
        if (vehicle.regis_num == regis_num)
        {
            cout << "Enter new number of seats: ";
            cin >> vehicle.seats;
            cout << "Enter new rate per km: ";
            cin >> vehicle.rate_per_km;
            cout << "Vehicle details updated successfully!\n";
            return;
        }
    }
}

void VehicleRentalSystem::addNewUser()
{
    cout << "***************Adding new user details***************\n";
    User newUser;
    cout << "Enter user name: ";
    cin >> newUser.name;
    cout << "Enter user contact number: ";
    cin >> newUser.contact;
    users.push_back(newUser);
    cout << "User added successfully!\n";
}

void VehicleRentalSystem::addNewTrip()
{
    cout << "***************Adding new trip details***************\n";
    Trip newTrip;
    cout << "Enter user contact number: ";
    cin >> newTrip.user.contact;
    for (const auto &user : users)
    {
        if (user.contact == newTrip.user.contact)
        {
            newTrip.user.name = user.name;
            break;
        }
    }
    if (newTrip.user.name.empty())
    {
        cout << "User with this contact number does not exist. Please add the user first.\n";
        addNewUser();
    }
    cout << "Enter vehicle type: ";
    string type;
    cin >> type;
    vector<Vehicle> availableVehicles;
    for (const auto &vehicle : vehicles)
    {
        if (vehicle.type == type)
        {
            availableVehicles.push_back(vehicle);
        }
    }
    if (availableVehicles.empty())
    {
        cout << "No vehicles of this type are available.\n";
        return;
    }
    cout << "Available vehicles of this type are:\n";
    for (const auto &vehicle : availableVehicles)
    {
        cout << vehicle.model << " ";
        cout << vehicle.seats << "-seater ";
        cout << "Rs." << vehicle.rate_per_km << " per km";
        cout << "\n";
    }
    do {
    cout << "Enter vehicle model: ";
    string model1;
    cin >> model1;
    for (const auto &vehicle : vehicles)
    {
        if (vehicle.model == model1)
        {
            newTrip.vehicle = vehicle;
            break;
        }
    }
    if(newTrip.vehicle.model.empty())
    {
        cout << "\nNo such vehicle model exists. Select the correct vehicle model out of the one displayed above\n";
    }
    else {
        cout << "Enter no. of days: ";
        cin >> newTrip.days;

        newTrip.id = generaterandom();

        cout << newTrip.user.name << ", Your trip has been added succesfully for " << newTrip.days << " days with trip id " << newTrip.id << ".\n";
        trips.push_back(newTrip);
    }
} while(newTrip.vehicle.model.empty());
}

void VehicleRentalSystem::viewTrip()
{
    cout << "***************Viewing trip details***************\n";
    int id;
    cout << "Enter your trip ID: ";
    cin >> id;
    for (auto &trip : trips)
    {
        if (trip.id == id)
        {
            cout << "User name: " << trip.user.name << "\n";
            cout << "Vehicle type: " << trip.vehicle.type << "\n";
            cout << "Vehicle Registration no: " << trip.vehicle.regis_num << "\n";
            cout << "Vehicle model: " << trip.vehicle.model << "\n";
            cout << "Number of seats: " << trip.vehicle.seats << "\n";
            cout << "Rate per km: " << trip.vehicle.rate_per_km << "\n";
            cout << "Base fare for 1 day rental: 100\n";
            return;
        }
    }
    cout << "Trip not found!\n";
    cout << "Do you want to add new trip (yes/no)\n";
    string x;
    cin >> x;
    if (x == "yes")
    {
        addNewTrip();
    }
    else
        return;
}

void VehicleRentalSystem::startTrip()
{
    cout << "***************Starting your trip***************\n";
    int id;
    cout << "Enter your trip ID: ";
    cin >> id;
    for (auto &trip : trips)
    {
        if (trip.id == id)
        {
            cout << "Enter starting odometer reading: ";
            cin >> trip.startOdometer;
            cout << "Trip started. Have a safe journey!\n";
            return;
        }
    }
    cout << "Trip not found!\n";
    cout << "Do you want to add new trip (yes/no)\n";
    string x;
    cin >> x;
    if (x == "yes")
    {
        addNewTrip();
    }
    else
        return;
}

void VehicleRentalSystem::completeTrip()
{
    cout << "***************Ending your trip***************\n";
    int id;
    cout << "Enter your trip ID: ";
    cin >> id;
    for (auto &trip : trips)
    {
        if (trip.id == id)
        {
            cout << "Enter ending odometer reading: ";
            cin >> trip.endOdometer;
            trip.fare = ((trip.endOdometer - trip.startOdometer) * trip.vehicle.rate_per_km) + trip.days * 100;
            cout << "Trip completed! The fare is: " << trip.fare << "\n";
            return;
        }
    }
    cout << "Trip not found!\n";
    cout << "Do you want to add new trip (yes/no)\n";
    string x;
    cin >> x;
    if (x == "yes")
    {
        addNewTrip();
    }
    else
        return;
}

int main()
{
    VehicleRentalSystem vrs;
    vrs.operatorMenu();
    return 0;
}