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
#include "IniReader.h"
using namespace std;


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
		            for(j=0;j<road.getRoad_Length();j++){
					//cout<<endl;
		        		if(v[i].getPosx()==j){
						//cout<< "beta"<< j <<endl;
						//cout<< "alpha" << v[i].getPosx() <<endl;
		        			for(q=j;(q>j-v[i].getLength() && q>=0);q--){
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
//
void change(string s){
    int pos = s.find("="); 
    s = s.substr(pos+1);
    cout<<s<<endl;
}
//void move_all()

int main(int argc, char* argv[]){
    clock_t start = clock();
    int time = 0;
    Road road;
    ifstream infile;
    infile.open("config.ini");
    if(!infile.is_open()){
        cout<< "Error opening file"<< endl;
        return 0;
    }
    //road parameters
    string a1,b1,c1;
    infile>>a1; infile>>b1; infile>>c1;
    road.setRoad_ID(stoi(c1));
    infile>>a1; infile>>b1; infile>>c1;
    road.setRoad_Length(stoi(c1));
    infile>>a1; infile>>b1; infile>>c1;
    road.setRoad_Width(stoi(c1));
    infile>>a1; infile>>b1; infile>>c1;
    road.setRoad_Signal(stoi(c1));
    
    vector<Vechile> v_vechile;
    /*infile>>a1;
    infile>>b1;
    infile>>c1; //total types of vehicle defined
    //order fixed type length width speed acceleration color
    while(i<c1){
        string a1,b1,c1;
        infile>>a1; infile>>b1; infile>>c1;//vehicle type
        string a2,b2,c2;
        infile>>a2; infile>>b2; infile>>c2;//vehicle length
        string a3,b3,c3;
        infile>>a3; infile>>b3; infile>>c3;//vehicle width
        string a4,b4,c4;
        infile>>a4;
        if(a4=="Rest_Default"){
            Vehicle_v(c1,stoi(c2),stoi(c3)); //only to set type length and width
            v_vechile.push_back(v);
            i++;
            continue;
        }
        else{
            infile>>b4; infile>>c4;//vehicle speed
            string a5,b5,c5;
            infile>>a5;
            if(a5=="Rest_Default"){
                Vehicle_v(c1,stoi(c2),stoi(c3),stoi(c4)); //only to set type length width speed
                v_vechile.push_back(v);
                i++;
                continue;
            }
            else{
                infile>>b5; infile>>c5;//vehicle acceleration
                string a6,b6,c6;
                infile>>a6;
                if(a6=="Rest_Default"){
                    Vehicle_v(c1,stoi(c2),stoi(c3),stoi(c4),stoi(c5)); //only to set type length width speed acceleration
                    v_vechile.push_back(v);
                    i++;
                    continue;
                }
                else{
                    infile>>b6; infile>>c6;//vehicle color
                    Vechile v(c1,c6,stoi(c2),stoi(c3),stoi(c4),stoi(c5)); //set all parameters
                    v_vechile.push_back(v);
                }
            }
        }
    	i++;
    }
    */
    int i=0;
    int num;
    //cin>>num
    num=1;
    while(i<num){
    	Vechile v("Car","Green",2,2,1,1,1);
    	v_vechile.push_back(v);
    	i++;
    }
    num=v_vechile.size();
    Vechile vechile[num];
    for(int i=0;i<num;i++)
    	vechile[i]=v_vechile[i];
    vector<Vechile> v_in_vechile;
    i=0;
    Vechile v;
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
 /* string s;
  infile>>s;
  if(s!="START"){
    cout<<"Wrong order"<<endl;
    return 0;
  }
  string col;//for signal color
  infile>>s; infile>>col;
  road.setSignal_Color(col);
  
  int num_v;
  infile>>s; //entry 
  infile>>s;//=
  infile>>stoi(num_v);
  
  while(num_v>0){
      //store incoming vehicles in array or vector here
      num_v--;
  }/*
  
  
  
/* 
   // while{
	    //if(readline==){
    		Vechile vec=vechile[0]; //later vechile[k]
    		vec.setPosx(0);
    		vec.setPosy(2);
	    	v_in_vechile.push_back(vec);
	    	for(int i=0;i<v_in_vechile.size()-1;i++){
	    		v_in_vechile[i].move();
	    	}
	    //}
*/
	    	
		
	 for(int t=0;t<40;t++){
		//display(a,road);
		//cout<<"a"<<endl;
		if(t==3){
    		Vechile vec=vechile[0]; //later vechile[k]
    		vec.setPosx(0);
    		vec.setPosy(2);
	    	v_in_vechile.push_back(vec);
                    for(int i=0;i<v_in_vechile.size()-1;i++){
                            v_in_vechile[i].move();
                    }
                }
		if(t==4){
    		Vechile vec=vechile[0]; //later vechile[k]
    		vec.setPosx(0);
    		vec.setPosy(5);
	    	v_in_vechile.push_back(vec);
                    for(int i=0;i<v_in_vechile.size()-1;i++){
                            v_in_vechile[i].move();
                    }
                }
		if(t!=3 && t!=4){
                    for(int i=0;i<v_in_vechile.size();i++){
                            v_in_vechile[i].move();
                    }		
		}
		for (int i=1;i<road.getRoad_Width()+1;i++){
                    for(int j=0;j<road.getRoad_Length();j++){
                        a[j][i]=" ";
                    }
                }
	    	update(v_in_vechile,a,road);
	    	display(a,road);
		//cout<<"b"<<endl;
		//cout<<v_in_vechile[0].getPosx()<<" "<<v_in_vechile[0].getLength()<<endl;
    //}
	}
    // vechile.push_back((Car,Green,2,2,1,1,0.5)) 
    // Vechile(Car,Green,2,2,1,1,0.5);
    // Vechile(Bus,Red,3,2);
    // Vechile(Truck,Green,4,2);
    // Vechile(bike,Blue,2,1);
	return 0;
}