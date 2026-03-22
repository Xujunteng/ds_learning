#include<iostream>
 
using namespace std;

struct Node{
    int value;
    Node *next;
};

int main(){
    Node *head=nullptr;
    int k=0;
    cin>>k;
    int a=0;
    int n=0;
    while(cin>>a&&a!=-1){
        Node *node=new(Node);
        node->value=a;
        if(head==nullptr){
            node->next=nullptr;
            head=node;
        }
        else{
            node->next=head->next;
            head->next=node;
        }
        n++;
    }
    Node *p=head;
    if(k>n){
        cout<<"-1";
    }
    else{
    for(int i=0;i<k;i++){
        p=p->next;
    }
    cout<<p->value;
    }
    return 0;
}