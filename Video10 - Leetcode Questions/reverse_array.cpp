#include<iostream>
using namespace std;

void reverseArray(int arr[] , int size){
    int start = 0;
    int end = size - 1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
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


    reverseArray(even,8);
    reverseArray(odd,5);

    printArray(even,8);
    cout<<endl;
    printArray(odd,5);
}