#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    ifstream fin("in.txt");
    string a;
    string b;
    getline(fin,a);
    getline(fin,b);
    string sa;
    string sb;
    string s;
    for(int i=1;i<=a.length()&&i<=b.length();i++){
        sa=a.substr(0,i);
        sb=b.substr(b.length()-i,i);
        if(sa==sb){
            s=sa;
        }
    }
    if(s==""){
        cout<<0;
    }
    else{
        cout<<s<<" "<<s.length();
    }

    return 0;
}