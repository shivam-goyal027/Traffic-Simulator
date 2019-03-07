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
};
Road::Road(){
	Road_ID=1;
	Road_Length=30;
	Road_Width=5;
	Road_Signal=15;
	Signal_Color="GREEN";
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
#endif

