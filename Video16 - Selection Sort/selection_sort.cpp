#include<iostream>
using namespace std;

int selectionSort(int arr1[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr1[j]< arr1[minIndex]){
                minIndex=j;
            }
        }
        swap(arr1[i],arr1[minIndex]);
    }
}

int main(){

    int arr1[6] = {4,6,2,1,3,12};

    // cout<<"Before Sorting : "<<arr1;
    cout<<"After Sorting : "<<selectionSort(arr1 , 6);

    return 0;
}