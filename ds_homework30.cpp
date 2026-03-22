#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct BTnode{
    int data;
    BTnode *lchild;
    BTnode *rchild;
    BTnode(int x):data(x),lchild(nullptr),rchild(nullptr){};
};

class BTree{
    public:
    BTnode *root;
    string s="";
    BTree():root(nullptr){};
    BTnode *build(){
        int x;
        if(!(cin>>x)) return nullptr;
        if(x==-1) return nullptr;
        BTnode *r=new BTnode(x);
        r->lchild=build();
        r->rchild=build();
        return r;
    }
    void print(BTnode *r){
        if(r==nullptr){
            s += "-1 ";
            return;
        }
        else{
            s += to_string(r->data) + " ";
            print(r->lchild);
            print(r->rchild);
        }
    }
};

int main(){
    BTree t1;
    BTree t2;
    t1.root=t1.build();
    t2.root=t2.build();
    t1.print(t1.root);
    t2.print(t2.root);
    if(t1.s==t2.s) cout<<"YES";
    else cout<<"NO";
    return 0;
}
