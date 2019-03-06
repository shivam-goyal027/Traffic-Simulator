#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Road.h"
#include "Vehicle.h"
using namespace std;


void update(vector<Vehicle> v,string **s,Road road){
    for(int i=0;i<v.size();i++){
    	for(int k=0;k<road.getRoad_Width();k++){
    		if(v[i].getPosy()==k){
    			for(int r=k;r>k-v[i].getWidth();r--){
		            for(int j=0;j<road.getRoad_Length();j++){
		        		if(v[i].getPosx()==j){
		        			for(int q=j;q>j-v[i].getLength();q--){
		        				s[q][r]=v[i].getType().substr(0,1);
		        			}
		        		}
		        	}
		        }
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

//void move_all()

int main(int argc, char*argv){
	clock_t start = clock();
    int time = 0;
    Road road;
     
    vector<Vehicle> v_Vehicle;
    int i=0;
    int num;
    //cin>>num
    num=1;
    while(i<num){
    	Vehicle v("Car","Green",2,2,1,1,0.5);
    	v_Vehicle.push_back(v);
    	i++;
    }
    num=v_Vehicle.size();
    Vehicle Vehicle[num];
    for(int i=0;i<num;i++)
    	Vehicle[i]=v_Vehicle[i];
    vector<Vehicle> v_in_Vehicle;
    i=0;
    Vehicle v;
    string **a;
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
    for(int t=0;t<10;t++){
   // while{
	    //if(readline==){
    		Vehicle vec;
		vec=Vehicle[0]; //later Vehicle[k]
    		vec.setPosx(0);
    		vec.setPosy(2);
	    	v_in_Vehicle.push_back(vec);
	    	for(int i=0;i<v_in_Vehicle.size()-1;i++){
	    		v_in_Vehicle[i].move()
	    	}
	    //}
	    	



	    	update(v_in_Vehicle,a,road);
	    	display(a,road);
    //}
	}
    // Vehicle.push_back((Car,Green,2,2,1,1,0.5)) 
    // Vehicle(Car,Green,2,2,1,1,0.5);
    // Vehicle(Bus,Red,3,2);
    // Vehicle(Truck,Green,4,2);
    // Vehicle(bike,Blue,2,1);
	return 0;
}
