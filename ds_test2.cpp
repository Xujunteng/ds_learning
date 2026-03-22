#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
vector<string>a(11);
a[0]="1";
a[1]="1 1";
a[2]="1 2 1";
a[3]="1 3 3 1";
a[4]="1 4 6 4 1";
a[5]="1 5 10 10 5 1";
a[6]="1 6 15 20 15 6 1";
a[7]="1 7 21 35 35 21 7 1";
a[8]="1 8 28 56 70 56 28 8 1";
a[9]="1 9 36 84 126 126 84 36 9 1";
a[10]="1 10 45 120 210 252 210 120 45 10 1";
int n=0;
cin>>n;
if(n<=11){
for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
}
}
    return 0;
}