#include<iostream>
#include<string>
#include<stack>
#include<cctype>

using namespace std;

struct BTnode{
    char data;
    BTnode* lchild;
    BTnode* rchild;
    BTnode(char c):data(c),lchild(nullptr),rchild(nullptr){};
};

class BTree{
    public:
    BTnode* root;
    bool left=false;
    bool right=false;
    stack<BTnode*> bd;
    BTree():root(nullptr){};
    BTnode* build(string s,int &i){
        BTnode *last=nullptr;
        for(;i<s.size();++i){
        if(isalpha(s[i])){
            BTnode *r=new BTnode(s[i]);
            if(!root) root=r;
            if(left) bd.top()->lchild=r;
            if(right) bd.top()->rchild=r;
            last =r;
        }
        else if(s[i]=='(') {
            left=true;
            right=false;
            bd.push(last);
        }
        else if(s[i]==','){
            left=false;
            right=true;
        }
        else if(s[i]==')'){
            bd.pop();
        }
    }
    return root;
    };
    void lasord(BTnode *r){
        if(r==nullptr) return;
        lasord(r->lchild);
        lasord(r->rchild);
        cout<<r->data;
    }
};


int main(){
    BTree t;
    string s;
    int i=0;
    cin>>s;
    t.root=t.build(s,i);
    t.lasord(t.root);
    return 0;
}