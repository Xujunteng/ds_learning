#include<iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

void buildlist(Node *&head,Node *&tail){
    int a=0;
do{
        Node *node=new(Node);
        cin>>a;

        if(a==-1)
            return;

        node->value=a;
        node->next=nullptr;
        if(head==nullptr){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }

    }while(1);
    return;
}

void sortlist(Node *&head1,Node *&tail1,Node *&head2,Node *&tail2,Node *&head,Node *&tail){
    Node *p=head1;
    Node *q=head2;

   while(p!=nullptr&&q!=nullptr){
        if(p->value<q->value){
            if(head==nullptr){
            head=p;
            tail=p;
            p=p->next;
        }
        else{
            tail->next=p;
            tail=p;
            p=p->next;
        } 
    }
        else{
            if(head==nullptr){
            head=q;
            tail=q;
            q=q->next;
        }
        else{
            tail->next=q;
            tail=q;
            q=q->next;
        }
        }
        }
        if(p==nullptr){
            if(head==nullptr){
                head=q;
            }
            else{tail->next=q;
            tail=tail2;
            }
        }
        else{
            if(head==nullptr){
                head=p;
            }
            else{tail->next=p;
            tail=tail1;
            }
        
    }
        return;
    }

void printlist(Node *head){
    Node *p=head;
    while(p!=nullptr){
        cout<<p->value<<" ";
        p=p->next;
    }
    return;
}

int main(){

    Node *head1=nullptr;
    Node *tail1=nullptr;

    Node *head2=nullptr;
    Node *tail2=nullptr;

    Node *head=nullptr;
    Node *tail=nullptr;

    buildlist(head1,tail1);
    buildlist(head2,tail2);

    sortlist(head1,tail1,head2,tail2,head,tail);

    printlist(head);

    return 0;
}