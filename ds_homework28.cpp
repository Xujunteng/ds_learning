#include<iostream>
#include<string>

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
    string s;
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
   void swapt(BTnode *r){
        if(r==nullptr) return;
        BTnode* temp=r->lchild;
        r->lchild=r->rchild;
        r->rchild=temp;
        swapt(r->lchild);
        swapt(r->rchild);
    }
    void print(BTnode *r){
        if(r==nullptr){
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
    BTree t;
    t.root=t.build();
    t.swapt(t.root);
    t.print(t.root);
    cout<<t.s;
    return 0;
}
