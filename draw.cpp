#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Road.h"
#include "Vechile.h"
using namespace std;

Road road;
string **a;
vector<Vechile> v_vechile;
vector<Vechile> v_in_vechile;
ifstream infile;
    
int run=0;
int time_run;
string read_k;
string read_a1;

string change(string s){
    int pos = s.find("="); 
    if(pos==-1){
        pos = s.find(":");
    }
    s = s.substr(pos+1);
    return s;
}
string change2(string s){
    int pos = s.find("=");
    if(pos==-1){
        pos = s.find(":");
    }
    s = s.substr(0,pos);
    return s;
}
int count(vector<int> v,int a){
    int k;
    for(int i=0;i<v.size();i++){
        if(v[i]==a)
            k++;
    }
    return k;
}
// Returns random entering position
int call_value(string** k,Vechile v0){
    srand( time(0));
    bool makeit=true;
    int number;
    int i;
    vector<int> v;
    while(makeit==true){
        
        for(i=1;i<road.getRoad_Width()+1;i++){
            if(k[0][i]==" ")
                v.push_back(i);
        }
        number = rand() % v.size();
        for(i=1;i<v0.getWidth();i++){
            if(count(v,v[number]-i)<=0){
                break;
            }
        }
        if(i==v0.getWidth()){
            makeit=false;
        }
    }
    return v[number];
}

void update(vector<Vechile> v,string **s,Road road){
  int i,j,r,q,k;
  int w=0;  
    for(i=0;i<v.size();i++){
	//cout<< "be"<< v.size() <<endl;
    	for(k=1;k<road.getRoad_Width()+1;k++){
		//cout<< "alpha"<< k <<endl;
    		if(v[i].getPosy()==k){
                    
			//cout<< "beta"<< k <<endl;
    			for(r=k;(r>k-v[i].getWidth() && r>0);r--){
                            //cout<< "eta"<< r <<endl;
                            //cout<<"see:"<<v[i].getType().substr(0,1)<<":"<<endl;
		            for(j=0;j<road.getRoad_Length();j++){
					//cout<<endl;
		        		if(v[i].getPosx()==j){
		        			for(q=j;(q>j-v[i].getLength() && q>=0);q--){
		        				s[q][r]=v[i].getType().substr(0,1);
                                                        
		        			}
		        		}
		        	}
		        } //cout<< "out"<< k-v[i].getWidth() <<endl;
    		}
        }    		
    }
}

void display(string **s,Road road){
    for (int i=0;i<road.getRoad_Width()+2;i++){
        for(int j=0;j<road.getRoad_Length();j++){
            cout<<s[j][i];
        }
        cout<<endl;
    }
}
int refreshMills = 200; // refresh interval in milliseconds

/* Called back when timer expired */
void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

void initGL() {
   //Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
// Function to escape screen
void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
   }
}

int min_2(int a,int b){
        //cout<< a<<": "<<b<<endl;
	if(b<0 || a<b){
		return a;
	}
	return b;
}
int minimum_all(vector<int> v){
	int min_all=10000;
	for(int i=0;i<v.size();i++){
                //cout<<v[i]<<endl;
		if(v[i]<min_all){
			min_all=v[i];
                }
	}
	return min_all;
}

bool is_between(int a,int b,int c){
	if(a<b && a>c ){
		return true;
	}
	return false;
}

//v_clash_x is a function that returns a vector of x distances of vechiles that clash with the given vechile.
vector<int> v_clash_x(Vechile v0,vector<Vechile> v){
	vector<int> ret;
	
	for(int i=0;i<v.size();i++){
		if(v[i].getPosx()!=v0.getPosx() || v[i].getPosy()!=v0.getPosy()){
			if(((is_between(v[i].getPosy(),v0.getPosy(),v0.getPosy()-v0.getWidth()) || is_between(v[i].getPosy()-v[i].getWidth(),v0.getPosy(),v0.getPosy()-v0.getWidth())) || ((v[i].getPosy()==v0.getPosy() || v[i].getPosy()-v[i].getWidth()==v0.getPosy()-v0.getWidth() )&& v[i].getWidth()>=v0.getWidth())) && v[i].getPosx()-v[i].getLength()>=v0.getPosx()){
				ret.push_back(v[i].getPosx()-v[i].getLength()-v0.getPosx()); //v[i].getPosx-v[i].getWidth-v0.getPosx // this is the xdis b/w the vechiles ,that is >=1
			}
		}
	}
	if(ret.size()==0){
		ret.push_back(10000);
	}
	return ret;
}


