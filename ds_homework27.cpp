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
    string s1;
    string s2;
    BTree():root(nullptr){};
    BTnode *build(){
        int x;
        if(!(cin>>x)){
            s1+="-1,";
            return nullptr;
        }
        if(x==-1) {
            s1 += "-1,";
            return nullptr;
        }
        s1 += to_string(x) + ",";
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
            s2 += "-1,";
            return;
        }
        else{
            s2 += to_string(r->data) + ",";
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
    if(t.s1==t.s2) cout<<"YES";
    else cout<<"NO";
    return 0;
}
