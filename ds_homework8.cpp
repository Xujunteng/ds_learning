#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    public:
    char *data;
    int top;
    stack(int max);
    void push(char a);
    void pop();
};
stack::stack(int max){
    data=new char[max];
    top=-1;
}
void stack::push(char a){
        top++;
        data[top]=a;
}
void stack::pop(){
   top--;
}


int main(){
    int N;
    cin>>N;
    cin.get();
    stack stack1(N);
    stack stack2(N);
    string a;
    string b;
    char c;
    getline(cin,a);
    stringstream aa(a);
    getline(cin,b);
    stringstream bb(b);
    string tokens[1000]; 
    int m = 0;
    string t;
    while (bb >> t) {
    tokens[m++] = t;
    }
    for (int i = m - 1; i >= 0; --i) {
    stack2.push(tokens[i][0]);
    }
    while(aa>>c){
        stack1.push(c); 
        while(stack1.top>=0&&stack2.top>=0&&stack1.data[stack1.top]==stack2.data[stack2.top]){
            stack1.pop();
            stack2.pop();
        }
    }
    if(stack2.top==-1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}