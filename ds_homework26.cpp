#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

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
    BTnode* build(){
        int x;
        cin>>x;
        if(x==-1) return nullptr;
        BTnode* root =new BTnode(x);
        root->lchild=build();
        root->rchild=build();
        return root;
    }
    int maxW(){
        if(root==nullptr)return 0;
        queue<BTnode*>q;
        q.push(root);
        int ans=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                BTnode* cur=q.front();
                q.pop();
                if(cur->lchild)q.push(cur->lchild);
                if(cur->rchild)q.push(cur->rchild);
            }
            ans=max(ans,n);
        }
        return ans;
    }
};

    int main(){
        BTree t;
        t.root=t.build();
        cout<<t.maxW();
        return 0;
    }