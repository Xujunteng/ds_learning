#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    public:
    int *data;
    int top;
    stack();
    void push(int x);
    void pop();
    void check();
};
stack::stack(){
    data =new int [1000000];
    top=-1;
}

void stack::push(int x){
    data[++top]=x;
}

void stack::pop(){
    top--;
}

void stack::check(){
    if(top==-1){
        cout<<0<<endl;
    }
    else{
    cout<<data[top]<<endl;
    }
}

int main(){
    stack stack1;
    stack max;
    int N=0;
    cin>>N;
    cin.ignore();
    int a=0;
    string s;
    for(int i=0;i<N;i++){
        getline(cin,s);
        stringstream ss(s);
        ss>>a;
        if(a==0){
            ss>>a;
            stack1.push(a);
            if(max.top==-1){
                max.push(a);
            }
            else if(a>=max.data[max.top]){
                max.push(a);
            }
        }
        else if(a==1){
            if(stack1.top==-1){
                continue;
            }
            else{;
            if(stack1.data[stack1.top]==max.data[max.top]){
                stack1.pop();
                max.pop();
            }
            else{
                stack1.pop();
            }
        }
        }
        else if(a==2){
            max.check();
            }
        }
    

    return 0;
}