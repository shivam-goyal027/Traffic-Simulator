#include "Road.h"

Road::Road(){
	Road_ID=1;
	Road_Length=30;
	Road_Width=5;
	Road_Signal=15;
	Signal_Color=GREEN;
}
Road::Road(int a,int b,int c,int d,string e){
	Road_ID=a;
	Road_Length=b;
	Road_Width=c;
	Road_Signal=d; 
	Signal_Color=e;
}
/*Road::Road(int a,int b,int c,int d){
	Road_ID=a;
	Road_Length=b;
	Road_Width=c;
	Road_Signal=d;
}*/

Road::~Road(){

}

//get variables
int Road::getRoad_ID() const{
	return Road_ID;
}
string Road::getSignal_Color() const{
	return Signal_Color;
}
int Road::getRoad_Length() const{
	return Road_Length;
}
int Road::getRoad_Width() const{
	return Road_Width;
}
int Road::getRoad_Signal() const{
	return Road_Signal;
}

//set variables
void Road::setRoad_ID(int a){
	Road_ID=a;
}
void Road::setSignal_Color(string a){
	Signal_Color=a;
}
void Road::setRoad_Length(int a){
	Road_Length=a;
}
void Road::setRoad_Width(int a){
	Road_Width=a;
}
void Road::setRoad_Signal(int a){
	Road_Signal=a;
}
