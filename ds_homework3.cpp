#include<iostream>

using namespace std;

int main(){

    int n=0;
    cin>>n;
    int arr[n];

    int j=0;
    for(int i=0;i<n;i++){
        cin>>j;
        arr[i]=j;
    }
    
    for(int i=0;i<n/2;i++){
            int temp=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=temp;
        }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}