#include<iostream>
#include<queue>

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
    void midord(BTnode *r){
        if(r==nullptr) return;
        midord(r->lchild);
        cout<<r->data<<" ";
        midord(r->rchild);
    }
    void lasord(BTnode *r){
        if(r==nullptr) return;
        lasord(r->lchild);
        lasord(r->rchild);
        cout<<r->data<<" ";
    }
    void levord(BTnode *r){
        queue<BTnode*> q;
        q.push(r);
        while(!q.empty()){
            BTnode *cur=q.front();
            cout<<cur->data<<" ";
            q.pop();
            if(cur->lchild)q.push(cur->lchild);
            if(cur->rchild)q.push(cur->rchild);
        }
    }
};

int main(){
    BTree t;
    t.root=t.build();
    t.midord(t.root);
    cout<<endl;
    t.lasord(t.root);
    cout<<endl;
    t.levord(t.root);
    cout<<endl;
    return 0;
}