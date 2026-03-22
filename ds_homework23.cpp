#include<iostream>
#include<unordered_map>

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
    unordered_map<char,BTnode*>mp;

    BTnode* createNode(char c){
        if(c=='#') return nullptr;
        if(mp.count(c)==0){
            mp[c]=new BTnode(c);
        }
        return mp[c];
    }
    BTree():root(nullptr){}
    void createBTree(){
        int n;
        cin>>n;
        unordered_map<char,bool>isChild;
        for(int i=0;i<n;++i){
            char parent,left,right;
            cin>>parent>>left>>right;

            BTnode *p=createNode(parent);
            BTnode *l=createNode(left);
            BTnode *r=createNode(right);

            p->lchild=l;
            p->rchild=r;

            if(left !='#')isChild[left]=true;
            if(right !='#')isChild[right]=true;
        }
        for(auto& kv:mp){
            if(isChild.count(kv.first)==0){
                root=kv.second;
                break;
            }
        }
    }
    void preorderPrint(BTnode *r){
        if(r==nullptr) return;
        else{
            cout<<r->data<<' ';
            preorderPrint(r->lchild);
            preorderPrint(r->rchild);
        }
    }
};
int main(){
    BTree t;
    t.createBTree();
    char x;
    cin>>x;
    if(!t.mp[x]) return 0;
    t.preorderPrint(t.mp[x]->lchild);
    t.preorderPrint(t.mp[x]->rchild);
    return 0;
}