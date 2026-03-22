#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    public:
    char *data;
    int top;
    stack();
    void push(char e);
    void pop();
};
stack::stack(){
    data=new char[100000];
    top=-1;
}
void stack::push(char e){
    data[++top]=e;
}
void stack::pop(){
    top--;
}

int main(){
    bool pipei=true;
    bool exist=false;
    stack stack1;
    string s;
    getline(cin,s);
    stringstream ss(s);
    char c;
    while(ss>>c){
        if(c=='@'){
            exist=true;
            break;
        }
        stack1.push(c);
    }
    while(ss>>c){
        if(c==stack1.data[stack1.top]){
            stack1.pop();
        }
        else{
            pipei=false;
            break;
        }
    }
    if(pipei&&exist){
        cout<<"1";
        }
    else{
        cout<<"0";
    }
    return 0;
}