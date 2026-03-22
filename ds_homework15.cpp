#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ifstream fin("in.txt");
    char c;
    vector<char> vc;
    while(fin>>c){
        vc.push_back(c);
    }
    for(int i=0;i<vc.size();){
        char current = vc[i];
        int count = 0;
        while(i<vc.size() && vc[i]==current){
            count++;
            i++;
        }
        cout<<current<<" ";
        if(count>1){
        string s=to_string(count);
        for(char x:s){
            cout<<x<<" ";
        }
    }
    }
    return 0;
}