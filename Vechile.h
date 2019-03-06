#include <iostream>
#include <string>

using namespace std;

#ifndef Vechile_H
#define Vechile_H

class Vechile{
public:
	Vechile(); // Constructor
	Vechile(string,string,int,int,int,int,int); //Overload Constructor
	Vechile(string,string,int,int); //Overload w/o default values
	~Vechile(); //Destructor
	string getType() const; // returns type of vechile
	string getColor() const; // returns color of vechile
	int getLength() const; // returns length of vechile
	int getWidth() const; // returns width of vechile
	int getMaxSpeed() const; // returns max speed of vechile
	int getAcceleration() const; // returns acceleration of vechile
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
#endif
