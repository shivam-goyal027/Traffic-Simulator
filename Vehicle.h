#include <iostream>
#include <string>

using namespace std;

#ifndef Vehicle_H
#define Vehicle_H

class Vehicle{
public:
	Vehicle(); // Constructor
	Vehicle(string,string,int,int,int,int,int,int,int); //Overload Constructor
	Vehicle(string,string,int,int); //Overload w/o default values
	~Vehicle(); //Destructor
	string getType() const; // returns type of Vehicle
	string getColor() const; // returns color of Vehicle
	int getLength() const; // returns length of Vehicle
	int getWidth() const; // returns width of Vehicle
	int getMaxSpeed() const; // returns max speed of Vehicle
	int getAcceleration() const; // returns acceleration of Vehicle
	int getLaneFreq() const;
	int getPosx() const;
	int getPosy() const;

	//used for setting parameters
	void setType(string);
	void setColor(string);
	void setLength(int);
	void setWidth(int);
	void setMaxSpeed(int);
	void setAcceleration(int);
	void setLaneFreq(int);
	void setPosx(int);
	void setPosy(int);

	void move() const;

private:
	//Member Variables
	string Type;
	string Color;
	int Length;
	int Width;
	int MaxSpeed;
	int Acceleration;
	int LaneFreq; //Lane Change Frequency
	int Posx;
	int Posy;
};
