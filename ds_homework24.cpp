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
    BTree():root(nullptr){};
    unordered_map<char,BTnode*>mp;
    unordered_map<int,int>ump;
    unordered_map<char,bool>isChild;
    BTnode* createBTnode(char c){
        if(c=='#') return nullptr;
        if(mp.count(c)==0){
            mp[c]=new BTnode(c);
            return mp[c];
        }
        return mp[c];
    }
    void createBTree(){
        int n;
        cin>>n;
        char parent;
        char lchild;
        char rchild;
        for(int i=0;i<n;i++){
            cin>>parent>>lchild>>rchild;
            BTnode *p=createBTnode(parent);
            BTnode *l=createBTnode(lchild);
            BTnode *r=createBTnode(rchild);
            p->lchild=l;
            p->rchild=r;
            if(lchild!='#') isChild[lchild]=true;
            if(rchild!='#') isChild[rchild]=true;   
        }
        for(auto&kv:mp){
            if(!isChild.count(kv.first)){
                root=kv.second;
                break;
            }
        }
    }
    int height(BTnode* r){
        if(r==nullptr) return 0;
        else return max(height(r->lchild)+1,height(r->rchild)+1);
    }

    void preorderCount(BTnode *r,int k){
        if(r==nullptr) return;
        else{
            ump[k]++;
            ++k;
            preorderCount(r->lchild,k);
            preorderCount(r->rchild,k);
        }
    }
};

int main(){
    BTree t;
    t.createBTree();
    int n=t.height(t.root);
    for(int i=1;i<=n;i++){
        t.ump[i]=0;
    }
    t.preorderCount(t.root,1);
    int maxWidth=0;
    for(int i=1;i<=n;i++){
        if(t.ump[i]>maxWidth) maxWidth=t.ump[i];
    }
    cout<<maxWidth;
    return 0;
}