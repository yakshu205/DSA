#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
     Node* prev;

     Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
     }
};

class LinkedList{
  public:
    Node* head=NULL;
    Node* tail=NULL;

    //push at front
    void push_front(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;

            head->next=head;
            head->prev=head;
        }
        else{
            newNode->next=head;
            newNode->prev=tail;

            head->prev=newNode;
            tail->next=newNode;

            head=newNode;
        }
    }

    //push at back
    void push_back(int val){
        Node* newNode= new Node(val);

        if(head==NULL){
            head=tail=newNode;

            head->next=head;
            head->prev=head;
        }
        else{
            newNode->prev=tail;
            newNode->next=head;

            tail->next=newNode;
            head->prev=newNode;

            tail=newNode;
        }
    }

    //pop at head
    void pop_front(){

        if(head==NULL){
            cout<<"List Is Empty"<<endl;
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=head;

            head=head->next;

            head->prev=tail;
            tail->next=head;

            temp->next=NULL;
            temp->prev=NULL;

            delete temp;
        }
    }

    //pop_back
    void pop_back(){

        if(head==NULL){
            cout<<"List Is Empty"<<endl;
            return;
        }

        if(head==tail){
            delete tail;
            head=tail=NULL;
        }
        else{
            Node* temp=tail;

            tail=tail->prev;

            tail->next=head;
            head->prev=tail;

            temp->next=NULL;
            temp->prev=NULL;

            delete temp;
        }
    }

    //print
    void print(){

        if(head==NULL){
            cout<<"List Is Empty"<<endl;
            return;
        }

        cout<<head->data<<" <--> ";

        Node* temp=head->next;

        while(temp != head){
            cout<<temp->data<<" <--> ";
            temp=temp->next;
        }

        cout<<endl;
    }
};

int main(){

     LinkedList dll;

     dll.push_back(1);
     dll.push_back(2);
     dll.push_back(3);
     dll.push_back(5);
     dll.push_back(6);

     dll.push_front(9);
     dll.push_front(10);

     dll.pop_back();
     dll.pop_front();

     dll.print();
}