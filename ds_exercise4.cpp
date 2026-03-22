#include<iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    stack<char> st;
    char c;
    while(ss>>c){
        if(isdigit(c)){
            cout<<c<<" ";
        }
        else{
            if(st.empty()||st.top()=='('){
                st.push(c);
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(st.top()!='('){
                    cout<<st.top()<<" ";
                    st.pop();
                }
                st.pop();
            }
            else if(c=='*'||c=='/'){
                while(!st.empty()&&(st.top()=='*'||st.top()=='/')){
                    cout<<st.top()<<" ";
                    st.pop();
                }
                st.push(c);
            }
            else if(c=='+'||c=='-'){
                while(!st.empty()&&st.top()!='('){
                    cout<<st.top()<<" ";
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}