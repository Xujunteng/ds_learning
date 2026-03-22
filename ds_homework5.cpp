#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    vector<int> a;
    unordered_set<int> b;
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i:arr){
        if(b.insert(i).second)
            a.push_back(arr[i]);
    }

    if(a.empty())
        cout<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<' ';
        
    return 0;
}