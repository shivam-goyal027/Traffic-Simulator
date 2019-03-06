#include "Vehicle.h"

Vehicle::Vehicle(){
	Length=0.0;
	Width=0.0;
	MaxSpeed=1.0; //for now, later to be taken from configuration file
	Acceleration=1.0; //for now, later to be taken from configuration file
	LaneFreq=0.3; //for now, later to be taken from configuration file
}

Vehicle::Vehicle(string UType,string UColor,int ULength,int UWidth,int UMaxSpeed,int UAcceleration, int ULaneFreq, int UPosx, int UPosy){
	Type=UType;
	Color=UColor;
	Length=ULength;
	Width=UWidth;
	MaxSpeed=UMaxSpeed;
	Acceleration=UAcceleration;
	LaneFreq=ULaneFreq;
};

Vehicle::Vehicle(string UType,string UColor,int ULength,int UWidth){
	Type=UType;
	Color=UColor;
	Length=ULength;
	Width=UWidth;
};

Vehicle::~Vehicle(){

}
//get any parameter
string Vehicle::getType() const{
	return Type;
}
string Vehicle::getColor() const{
	return Color;
}
int Vehicle::getLength() const{
	return Length;
}
int Vehicle::getWidth() const{
	return Width;
}
int Vehicle::getMaxSpeed() const{
	return MaxSpeed;
}
int Vehicle::getAcceleration() const{
	return Acceleration;
}
int Vehicle::getLaneFreq() const{
	return LaneFreq;
}
int Vehicle::getPosx() const{
	return Posx;
}
int Vehicle::getPosy() const{
	return Posy;
}
//set any parameter manually
void Vehicle::setType(string s) {
	Type=s;
}
void Vehicle::setColor(string s) {
	Color=s;
}
void Vehicle::setLength(int f) {
	Length=f;
}
void Vehicle::setWidth(int f) {
	Width=f;
}
void Vehicle::setMaxSpeed(int f) {
	MaxSpeed=f;
}
void Vehicle::setAcceleration(int f) {
	Acceleration=f;
}
void Vehicle::setLaneFreq(int f) {
	LaneFreq=f;
}
void Vehicle::setPosx(int f) {
	Posx=f;
}
void Vehicle::setPosy(int f) {
	Posy=f;
}

void Vehicle::move() const{
	Posx=Posx + MaxSpeed*1;
	//Posy=Posy+....;
}
