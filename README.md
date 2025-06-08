# Vehicle Rental System (C++ OOPS Project)

This project is a simple **Vehicle Rental System** implemented in C++ using Object-Oriented Programming (OOPS) concepts. It allows users to manage vehicles, users, and trips, simulating a basic rental service.

## Features

- **Vehicle Management**
  - Add new vehicles
  - View vehicle details by registration number
  - Edit vehicle details (number of seats, rate per km)

- **User Management**
  - Add new users

- **Trip Management**
  - Add new trips (with user and vehicle selection)
  - View trip details by trip ID
  - Start a trip (record starting odometer)
  - Complete a trip (record ending odometer, calculate fare)

- **Menu-driven Console Interface**
  - Operator menu for managing vehicles and trips
  - Input validation and prompts for missing data

## How It Works

- The system maintains lists of vehicles, users, and trips using C++ vectors.
- Each trip is associated with a user and a vehicle, and is assigned a unique random trip ID.
- The fare is calculated based on distance traveled and number of days.
- The program runs in a loop, allowing the operator to perform various actions until they choose to exit.

## Classes Used

- `Vehicle`: Represents a vehicle with type, registration number, model, seats, and rate per km.
- `User`: Represents a user with name and contact number.
- `Trip`: Represents a trip with trip ID, associated user and vehicle, odometer readings, fare, and days.
- `VehicleRentalSystem`: Main class managing all operations and data.

## How to Run

1. **Copy the code** from `OOPS_PROJECT-1.cpp` into your C++ IDE or editor.
2. **Compile the code** using a C++ compiler:
   ```sh
   g++ OOPS_PROJECT-1.cpp -o VehicleRentalSystem
   ```
3. **Run the executable**:
   ```sh
   ./VehicleRentalSystem
   ```
4. **Follow the on-screen menu** to add vehicles, users, trips, and manage rentals.

## Example Menu

```
1. Edit Vehicles
2. Rent Vehicles
Enter Choice : 1

10. Add new vehicle
11. View vehicle details
12. Edit vehicle details
Choose an Option:
```

## Notes

- The system uses random numbers for trip IDs.
- All data is stored in memory (no file/database persistence).
- The code demonstrates OOPS concepts such as classes, encapsulation, and member functions.

---

**Project by:** Shreyas Mohan  
**Course:** OOPS Lab  
**Language:** C++
