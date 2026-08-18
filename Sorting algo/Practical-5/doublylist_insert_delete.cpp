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
        }
       else{
           newNode->next=head;
           head->prev=newNode;
           head=newNode;
       }


    }
 
    //posh at back
    void push_back(int val){
        Node* newNode= new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }


    //push at any position
    void push_at(int val , int searchVal){
        Node* newNode =new Node(val);
         
        Node* temp=head;
        while(temp->data != searchVal){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next->prev=newNode;
        newNode->prev=temp;
        temp->next=newNode;

    }


    //pop from front
    void pop_front(){
        if(head==NULL){
            cout<<"LL is Empty"<<endl;
        }

        Node* temp=head;
        head=head->next;
        if(head != NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    //pop at any position
    void pop_at(int val){
        Node* temp=head;
        while(temp->data != val){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;

    }

    // pop from back
    void pop_back(){
      if(head==NULL){
            cout<<"LL is Empty"<<endl;
        }

        Node* temp=tail;
        tail=tail->prev;
        if(tail != NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }   
    

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" <--> ";
            temp=temp->next;
        }
        cout<<"NULL";
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

      dll.push_at(4,3);


      dll.print();
}