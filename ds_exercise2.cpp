#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

void insert(vector<int>&a,int x){
    a.push_back(x);
}

void insert(vector<int>&a,int k,int x){
    if(k<1 || k>static_cast<int>(a.size())+1){
        return;
    }
    int n=static_cast<int>(a.size());
    a.push_back(0);
    for(int i=n;i>=k;i--){
        a[i]=a[i-1];
    }
    a[k-1]=x;
}

void Delete(vector<int>&a,int k){
    if(k<1 || k>static_cast<int>(a.size())){
        return;
    }
    int n=static_cast<int>(a.size());
    for(int i=k-1;i<n-1;i++){
        a[i]=a[i+1];
    }
    a.pop_back();
}

int find(const vector<int>&a,int x){
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int n=0;
    cin>>n;
    string line;
    string a;
    vector<int>r;
    while(getline(cin,line)){
        stringstream s(line);
        s>>a;
        if(a=="INSERT"){
            int num;
            vector<int>b;
            while(s>>num){
                b.push_back(num);
            }
            if(b.size()==1){
                insert(r,b[0]);
            }
            if(b.size()==2){
                insert(r,b[0],b[1]);
            }
        }
        if(a=="DELETE"){
            int num;
            s>>num;
            Delete(r,num);
        }
        if(a=="FIND"){
            int num;
            s>>num;
            cout<<find(r,num)<<endl;
        }
    }
    return 0;
}