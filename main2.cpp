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

void drawRoad(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.95,0.95,0.95);
    glBegin(GL_POLYGON);
        //gluOrtho2D(-(0.5),-0.5,0.5,0.5);
        glVertex2f(-(road.getRoad_Length()/2),(road.getRoad_Width()/2));
        glVertex2f((road.getRoad_Length()/2),(road.getRoad_Width()/2));
        glVertex2f((road.getRoad_Length()/2),-(road.getRoad_Width()/2));
        glVertex2f(-(road.getRoad_Length()/2),-(road.getRoad_Width()/2));
    glEnd();
    glFlush();
}
//
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

int min_2(int a,int b){
        //cout<< a<<": "<<b<<endl;
	if(b<=0 || a<b){
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
	if(a<=b && a>=c ){
		return true;
	}
	return false;
}

//v_clash_x is a function that returns a vector of x distances of vechiles that clash with the given vechile.
vector<int> v_clash_x(Vechile v0,vector<Vechile> v){
	vector<int> ret;
	for(int i=0;i<v.size();i++){
		if(v[i].getPosx()!=v0.getPosx() && v[i].getPosy()!=v0.getPosy()){
			if((is_between(v[i].getPosy(),v0.getPosy(),v0.getPosy()-v0.getWidth()) || is_between(v[i].getPosy()-v[i].getWidth(),v0.getPosy(),v0.getPosy()-v0.getWidth())) && v[i].getPosx()-v[i].getLength()>v0.getPosx()){
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
	else if(v.getDisx()<v.getSpeed()+v.getAcceleration() && v.getDisx()>v.getSpeed()){
		return v.getSpeed();
	}
	else if(v.getDisx()>v.getSpeed()-v.getAcceleration() && v.getDisx()<v.getSpeed()){
		return v.getSpeed()-v.getAcceleration(); 
	}
	return 0;
}
//void move_all()

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Traffic System");
    gluOrtho2D(-50, 50, -50, 50);
    
    //Road road;
    ifstream infile;
    infile.open("config.ini");
    if(!infile.is_open()){
        cout<< "Error opening file"<< endl;
        return 0;
    }
    
    //road parameters
    string a1; 
    infile>>a1; a1=change(a1);
    road.setRoad_ID(stoi(a1));
    infile>>a1; a1=change(a1);
    road.setRoad_Length(stoi(a1));
    infile>>a1; a1=change(a1);
    road.setRoad_Width(stoi(a1));
    infile>>a1; a1=change(a1);
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
    display(a,road);
    vector<Vechile> v_vechile;
    
    string k;
    infile>>k;
    k=change(k); //number of vechiles to be defined
    int t = stoi(k);
    //cout<<t;
    int i=0;
    string a2;
    while(t>0){
        
        if(i==0){
            infile>>a1;
            infile>>a2;
        }
        else{
            a1=a2;
            infile>>a2;
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
    //Pass,Type,Signal
    vector<Vechile> v_in_vechile;//v_in_vechile is the vector of vechiles in the road
    infile>>k;
    if(k=="START"){
        infile>>k;
        while(k!="END"){
            if(change2(k)!="Pass" && change2(k)!="Signal"){
                int i;
                for(i=0;i<v_vechile.size();i++){
                    if(v_vechile[i].getType()==change2(k)){
                        //cout<<"yes"<<endl;
                        break;
                    }
                }
                if(i==v_vechile.size())
                    cout<<"This vehicle type is not yet defined"<<endl;
                
                v_vechile[i].setColor(change(k));
                v_vechile[i].setPosx(0);
                v_vechile[i].setPosy(4*i + 3);
                //cout<<v_vechile[i].getWidth()<<endl;
                 
                v_in_vechile.push_back(v_vechile[i]);
               //cout<<v_in_vechile[0].getWidth()<<endl;
                //cout<<v_in_vechile.size()<<endl;
                
                for(int i=0;i<v_in_vechile.size();i++){
                    v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx())); 
                }
                for(int i=0;i<v_in_vechile.size();i++){cout<<i<<":"<<v_in_vechile[i].getDisx()<<endl;}
                //cout<<v_in_vechile[i].getDisx()<<endl;
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
                
                for(int i=0;i<v_in_vechile.size()-1;i++){
                    v_in_vechile[i].move();
                }
                 
                update(v_in_vechile,a,road);
                display(a,road);
            }
            
            if(change2(k)=="Pass"){
                int time_run = stoi(change(k));
                while(time_run>0){
                    
                    for(int i=0;i<v_in_vechile.size();i++){ 
                        v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx())); //v_clash_x is a function that returns a vector of x 		distances of vechiles that clash with the given vechile.
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
                    //display(a,road);
                    time_run--;
                }
            }
            
            if(change2(k)=="Signal"){
                road.setSignal_Color(change(k));
                for(int i=0;i<v_in_vechile.size();i++){ //v_in is the vector of vechiles in the road
                    v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx())); //v_clash_x is a function that returns a vector of x 		distances of vechiles that clash with the given vechile.
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
                for(int i=0;i<v_in_vechile.size()-1;i++){
                    v_in_vechile[i].move();
                }
                update(v_in_vechile,a,road);
                display(a,road);
            }
            infile>>k;
        }     
    }
    else{
     cout<<"Invalid Format"<<endl;   
    }
    glutDisplayFunc(drawRoad);
    glutMainLoop();
    return 0;
}   
    

