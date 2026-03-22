#include<iostream>
#include<string>

using namespace std;

struct Node{
    int value;
    Node *next;
};

int equal(string a,string b,Node *head1,Node *head2){
    if(a.length()!=b.length()){
        return 0;
    }
    int n=a.length();
    if(n==0)
    return 1;
    int count=0;
    Node *a1=head1;
    Node *b2=head2;
    for(int i=0;i<n;i++){
        Node *check1=a1;
        Node *check2=b2;
        for(int i=0;i<n;i++){
            if(check1->value!=check2->value)
            break;
            else{
                count++;
                check1=check1->next;
                check2=check2->next;
            }
        }
        if(count==n)
        return 1;
        a1=a1->next;
        count=0;
    }
    return 0;
}

int main(){
    Node *head1=nullptr;
    Node *head2=nullptr;
    Node *r=nullptr;

    string a="";
    
    getline(cin,a);

    for(int i=0;i<a.length();i++){
        Node *node=new(Node);
        node->value=int(a[i]);
        if(head1==nullptr){
            head1=node;
            head1->next=nullptr;
        }
        else if(head1->next==nullptr){
            head1->next=node;
            node->next=head1;
            r=node;
        }
        else{
            r->next=node;
            node->next=head1;
            r=node;
        }
    }

    string b="";
    
    getline(cin,b);

    for(int i=0;i<b.length();i++){
        Node *node=new(Node);
        node->value=int(b[i]);
        if(head2==nullptr){
            head2=node;
            head2->next=nullptr;
        }
        else if(head2->next==nullptr){
            head2->next=node;
            node->next=head2;
            r=node;
        }
        else{
            r->next=node;
            node->next=head2;
            r=node;
        }
    }

    cout<<equal(a,b,head1,head2);

    return 0;
}