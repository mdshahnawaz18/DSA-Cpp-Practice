#include<iostream>
using namespace std;

void reachHome(int src , int dest){

    cout<<"Source is "<<src<<" and Destination is "<<dest<<endl;

    if(src == dest){
        cout<<"Pahuch Gaya"<<endl;
        return;
    }
    src++;

    return reachHome(src , dest);

}

int main(){
    
    int src = 1;
    int dest = 10;

    reachHome(src , dest);

    return 0;
}