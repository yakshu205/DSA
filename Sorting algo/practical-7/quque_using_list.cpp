#include<iostream>
using namespace std;
class Node{
    public:
     int data;
     Node* next;
     Node(int val){
        data=val;
        next=NULL;
     }
};
class Queue{
  public:
    Node* front=NULL;
    Node* rear=NULL;
    void push(int val){
        Node* newNode=new Node(val);
        if(front==NULL){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue Is Empty"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        temp->next=NULL;
        delete temp;
        if(front==NULL){
            rear=NULL;
        }
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        return front->data;
    }
    void print(){
        if(front==NULL){
            cout<<"Queue Is Empty"<<endl;
            return;
        }
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
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