int check_x(Vechile v){
	if(v.getDisx()>v.getSpeed()+v.getAcceleration()){
		return v.getSpeed()+v.getAcceleration();
	}
	else if(v.getDisx()<=v.getSpeed()+v.getAcceleration() && v.getDisx()>v.getSpeed()){
		return v.getSpeed();
	}
	else if(v.getDisx()>v.getSpeed()-v.getAcceleration() && v.getDisx()<=v.getSpeed()){
		return v.getSpeed()-v.getAcceleration(); 
	}
	else if(v.getDisx()>v.getSpeed()-2*v.getAcceleration() && v.getDisx()<=v.getSpeed()-v.getAcceleration()){
		return v.getSpeed()-2*v.getAcceleration(); 
	}
	else if(v.getDisx()>v.getSpeed()-3*v.getAcceleration() && v.getDisx()<=v.getSpeed()-2*v.getAcceleration()){
		return v.getSpeed()-3*v.getAcceleration(); 
	}
	return 0;
}
int check_array(string **s){
    int p=1;
    for (int i=1;i<road.getRoad_Width()+1;i++){
        for(int j=0;j<road.getRoad_Length();j++){
            if(s[i][j]!=" "){
                p=0;
                break;
            }
        }
    }
    return p;
}

int check_right(vector<Vechile> v, Vechile v0){
	for(int i=0;i<v.size();i++){
		if(v[i].getPosx()!=v0.getPosx() || v[i].getPosy()!=v0.getPosy()){
			if((((is_between(v[i].getPosy(),v0.getPosy(),v0.getPosy()+v0.getWidth()) || is_between(v[i].getPosy()-v[i].getWidth(),v0.getPosy(),v0.getPosy()+v0.getWidth())) || ((v[i].getPosy()-v[i].getWidth()==v0.getPosy() || v[i].getPosy()==v0.getPosy()+v0.getWidth() )&& v[i].getWidth()>=v0.getWidth())) && ((v[i].getPosx()-v[i].getLength()<=v0.getPosx()+v0.getSpeed()+v0.getAcceleration() && v[i].getPosx()>=v0.getPosx()) && (v[i].getPosx()+v[i].getSpeed()+v[i].getAcceleration()>=v0.getPosx()-v0.getLength() && v[i].getPosx()<=v0.getPosx()))) || ( is_between(v[i].getPosx(),v0.getPosx(),v0.getPosx()-v0.getLength()) || is_between(v[i].getPosx()-v[i].getLength(),v0.getPosx(),v0.getPosx()-v0.getLength()) ||((v[i].getPosx()==v0.getPosx() || v[i].getPosx()-v[i].getLength()==v0.getPosx()-v0.getLength()) && v[i].getWidth()>=v0.getWidth() ) )){
				return 0;
			}
		
		}			
	}
	return 1;
}

