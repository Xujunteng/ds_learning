#include<iostream>
#include<string>

using namespace std;

struct BTnode{
    char data;
    BTnode *lchild;
    BTnode *rchild;
    BTnode(char c):data(c),lchild(nullptr),rchild(nullptr){};
};

class BTree{
    public:
    BTnode *root;
    BTree():root(nullptr){};
    BTnode* build(string s,int &i){
        if(i>=(int)s.length()||s[i]=='#'){
            ++i;
            return nullptr;
        }
        BTnode* root =new BTnode(s[i]);
        ++i;
        root->lchild=build(s,i);
        root->rchild=build(s,i);
        return root;
    }
    void swapt(BTnode *r){
        if(r==nullptr) return;
        BTnode* temp=r->lchild;
        r->lchild=r->rchild;
        r->rchild=temp;
        swapt(r->lchild);
        swapt(r->rchild);
    }
    void print(BTnode *r,string &s){
        if(r==nullptr){
            s+='#';
            return;
        }
        else{
            s+=r->data;
            print(r->lchild,s);
            print(r->rchild,s);
        }
    }
};

int main(){
    BTree t;
    string s;
    string s0;
    cin>>s;
    int i=0;
    t.root=t.build(s,i);
    t.swapt(t.root);
    t.print(t.root,s0);
    if(s==s0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}