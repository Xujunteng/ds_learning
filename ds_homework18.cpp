#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int>getNext(string t){
    int m=t.length();
    vector<int> next(m,0);
    int j=0;
    for(int i=1;i<m;i++){
        while(j>0&&t[i]!=t[j]){
            j=next[j-1];
        }
        if(t[i]==t[j]){
            j++;
        }
        next[i]=j;
    }
    return next;
}
int KMPcount(string s,string t){
    if(t.empty()){
        return 0;
    }
    vector<int>next=getNext(t);
    int n=s.length();
    int m=t.length();
    int j=0;
    int count=0;
    for(int i=0;i<n;i++){
        while(j>0&&s[i]!=t[j]){
            j=next[j-1];
        }
        if(s[i]==t[j]){
            j++;
        }
        if(j==m){
            j=next[j-1];
            count++;
        }
    }
    return count;
}
int main(){
    string t;
    string s;
    getline(cin,t);
    getline(cin,s);
    cout<<KMPcount(s,t);
    return 0;
}