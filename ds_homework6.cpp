#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int value;
    Node *next;
};

int main(){
    Node *head=nullptr;
    Node *tail=nullptr;
    
    int n=0;
    int m=0;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }

    for(int i=0;i<n;i++){
        Node *node=new(Node);
        node->value=i+1;
        if(head==nullptr){
            head=node;
            head->next=nullptr;
        }
        else if(head->next==nullptr){
            head->next=node;
            node->next=head;
            tail=node;
        }
        else{
            tail->next=node;
            node->next=head;
            tail=node;
        }
    }

    Node *p=tail;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            p=p->next;
        }
        cout<<p->next->value<<' ';
        if(p->next->next!=p)
        p->next=p->next->next;
        else
            cout<<p->value;
    }
    return 0;
}