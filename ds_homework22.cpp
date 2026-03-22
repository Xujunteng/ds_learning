#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct BTnode{
    char data;
    BTnode *lchild;
    BTnode *rchild;

    BTnode():lchild(NULL),rchild(NULL){};
    BTnode(char d){
        data=d;
        lchild=rchild=NULL;
    }
};

class BTree{
    public:
    BTnode *root;
    int count(){
        return count(root);
    }
    int count(BTnode *root){
    if(root==NULL)
    return 0;

    bool hasleft=(root->lchild!=NULL);
    bool hasright=(root->rchild!=NULL);

    int self=(hasleft^hasright)?1:0;
    return self+count(root->lchild)+count(root->rchild);
}
    BTree():root(NULL){};
    void createBTree(string s);
};

void BTree::createBTree(string s){
        if(s.empty()||s[0]=='#'){
            return;
        }
        int n=(int)s.length();
        vector<BTnode*>pos(n+1,NULL);

        for(int i=1;i<=n;++i){
            if(s[i-1]!='#'){
                pos[i]=new BTnode(s[i-1]);
            }
        }
        for(int i=1;i<=n;++i){
            if(pos[i]==NULL)continue;

            int li=2*i;
            int ri=2*i+1;

            if(li<=n)pos[i]->lchild=pos[li];
            if(ri<=n)pos[i]->rchild=pos[ri];
        }
        root=pos[1];
}


int main(){
    string s;
    cin>>s;
    BTree t;
    t.createBTree(s);
    cout<<t.count();
    return 0;
}
