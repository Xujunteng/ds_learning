#include<iostream>
#include<string>

using namespace std;

struct BTnode{
    char data;
    BTnode *lchild;
    BTnode *rchild;
    BTnode(char x):data(x),lchild(nullptr),rchild(nullptr){};
};

class BTree{
    public:
    BTnode* root;
    string s0="";
    BTree():root(nullptr){};
    BTnode *build(){
        char x;
        if(!(cin>>x)) return nullptr;
        if(x=='#') return nullptr;
        BTnode *r=new BTnode(x);
        r->lchild=build();
        r->rchild=build();
        return r;
    }
    BTnode *copy(string s,int& i){
        if(i>=(int)s.length()||s[i]=='#'){
            ++i;
            return nullptr;
        }
        BTnode *r=new BTnode(s[i]);
        ++i;
        r->lchild=copy(s,i);
        r->rchild=copy(s,i);
        return r;
    }
    void preord(BTnode *r){
        if(r==nullptr){
            s0+='#';
            return;
        }
        s0+=r->data;
        preord(r->lchild);
        preord(r->rchild);
        return;
    }
    void midord(BTnode *r){
        if(r==nullptr) return;
        midord(r->lchild);
        s0+=r->data;
        s0+=' ';
        midord(r->rchild);
        return;
    }
};

int main(){
    BTree t1;
    BTree t2;
    t1.root=t1.build();
    t1.preord(t1.root);
    int i=0;
    t2.root=t2.copy(t1.s0,i);
    t2.midord(t2.root);
    cout<<t2.s0;
    return 0;
}