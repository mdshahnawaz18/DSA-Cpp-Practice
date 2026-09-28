#include<iostream>
using namespace std;

int getSum(int *arr , int n){
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){

    int n;
    cout<<"Enter the value of n : ";
    cin >> n;
    
    //varible size array
    
    int* arr = new int[n];
    
    cout<<"Enter the value of array : ";
    //taking input in array
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    int ans = getSum(arr , n);
    cout<<"The sum of array is : "<<ans<<endl;

    delete[] arr;
    return 0;
}