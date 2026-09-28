#include<iostream>
using namespace std;

void swapAlternate(int arr[] , int size){
    
    for(int i=0; i<size; i+=2){
        if(i+1 <size){
            swap(arr[i],arr[i+1]);
        }

    }

}

void printArray(int arr[] , int size){
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
}


int main(){

    int even[8] = {2,3,5,6,1,0,7,12};
    int odd[5] = {4,3,5,1,7};


    swapAlternate(even,8);
    swapAlternate(odd,5);

    printArray(even,8);
    cout<<endl;
    printArray(odd,5);
}