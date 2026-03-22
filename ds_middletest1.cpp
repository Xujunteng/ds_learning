#include<iostream>

using namespace std;

class queue{
    public:
    int *data;
    int front;
    int rear;
    int size;
    queue();
    void enqueue(int e);
    void dequeue(int &e);
    bool isempty();
};

queue::queue(){
    data=new int [10000];
    front=0;
    rear=0;
    size=0;
}
void queue::enqueue(int e){
    data[++rear]=e;
    size++;
}
void queue::dequeue(int &e){
    e=data[++front];
    size--;
}
bool queue::isempty(){
    return(size==0);
}
int main(){
    queue queue1;
    queue queue2;
    int n;
    cin>>n;
    int e;
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            queue1.enqueue(i);
        }
        for(int i=(n/2+1);i<=n;i++){
            queue2.enqueue(i);
        }
        for(int j=1;j<=n;j++){
            if(j%2!=0){
                queue1.dequeue(e);
            }
            else{
                queue2.dequeue(e);
            }
            cout<<e<<" ";
        }
    }
    else{
        for(int i=1;i<=(n+1)/2;i++){
            queue1.enqueue(i);
        }
        for(int i=(n+1)/2+1;i<=n;i++){
            queue2.enqueue(i);
        }
        for(int j=1;j<=n;j++){
            if(j%2!=0){
                queue1.dequeue(e);
            }
            else{
                queue2.dequeue(e);
            }
            cout<<e<<" ";
        }
    }
    
    return 0;
}