#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    public:
    int *data;
    int top;
    void push(int a);
    int pop();
};

void stack::push(int a){
    data[++top]=a;
}

int stack::pop(){
    return data[top--];
}

int main(){
    stack stack1;
    stack1.data=new int[100000];
    stack1.top=-1;
    int a=0;
    int b=0;
    int c=0;
    ifstream fin("in.txt");
    string token;
    while(getline(fin,token,',')){
        while(!token.empty()&&(token.front()==' '||token.front()=='\n')){
            token.erase(token.begin());
        }
        while(!token.empty()&&(token.back()==' '||token.back()=='\n')){
            token.pop_back();
        }
        if(token.empty()){
            continue;
        }
        if(token=="+"){
            a=stack1.pop();
            b=stack1.pop();
            c=a+b;
            stack1.push(c);
        }
        else if(token=="-"){
            a=stack1.pop();
            b=stack1.pop();
            c=b-a;
            stack1.push(c);
        }
        else if(token=="*"){
            a=stack1.pop();
            b=stack1.pop();
            c=a*b;
            stack1.push(c);
        }
        else if(token=="/"){
            a=stack1.pop();
            b=stack1.pop();
            c=b/a;
            stack1.push(c);
        }
        else {
            try{
                stack1.push(stoi(token));
            }
            catch(...){
                continue;
            }
        }
    }
    
    cout<<stack1.data[stack1.top];

    return 0;
}