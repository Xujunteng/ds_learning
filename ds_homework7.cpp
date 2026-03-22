#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct Stack{
    char* data;
    int top;
};



int main(){
    bool Yes=true;
    int MaxSize=1000;
    Stack *stack=new(Stack);
    stack->data=new char[MaxSize];
    stack->top=-1;
    string s;
    getline(cin,s);
    stringstream ss(s);
    char c;
    while(ss>>c){
    if(c=='{'||c=='['||c=='('){
        stack->top++;
        stack->data[stack->top]=c;
    }
     if(c=='}'){
        if(stack->top==-1){
            Yes=false;
            break;
            
        }
            else if(stack->data[stack->top]!='{'){
                Yes=false;
                break;
                
            }
            else {
                stack->top--;
            }
        }
        if(c==')'){
        if(stack->top==-1){
            
            Yes=false;
            break;
        }
            else if(stack->data[stack->top]!='('){
                
                Yes=false;
                break;
            }
            else {
                stack->top--;
            }
        }
        if(c==']'){
        if(stack->top==-1){
           
            Yes=false;
            break;
        }
            else if(stack->data[stack->top]!='['){
               
                Yes=false;
                break;
            }
            else {
                stack->top--;
            }
        }
    }
    if(Yes&&stack->top==-1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}