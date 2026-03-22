#include <iostream>
#include<fstream>

using namespace std;

class player{
    public:
    player();
    bool exist;
    int S;
    int F;
    int X(int i);
};

player::player(){
    exist=true;
}

int player::X(int i){
    int x;
    return x=F+S*(i-1);
}

int main() {
    ifstream in("in.txt");
    int n=0;
    in>>n;
    player*data=new player[n];
    for(int i=0;i<n;i++){
        in>>data[i].F>>data[i].S;
    }
    int max=0;
    int maxi=0;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n;j++){
            if(data[j].exist){
                if(data[j].X(i)>max){
                    max=data[j].X(i);
                    maxi=j;
                }
            }
        }
        cout<<maxi+1<<" ";
        data[maxi].exist=false;
        max=0;
        maxi=0;
    }
 return 0;
}