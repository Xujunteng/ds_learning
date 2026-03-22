#include<iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};

int main(){

    Node *head=new(Node);
    head->next=nullptr;
   

    int value=0;

    while(1){
        cin>>value;
        if(value==-1)
            break;
        else{
            Node *node=new(Node);
            node->value=value;
            node->next=head->next;
            head->next=node;
        }
    }

    Node *p=head->next;
    while(p!=nullptr){
        cout<<p->value<<" ";
        p=p->next;
    }

    return 0;
}