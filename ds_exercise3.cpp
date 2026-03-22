#include<iostream>
#include<string>
#include<sstream>

using namespace std;

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

int main(){
	int n=0;
	cin>>n;
	cin.get();
	string s;
	getline(cin,s);
	stringstream ss(s);
	int num;
	int e;
	stack stack1;
	stack stack2;
	while(ss>>num){
		stack1.push(num);
	}
	while(stack1.top!=-1){
		stack1.pop(e);
		if(stack2.top==-1){
			stack2.push(e);
		}
		else if(e<stack2.data[stack2.top]){
			stack2.push(e);
		}
		else{
		while(stack2.top!=-1 && e>stack2.data[stack2.top]){
			stack2.pop(num);
			stack1.push(num);
		}
		stack2.push(e);
	}
	}
	while(stack2.top!=-1){
		stack2.pop(e);
		cout<<e<<" ";
	}
	return 0;
}