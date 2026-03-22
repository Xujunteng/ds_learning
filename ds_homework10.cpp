#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    public:
    int *data;
    int top;
    int size0;
    stack();
    void push(int x);
    void pop();
    void query();
    void size();
};
stack::stack(){
    data=new int [100000];
    top=-1;
    size0=0;
}

void stack::push(int x){
    data[++top]=x;
    size0++;
}
void stack::pop(){
    if(top!=-1){
    top--;
    size0--;
    return;
    }
    else{
    cout<<"Empty"<<endl;
    return;
    }
}
void stack::query(){
    if(top!=-1){
        cout<<data[top]<<endl;
        return;
    }
    else{
        cout<<"Anguei!"<<endl;
        return;
    }
}
void stack::size(){
    cout<<size0<<endl;
    return;
}

int main(){
    int T=0;
    int n=0;
    int b=0;
    string s;
    string a;
    cin>>T;
    for(int i=0;i<T;i++){
        stack stack1;
        cin>>n;
        cin.ignore();
        for(int j=0;j<n;j++){
            getline(cin,s);
            stringstream ss(s);
            ss>>a;
            if(a=="push"){
                ss>>b;
                stack1.push(b);
            }
            else if(a=="pop"){
                stack1.pop();
            }
            else if(a=="query"){
                stack1.query();
            }
            else if(a=="size"){
                stack1.size();
            }
        }
    }

    return 0;
}