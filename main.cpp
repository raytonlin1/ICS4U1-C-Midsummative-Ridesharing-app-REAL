/*
Name: Rayton Lin
Teacher: Mr. Noukhovitch
Class: ICS4U1-03
Date: January 5th, 2019
Purpose: This program stores information for a ride sharing app using classes, inheritance, constructors, destructors, functions, exceptions and dynamic memory.
*/
#include <iostream>

using namespace std;
bool invalidOperationOrNot=false; //Boolean value that represents if the operation was invalid or not.
string InvalidOperation= "Invalid operation. "; //Base string to be added to and thrown if an error occurs.
string InvalidInput = "The input is invalid. The input can not be negative.";	//String to be thrown when an error due to a negative input occurs.
string InputMoreThanReserved = "The input is more than the number of reserved seats, so the inputted number of seats can not be unreserved.";	//String to be thrown when the number of reserved seats is too large.

class RideBooking
{				//Creates a class to represent the ride's booking.
public:			//These are public methods.
  RideBooking () {}; //Constructor for a ride.
  ~RideBooking() {}; //Destructor for when the ride is finished.
  void setCar(int num, int capacity); //Method to set the number and number of seats of the car.
  void makeReservation (string destinationInput);	//Method that makes a reservation.
  void cancelReservation ();	//Method that cancels a reservation.
  int getCarNumber ();		//Method that obtains the number of the car that is taken for the ride.
  virtual string getDestination()=0; //Method that gets the destination of the ride. This is a pure virtual function only used in the subclasses.
  virtual void changeDestination()=0; //Method that changes the destination for the ride. This is a pure virtual function only used in the subclasses.
private:			//These are private members that can only be accessed by the public methods.
  int carNumber;		//Represents the number of the car that is taken for the ride.
  int numOfSeats;		//Represents the number of seats of the ride.
  bool reserved; //Represents if the car is reserved for a ride or not.
};

void RideBooking::setCar(int num, int capacity) //Method to set the number and number of seats of the car.
{
    carNumber=num;
    numOfSeats=capacity;
    reserved=false;
    //Sets the methods to the inputted parameters. The car is not reserved until a reservation is made.
}


class Carpool : public RideBooking
{
private:
    string *destinations;
    rides=new string[maxNumberOfRides+1];
    
public:
    void addDestination();
    string getDestination(); //Method that gets the destination of the ride. This is changed in the subclasses.
    void changeDestination(); //Method that changes the destination for the ride. This is changed in the subclasses.
}


class SingleCar : public RideBooking
{
public:
    string getDestination();	//Method that obtains the destination of the ride.
    void getDestination(); //Method that gets the destination of the ride. 
    void changeDestination(); //Method that changes the destination for the ride. 
}


int main ()
{
  string inputCommand="",inputTypeOfRide;		//Initializes string variables that stores inputted commands and inputted types of rides.
  int inputNumber,inputSeats, maxNumberOfRides;		//Initializes integer variables that stores inputted car numbers, inputted number of seats and the maximum number of rides.
  cout << "Enter the maximum number of rides that can be stored. Car ID numbers will go from 1 to this number.: ";
  cin >> maxNumberOfRides;
  cout << "\n";
  RideBooking *rides;
  rides=new RideBooking[maxNumberOfRides+1]; //Initializes an array of pointers to represent the rides in the ride-sharing app, with the maximum number of rides being the number inputted.

  cout<<"The following commands can be entered.\n";
  cout<<"The create command creates a new empty car for a ride. You will be asked to enter the number of the car, and then the number of seats in the car.\n";
  cout<<"The delete command deletes a ride. You will be asked for the number of the car to be deleted.\n";
  cout<<"The reserve command reserves a ride. You will be asked for the number of seats necessary, and the destination.\n";
  cout<<"The cancel command cancels a ride. You will be asked for the number of the car whose ride will be cancelled.";
  cout<<"The quit command exits the program.\n";

  while (inputCommand != "quit")
    {
      cout << "Enter your command (create, add, cancel, delete or quit): ";
	  cin >> inputCommand;
      cout << "\n";
      InvalidOperation="Invalid operation. "; //Resets the string to be thrown if there is an invalid operation.
      invalidOperationOrNot=false;
      if (inputCommand=="create")
      {
          cout<<"Enter the number for the car (between 1 and "<<maxNumberofRides<<"): ";
          cin>>inputNumber;
          cout<<"\n";
          cout<<"Enter the number of seats for the car: ";
          cin>>inputSeats;
          cout<<"\n";
          cout<<"Enter the type of ride (carpool or single car): ";
          cin>>inputTypeOfRide;
          cout<<"\n";
          try 
          {
              if (inputNumber<1 || inputNumber>maxNumberOfRides)
              {
                  InvalidOperation.append("The inputted number for the car must be between 1 and ");
                  InvalidOperation.append(to_string(maxNumberOfRides));
                  InvalidOperation.append(".");
                  invalidOperationOrNot=true;
              }
              if (tolower(inputTypeOfRide)=="carpool")
              {
                  rides[inputNumber]=new Carpool;
                  
              }
              else if (tolower(inputTypeOfRide)=="single car")
              {
                  rides[inputNumber]=new SingleCar;
                  
              }
              else
              {
                 InvalidOperation.append("The type of ride that was inputted is invalid.");
                 invalidOperationOrNot=true;
              }
              if (invalidOperationOrNot)
              {
                  throw InvalidOperation;
              }
          }
          catch (string &problem)
          {
              cout<<problem<<"\n";
          }
      }
      else if (inputCommand=="add")
      {
          
      }
      else if (inputCommand=="cancel")
      {
          
      }
      else if (inputCommand=="delete")
      {
          
      }
      else if (inputCommand!="quit")
      {
          cout<<"Invalid command, you must input a valid command.\n";
      }
    }
  delete [] rides; //Deletes the array from memory.
  return 0;
}