void drawRoad(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Road
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(0.0,0.0);
        glVertex2f((road.getRoad_Length()),0.0);
        glVertex2f((road.getRoad_Length()),-(road.getRoad_Width()+2));
        glVertex2f(0.0,-(road.getRoad_Width()+2));
    glEnd();
    
    //Divider line
    float l=0.0;
    while(l<road.getRoad_Length()){
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glVertex2f(l,-(road.getRoad_Width()/2));
            glVertex2f(l+2,-(road.getRoad_Width()/2));
            glVertex2f(l+2,-(road.getRoad_Width()/2)+0.5);
            glVertex2f(l,-(road.getRoad_Width()/2)+0.5);
        glEnd();
        
            //background
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);
                glVertex2f(l,-(road.getRoad_Width()+2));
                glVertex2f(l+2,-(road.getRoad_Width()+2));
                glVertex2f(l+2,-(road.getRoad_Width()+2)-2.5);
                glVertex2f(l,-(road.getRoad_Width()+2)-2.5);
            glEnd();
            glBegin(GL_POLYGON);
                glVertex2f(l,0.0);
                glVertex2f(l+2,0.0);
                glVertex2f(l+2,2.5);
                glVertex2f(l,2.5);
            glEnd();
        
        l=l+5.0;
    }
    //Side divider
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0,0.0);
        glVertex2f((road.getRoad_Length()),0.0);
        glVertex2f((road.getRoad_Length()),0.4);
        glVertex2f(0.0,0.4);
    glEnd();
    
    glBegin(GL_POLYGON);
        glVertex2f(0.0,-road.getRoad_Width()-2);
        glVertex2f((road.getRoad_Length()),-road.getRoad_Width()-2);
        glVertex2f((road.getRoad_Length()),-road.getRoad_Width()-2-0.4);
        glVertex2f(0.0,-road.getRoad_Width()-2-0.4);
    glEnd();

        for(int i=0;i<v_in_vechile.size();i++){
            //glTranslatef(v_in_vechile[i].getPosx(), v_in_vechile[i].getPosy(), 0.0f); 
            string colour = v_in_vechile[i].getColor();
            if(colour=="RED")
                glColor3f(1,0,0);
            if(colour=="GREEN")
                glColor3f(0,1,0);
            if(colour=="BLUE")
                glColor3f(0,0,1);
            if(colour=="YELLOW")
                glColor3f(1,1,0);
            if(colour=="BLACK")
                glColor3f(0,0,0);
            if(colour=="WHITE")
                glColor3f(1,1,1);
            if(colour=="PINK")
                glColor3ub(255,51,255);
            if(colour=="CYAN")
                glColor3ub(0,255,255);
            if(colour=="GOLDEN")
                glColor3ub(153,153,0);
            glBegin(GL_POLYGON);
                glVertex2f(v_in_vechile[i].getPosx(),-(v_in_vechile[i].getPosy()));
                glVertex2f(v_in_vechile[i].getPosx(),-(v_in_vechile[i].getPosy())+v_in_vechile[i].getWidth());
                glVertex2f(v_in_vechile[i].getPosx()-v_in_vechile[i].getLength(),-(v_in_vechile[i].getPosy())+v_in_vechile[i].getWidth());
                glVertex2f(v_in_vechile[i].getPosx()-v_in_vechile[i].getLength(),-(v_in_vechile[i].getPosy()));
            glEnd();
        }
    //Traffic light
    if(road.getSignal_Color()=="RED")
        glColor3f(1,0,0);
    if(road.getSignal_Color()=="GREEN")
        glColor3f(0,1,0);
    float x1,y1,x2,y2;
    float angle;
    double radius=0.38;
    y1 = radius,x1=road.getRoad_Signal();
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1,y1);

            for(angle=0.0f ; angle<2*3.14159 + 3; angle+=0.2){
                x2 = x1+sin(angle)*radius;
                y2 = y1+cos(angle)*radius;
                glVertex2f(x2,y2);
            }
        glEnd();
    
        y1=2*radius + radius;
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1,y1);

            for(angle=0.0f ; angle<2*3.14159 + 3; angle+=0.2){
                x2 = x1+sin(angle)*radius;
                y2 = y1+cos(angle)*radius;
                glVertex2f(x2,y2);
            }
        glEnd();
        
        y1=4*radius + radius;
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1,y1);

            for(angle=0.0f ; angle<2*3.14159 + 3; angle+=0.2){
                x2 = x1+sin(angle)*radius;
                y2 = y1+cos(angle)*radius;
                glVertex2f(x2,y2);
            }
        glEnd();
        
    glutSwapBuffers();
}
void display2(){
    if(time_run<=0){
        infile>>read_k;
        while(read_k=="#"){
            infile.ignore(256,'\n');
            infile>>read_k;
        }
    }
        if(read_k!="END"){
            if(change2(read_k)!="Pass" && change2(read_k)!="Signal"){
                int i;
                for(i=0;i<v_vechile.size();i++){
                    if(v_vechile[i].getType()==change2(read_k)){
                        break;
                    }
                }
                if(i==v_vechile.size())
                    cout<<"This vehicle type is not yet defined"<<endl;
                
                v_vechile[i].setColor(change(read_k));
                v_vechile[i].setPosx(0);
                v_vechile[i].setPosy(call_value(a,v_vechile[i]));
                
                for(int i=0;i<v_in_vechile.size();i++){
			
		    if(road.getSignal_Color()=="RED")
                    	v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx()));
		    else
			v_in_vechile[i].setDisx(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)));
                }
                for(int i=0;i<v_in_vechile.size();i++){
                        if(check_right(v_in_vechile,v_in_vechile[i])==1 && ((v_in_vechile[i].getDisx()<v_in_vechile[i].getSpeed() && v_in_vechile[i].getSpeed()!=v_in_vechile[i].getMaxSpeed() && v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth()<=road.getRoad_Width()+1 && minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile))<=road.getRoad_Signal()-v_in_vechile[i].getPosx()) || v_in_vechile[i].getSpeed()==0))
                            v_in_vechile[i].setPosy(v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth());
                }
                for(int i=0;i<v_in_vechile.size();i++){
                        if(check_x(v_in_vechile[i])>=v_in_vechile[i].getMaxSpeed()){
                                v_in_vechile[i].setSpeed(v_in_vechile[i].getMaxSpeed());	
                        }
                        else{
                                if(check_x(v_in_vechile[i])<=0){
                                    if(v_in_vechile[i].getDisx()<=v_in_vechile[i].getLength())
                                         v_in_vechile[i].setPosx( v_in_vechile[i].getPosx()+ v_in_vechile[i].getDisx());
                                     v_in_vechile[i].setSpeed(0);
                                }
                                else{
                                        v_in_vechile[i].setSpeed(check_x(v_in_vechile[i]));
                                }
                        }
                }
		v_in_vechile.push_back(v_vechile[i]);
                for (int i=1;i<road.getRoad_Width()+1;i++){
                    for(int j=0;j<road.getRoad_Length();j++){
                        a[j][i]=" ";
                    }
                }
                
                for(int i=0;i<v_in_vechile.size()-1;i++){
                    v_in_vechile[i].move();
                }
                 
                update(v_in_vechile,a,road);
                display(a,road);
                drawRoad();
            }
            
            if(change2(read_k)=="Pass"){
                if(time_run==0){
                    time_run = stoi(change(read_k));
                }
                if(time_run>0){
                    
                    for(int i=0;i<v_in_vechile.size();i++){
			if(road.getSignal_Color()=="RED")
                        	v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx()));
			else
				v_in_vechile[i].setDisx(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)));
                        //v_clash_x is a function that returns a vector of x distances of vechiles that clash with the given vechile.
                    }
                    for(int i=0;i<v_in_vechile.size();i++){
                        if(check_right(v_in_vechile,v_in_vechile[i])==1 && v_in_vechile[i].getDisx()<v_in_vechile[i].getSpeed() && v_in_vechile[i].getSpeed()!=v_in_vechile[i].getMaxSpeed() && v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth()<=road.getRoad_Width()+1 && minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile))<=road.getRoad_Signal()-v_in_vechile[i].getPosx())
                            v_in_vechile[i].setPosy(v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth());
                    }
                    for(int i=0;i<v_in_vechile.size();i++){
                            if(check_x(v_in_vechile[i])>=v_in_vechile[i].getMaxSpeed()){
                                    v_in_vechile[i].setSpeed(v_in_vechile[i].getMaxSpeed());	
                            }
                            else{
                                     if(check_x(v_in_vechile[i])<=0){
                                    if(v_in_vechile[i].getDisx()<=v_in_vechile[i].getLength())
                                         v_in_vechile[i].setPosx( v_in_vechile[i].getPosx()+ v_in_vechile[i].getDisx());
                                     v_in_vechile[i].setSpeed(0);
                                }
                                    else{
                                            v_in_vechile[i].setSpeed(check_x(v_in_vechile[i]));
                                    }
                            }
                            
                    }
                    for (int i=1;i<road.getRoad_Width()+1;i++){
                        for(int j=0;j<road.getRoad_Length();j++){
                            a[j][i]=" ";
                        }
                    }
                    for(int i=0;i<v_in_vechile.size();i++){
                        v_in_vechile[i].move();
                    }
                    update(v_in_vechile,a,road);
                    display(a,road);
                    drawRoad();
                    time_run--;
                }
            }
            
            if(change2(read_k)=="Signal"){
                road.setSignal_Color(change(read_k));
                for(int i=0;i<v_in_vechile.size();i++){ //v_in is the vector of vechiles in the road
		    if(road.getSignal_Color()=="RED")
                    	v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx()));
		    else
			v_in_vechile[i].setDisx(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)));
                    //v_clash_x is a function that returns a vector of x distances of vechiles that clash with the given vechile.
                }
                for(int i=0;i<v_in_vechile.size();i++){
                        if(check_right(v_in_vechile,v_in_vechile[i])==1 && v_in_vechile[i].getDisx()<v_in_vechile[i].getSpeed() && v_in_vechile[i].getSpeed()!=v_in_vechile[i].getMaxSpeed() && v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth()<=road.getRoad_Width()+1 && minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile))<=road.getRoad_Signal()-v_in_vechile[i].getPosx())
                            v_in_vechile[i].setPosy(v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth());
                }
                    
                for(int i=0;i<v_in_vechile.size();i++){
                        if(check_x(v_in_vechile[i])>=v_in_vechile[i].getMaxSpeed()){
                                v_in_vechile[i].setSpeed(v_in_vechile[i].getMaxSpeed());	
                        }
                        else{
                                 if(check_x(v_in_vechile[i])<=0){
                                    if(v_in_vechile[i].getDisx()<=v_in_vechile[i].getLength())
                                         v_in_vechile[i].setPosx( v_in_vechile[i].getPosx()+ v_in_vechile[i].getDisx());
                                     v_in_vechile[i].setSpeed(0);
                                }
                                else{
                                        v_in_vechile[i].setSpeed(check_x(v_in_vechile[i]));
                                }
                        }
                        
                }
                for (int i=1;i<road.getRoad_Width()+1;i++){
                    for(int j=0;j<road.getRoad_Length();j++){
                        a[j][i]=" ";
                    }
                }
                for(int i=0;i<v_in_vechile.size()-1;i++){
                    v_in_vechile[i].move();
                }
                update(v_in_vechile,a,road);
                display(a,road);
                drawRoad();
            }
        }
        else{            
                for(int i=0;i<v_in_vechile.size();i++){
			if(road.getSignal_Color()=="RED")
                        	v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx()));
			else
				v_in_vechile[i].setDisx(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)));
                        //v_clash_x is a function that returns a vector of x distances of vechiles that clash with the given vechile.
                    }
    
                    for(int i=0;i<v_in_vechile.size();i++){
                            if(check_x(v_in_vechile[i])>=v_in_vechile[i].getMaxSpeed()){
                                    v_in_vechile[i].setSpeed(v_in_vechile[i].getMaxSpeed());	
                            }
                            else{
                                    if(check_x(v_in_vechile[i])<=0){
                                            v_in_vechile[i].setSpeed(0);
                                    }
                                    else{
                                            v_in_vechile[i].setSpeed(check_x(v_in_vechile[i]));
                                    }
                            }
                            
                    }
                    for (int i=1;i<road.getRoad_Width()+1;i++){
                        for(int j=0;j<road.getRoad_Length();j++){
                            a[j][i]=" ";
                        }
                    }
                    for(int i=0;i<v_in_vechile.size();i++){
                        v_in_vechile[i].move();
                    }
                    update(v_in_vechile,a,road);
                    if(check_array(a)=='1'){
                        return;
                    }
                    display(a,road);
                    drawRoad();
        }
}

