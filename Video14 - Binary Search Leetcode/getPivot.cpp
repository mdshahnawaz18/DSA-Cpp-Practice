#include<iostream>
using namespace std;

int getPivot(int arr[],int size){
    int s = 0;
    int e = size-1;
    int mid = s +(e-s)/2;
    while(s<e){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int main(){

    int arr1[5] = {4,5,8,1,2};
    cout<<"Pivot Element is at index "<<getPivot(arr1,5)<<endl;

    int arr2[10] = {12,15,18,80,122,144,2,4,7,8};
    cout<<"Pivot Element is at index "<<getPivot(arr2,10)<<endl;
    
}