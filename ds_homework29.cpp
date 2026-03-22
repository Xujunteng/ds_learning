#include<iostream>
#include<algorithm>

using namespace std;

struct BTnode{
    int data;
    BTnode* lchild;
    BTnode* rchild;
    BTnode(int x):data(x),lchild(nullptr),rchild(nullptr){};
};

class BTree{
    public:
    BTnode *root;
    BTree():root(nullptr){};
    BTnode* build(){
        int x;
        if(!(cin>>x)) return nullptr;
        if(x==-1) return nullptr;
        BTnode *r=new BTnode(x);
        r->lchild=build();
        r->rchild=build();
        return r;
    }
    int count(BTnode *r){
        int cnt=0;
        if(r==nullptr) return cnt;
        return ++cnt+max(count(r->lchild),count(r->rchild));
    }
};

int main(){
    BTree t;
    t.root=t.build();
    cout<<t.count(t.root);
    return 0;
}