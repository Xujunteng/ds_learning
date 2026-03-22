#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    ifstream fin("in.txt");
    string s;
    getline(fin,s);
    string t;
    getline(fin,t);
    bool pipei=false;
    fin>>s>>t;
    for(int i=0;i<s.length();i++){
        for(int j=0;j<t.length();j++){
            if(s[i+j]!=t[j]){
                break;
            }
            if(j==t.length()-1){
                cout<<i;
                pipei=true;
            }
        }
        if(pipei){
            break;
        }
    }
    if(!pipei){
        cout<<-1;
    }
    return 0;
}