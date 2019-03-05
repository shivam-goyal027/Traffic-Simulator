#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;


void display(string **s,int dim1,int dim2){
    for (int i=0;i<dim2;i++){
        for(int j=0;j<dim1;j++){
            cout<<s[j][i];
        }
        cout<<endl;
    }
}

int main(int argc,char* argv[]){
    clock_t start = clock();
    bool red_light=false;
    int time = 0;  
   
    int car_length=2; //2x2
    int truck_length=5; //3x3
    int bike_length=2; //2x1
    int bus_length=3; //3x2
    int auto_length=2; //2x2
    int width = stoi(argv[1]); //5
    int length = stoi(argv[2]); //30
    int count= stoi(argv[3]);
    
    string vehicle[count];
    vehicle[0]=argv[4];
    vehicle[1]=argv[5];
    vehicle[2]=argv[6];
    vehicle[3]=argv[7];
    vehicle[4]=argv[8];
   
    
    string **a;
    a=new string*[length];//7
    for(int i=0;i<length;i++)
            a[i]=new string[width+2];
    
    for(int i=0;i<width+2;i++){
            for(int j=0;j<length;j++){
                    a[j][i]=" ";
            }
    }
    
    if(time==0){
        for(int k=0;k<width+2;k++){
            if(k==0 || k==width+1){
                for(int i=0;i<length;i++){
                    a[i][k]="-";
                }
            }
        }
    }
    //cout<<6<<endl;
    display(a,length,width+2);
    time = time+1;
    usleep(1000000);
    
    
    string **b;
    b=new string*[length];//7
    for(int i=0;i<length;i++)
        b[i]=new string[width+2];
    
    int number=0;
    
    while(number<count){
        int s=0;
        //cout<<vehicle[number]<<endl;
        if(vehicle[number]=="car"){
            while(s<car_length){  
                if(s<car_length){
                    for(int i=0;i<width+2;i++){
                        for(int j=0;j<length;j++){
                            b[j][i]=a[j][i];
                        }
                    }
                    for(int i=0;i<length-1;i++){
                        for(int j=1;j<width+1;j++){
                            a[i+1][j]=b[i][j];
                        }
                    }
                    for(int k=1;k<width+1;k++){
                        if(k==1 || k==2){
                            a[s][k]="C";
                        }
                        else a[s][k]=" ";
                    }
                }
                display(a,length,width+2);
                s++;
                usleep(1000000);
            }
        } 
        
        if(vehicle[number]=="auto"){
            while(s<auto_length){  
                if(s<auto_length){
                    for(int i=0;i<width+2;i++){
                        for(int j=0;j<length;j++){
                            b[j][i]=a[j][i];
                        }
                    }
                    for(int i=0;i<length-1;i++){
                        for(int j=1;j<width+1;j++){
                            a[i+1][j]=b[i][j];
                        }
                    }
                    for(int k=1;k<width+1;k++){
                        if(k==4 || k==5){
                            a[s][k]="A";
                        }
                        else a[s][k]=" ";
                    }
                }
                display(a,length,width+2);
                s++;
                usleep(1000000);
            }
        } 
        
        if(vehicle[number]=="truck"){
            while(s<truck_length){  
                if(s<truck_length){
                    for(int i=0;i<width+2;i++){
                        for(int j=0;j<length;j++){
                            b[j][i]=a[j][i];
                        }
                    }
                    for(int i=0;i<length-1;i++){
                        for(int j=1;j<width+1;j++){
                            a[i+1][j]=b[i][j];
                        }
                    }
                    for(int k=1;k<width+1;k++){
                        if(k==2 || k==3 || k==4){
                            a[s][k]="T";
                        }
                        else a[s][k]=" ";
                    }
                }
                display(a,length,width+2);
                s++;
                usleep(1000000);
            }
        }
        if(vehicle[number]=="bus"){
            while(s<bus_length){  
                if(s<bus_length){
                    for(int i=0;i<width+2;i++){
                        for(int j=0;j<length;j++){
                            b[j][i]=a[j][i];
                        }
                    }
                    for(int i=0;i<length-1;i++){
                        for(int j=1;j<width+1;j++){
                            a[i+1][j]=b[i][j];
                        }
                    }
                    for(int k=1;k<width+1;k++){
                        if(k==2 || k==3){
                            a[s][k]="B";
                        }
                        else a[s][k]=" ";
                    }
                }
                display(a,length,width+2);
                s++;
                usleep(1000000);
            }
        } 
        if(vehicle[number]=="bike"){
            while(s<bike_length){  
                if(s<bike_length){
                    for(int i=0;i<width+2;i++){
                        for(int j=0;j<length;j++){
                            b[j][i]=a[j][i];
                        }
                    }
                    for(int i=0;i<length-1;i++){
                        for(int j=1;j<width+1;j++){
                            a[i+1][j]=b[i][j];
                        }
                    }
                    for(int k=1;k<width+1;k++){
                        if(k==5){
                            a[s][k]="b";
                        }
                        else a[s][k]=" ";
                    }
                }
                display(a,length,width+2);
                s++;
                usleep(1000000);
            }
        }
        if(number==count-1){
            while(s<length){
                for(int i=0;i<width+2;i++){
                    for(int j=0;j<length;j++){
                            b[j][i]=a[j][i];
                    }
                }
                for(int i=0;i<length-1;i++){
                    for(int j=1;j<width+1;j++){
                        a[i+1][j]=b[i][j];
                    }
                }
                for(int j=1;j<width+1;j++){
                        a[0][j]=" ";
                }
                display(a,length,width+2);
                s++;
                usleep(1000000);
            }
        }
    //cout<<number<<endl;
    number++;
}
    return 0;
}

