#include <iostream>
#include <string>

using namespace std;

#ifndef Road_H
#define Road_H

class Road{
public:
	Road(); // Constructor
	Road(int,int,int,int,string); //Overload Constructor
	//Road(int,int,int,int); //Overload w/o default values
	~Road(); //Destructor
	int getRoad_ID() const; 
	string getSignal_Color() const; 
	int getRoad_Length() const;
	int getRoad_Width() const; 
	int getRoad_Signal() const; 
	//used for setRoad_ting parameters
	void setRoad_ID(int);
	void setSignal_Color(string);
	void setRoad_Length(int);
	void setRoad_Width(int);
	void setRoad_Signal(int);



private:
	//Member Variables
	int Road_ID;
	int Road_Length;
	int Road_Width;
	int Road_Signal;
	string Signal_Color;
}