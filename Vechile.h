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

	void move();

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
Vechile::Vechile(){
	Length=0;
	Width=0;
	MaxSpeed=1; //for now, later to be taken from configuration file
	Acceleration=1; //for now, later to be taken from configuration file
	LaneFreq=1; //for now, later to be taken from configuration file
}

Vechile::Vechile(string UType,string UColor,int ULength,int UWidth,int UMaxSpeed,int UAcceleration, int ULaneFreq){
	Type=UType;
	Color=UColor;
	Length=ULength;
	Width=UWidth;
	MaxSpeed=UMaxSpeed;
	Acceleration=UAcceleration;
	LaneFreq=ULaneFreq;
};

Vechile::Vechile(string UType,string UColor,int ULength,int UWidth){
	Type=UType;
	Color=UColor;
	Length=ULength;
	Width=UWidth;
};

Vechile::~Vechile(){

}
//get any parameter
string Vechile::getType() const{
	return Type;
}
string Vechile::getColor() const{
	return Color;
}
int Vechile::getLength() const{
	return Length;
}
int Vechile::getWidth() const{
	return Width;
}
int Vechile::getMaxSpeed() const{
	return MaxSpeed;
}
int Vechile::getAcceleration() const{
	return Acceleration;
}
int Vechile::getLaneFreq() const{
	return LaneFreq;
}
int Vechile::getPosx() const{
	return Posx;
}
int Vechile::getPosy() const{
	return Posy;
}
//set any parameter manually
void Vechile::setType(string s) {
	Type=s;
}
void Vechile::setColor(string s) {
	Color=s;
}
void Vechile::setLength(int f) {
	Length=f;
}
void Vechile::setWidth(int f) {
	Width=f;
}
void Vechile::setMaxSpeed(int f) {
	MaxSpeed=f;
}
void Vechile::setAcceleration(int f) {
	Acceleration=f;
}
void Vechile::setLaneFreq(int f) {
	LaneFreq=f;
}
void Vechile::setPosx(int f) {
	Posx=f;
}
void Vechile::setPosy(int f) {
	Posy=f;
}

void Vechile::move(){
	setPosx((getPosx()) + (getMaxSpeed()));
	//Posy=Posy+....;
}
#endif
