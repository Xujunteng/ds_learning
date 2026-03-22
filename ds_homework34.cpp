#include<iostream>
#include<string>
#include<vector>
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
    BTnode* root;
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
    bool findPath(BTnode* r,int target,vector<int>& path){
        if(r==nullptr) return false;
        path.push_back(r->data);
        if(r->data==target) return true;
        if(findPath(r->lchild,target,path)) return true;
        if(findPath(r->rchild,target,path)) return true;
        path.pop_back();
        return false;
    }
    int lcaByPath(int p,int q){
        vector<int> pathP;
        vector<int> pathQ;
        if(!findPath(root,p,pathP)) return -1;
        if(!findPath(root,q,pathQ)) return -1;
        int len=min((int)pathP.size(),(int)pathQ.size());
        int ans=-1;
        for(int i=0;i<len;i++){
            if(pathP[i]==pathQ[i]) ans=pathP[i];
            else break;
        }
        return ans;
    }
};

int main(){
    int p;
    int q;
    cin>>p>>q;
    BTree t;
    t.root=t.build();
    cout<<t.lcaByPath(p,q);
    return 0;
}