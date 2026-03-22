#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class queue{
public:
int *data;
int front;
int rear;
queue();
void push(int e);
void pop(int &e);
};

class stack{
public:
int *data;
int top;
stack();
void push(int e);
void pop(int &e);
};

stack::stack(){
    data=new int[10000];
    top=-1;
}

void stack::push(int e){
    data[++top]=e;
}

void stack::pop(int &e){
    e=data[top--];
}

queue::queue(){
    data=new int[10000];
    front=0;
    rear=0;
}
void queue::push(int e){
    if((rear+1)%10000==front){
        return;
    }
    else{
        rear=(rear+1)%10000;
        data[rear]=e;
        return;
    }
}
void queue::pop(int &e){
    if(front==rear){
        return;
    }
    else{
        e=data[front+1];
        front=(front+1)%10000;
        return;
    }
}

int main(){
    int n=0;
    cin>>n;
    bool arr[n];
    cin.ignore();
    queue queue1;
    stack stack1;
    string s;
    getline(cin,s);
    stringstream ss(s);
    int num;
    int e;
    while(ss>>num){
        queue1.push(num);
    }
    for(int i=0;i<n;i++){
        queue1.pop(e);
        if(queue1.data[queue1.front]!=-1){
        stack1.push(e);
        arr[i]=false;
        }
        else{
        arr[i]=true;
        continue;
    }
}
   for(int i=0;i<n;i++){
    if(!arr[i]){
        stack1.pop(e);
        cout<<e<<" ";
    }
    else{
        cout<<-1<<" ";
    }
   }
    return 0;
}