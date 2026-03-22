#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct BTnode{
    int data;
    BTnode *lchild;
    BTnode *rchild;
    BTnode(int c):data(c),lchild(nullptr),rchild(nullptr){};
};

class BTree{
    public:
    BTnode *root;
    unordered_map<int,BTnode*>mp;
    BTnode* createNode(int c){
        if(c==0) return nullptr;
        if(mp.count(c)==0){
            mp[c]=new BTnode(c);
        }
        return mp[c];
    }
    BTree():root(nullptr){}
    void createBTree(){
        int n;
        cin>>n;
        unordered_map<int,bool>isChild;
        for(int i=0;i<n;++i){
            int parent,left,right;
            cin>>parent>>left>>right;

            BTnode *p=createNode(parent);
            BTnode *l=createNode(left);
            BTnode *r=createNode(right);

            p->lchild=l;
            p->rchild=r;

            if(left !=0)isChild[left]=true;
            if(right !=0)isChild[right]=true;
        }
        for(auto& kv:mp){
            if(isChild.count(kv.first)==0){
                root=kv.second;
                break;
            }
        }
    }
    int cnt(BTnode *r,int &self){
        if(r->lchild==nullptr&&r->rchild==nullptr) return self;
        else{
            ++self;
            if(!r->rchild&&r->lchild) return cnt(r->lchild,self);
            if(!r->lchild&&r->rchild) return cnt(r->rchild,self);
            else return min(cnt(r->lchild,self),cnt(r->rchild,self));
        }
    }
};
int main(){
    BTree t;
    t.createBTree();
    int self=0;
    cout<<t.cnt(t.root,self);
    return 0;
}