void display1(){
    infile.open("config.ini");
    if(!infile.is_open()){
        cout<< "Error opening file"<< endl;
    }    
    //road parameters
    string a1; 
    infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_ID(stoi(a1)); infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_Length(stoi(a1)); infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_Width(stoi(a1)); infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_Signal(stoi(a1));
    
    a=new string*[road.getRoad_Length()];//7
        for(int i=0;i<road.getRoad_Length();i++)
            a[i]=new string[road.getRoad_Width()+2];
    for(int i=0;i<road.getRoad_Width()+2;i++){
            for(int j=0;j<road.getRoad_Length();j++){
                    a[j][i]=" ";
            }
    }
    
    for(int k=0;k<road.getRoad_Width()+2;k++){
        if(k==0 || k==road.getRoad_Width()+1){
            for(int i=0;i<road.getRoad_Length();i++){
                a[i][k]="-";
            }
        }
    }
    string k;
    infile>>k;
    while(k=="#"){
        infile.ignore(256,'\n');
        infile>>k;
    } k=change(k); //number of vechiles to be defined
    int t = stoi(k);
    int i=0;
    string a2;
    while(t>0){
        if(i==0){
            infile>>a1;
            while(a1=="#"){
                infile.ignore(256,'\n');
                infile>>a1;
            }
            infile>>a2;
            while(a2=="#"){
                infile.ignore(256,'\n');
                infile>>a2;
            }
        }
        else{
            a1=a2;
            infile>>a2;
            while(a2=="#"){
                infile.ignore(256,'\n');
                infile>>a2;
            }
        }
        Vechile v;
        while(change2(a2)!="Vechile_Type" ){
            v.setType(change(a1)); 
                if(change2(a2)=="Vechile_Length")
                    v.setLength(stoi(change(a2))); 
                if(change2(a2)=="Vechile_Width"){
                    v.setWidth(stoi(change(a2)));
                }
                if(change2(a2)=="Vechile_MaxSpeed")
                    v.setMaxSpeed(stoi(change(a2)));
                if(change2(a2)=="Vechile_Acceleration")
                    v.setAcceleration(stoi(change(a2)));
                if(change2(a2)=="Vechile_Color")
                    v.setColor(change(a2));
            infile>>a2;
            while(a2=="#"){
                infile.ignore(256,'\n');
                infile>>a2;
            }
            if(change2(a2)=="Vechile_Type" || a2=="end"){
                v_vechile.push_back(v);
            }  
            if(a2=="end"){
                break;
            }
        }  
        i++;
        t=t-1;
    }    
}
bool paused = false;
//GLfloat xSpeedSaved, ySpeedSaved;  // To support resume
vector<int> save_speed;
vector<int> save_acceleration;
string save_signal;

int main(int argc, char* argv[]){
    
    display1();
    infile>>read_a1;
    while(read_a1=="#"){
        infile.ignore(256,'\n');
        infile>>read_a1;
    }
    time_run=0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(2000, 2000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Traffic System");
    gluOrtho2D(0,road.getRoad_Length(),-(road.getRoad_Width()+2+2.5),2.5 );
    if(read_a1=="START"){
        glutDisplayFunc(display2);
    }else{
        infile>>read_a1; 
        while(read_a1=="#"){
            infile.ignore(256,'\n');
            infile>>read_a1;
        }
    }
    glutTimerFunc(0, Timer, 0);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
    return 0;   
}
