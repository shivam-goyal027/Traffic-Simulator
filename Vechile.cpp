#include "Vechile.h"

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

void Vechile::move() const{
	Posx=Posx + MaxSpeed*1;
	//Posy=Posy+....;
}
