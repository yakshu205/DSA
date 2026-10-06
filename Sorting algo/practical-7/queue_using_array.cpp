#include<iostream>
using namespace std;
class Queue{
  public:
    int arr[100];
    int front=0;
    int rear=-1;
    void push(int val){
        if(rear==99){
            cout<<"Queue Is Full"<<endl;
            return;
        }
        rear++;
        arr[rear]=val;
    }
    void pop(){
        if(front>rear){
            cout<<"Queue Is Empty"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front>rear){
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    void print(){
        if(front>rear){
            cout<<"Queue Is Empty"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    cout<<"Front: "<<q.peek()<<endl;
    q.pop();
    q.pop();
    q.print();
    cout<<"Front: "<<q.peek()<<endl;
}