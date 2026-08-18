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

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }
         else{
                newNode->next=head;
                head=newNode;
                tail->next=head;
          }
    }

    //push at back
    void push_back(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }
        else{
                  
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
    }

    //pop at head
    void pop_front(){
       
        if(head==NULL){
            cout<<"List Is Empty"<<endl;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
         Node* temp=head;
         head=head->next;
         tail->next=head;
         temp->next=NULL;
         delete temp;
        }

    }

    //pop_back
    void pop_back(){
        if(head==NULL){
            cout<<"List Is Empty"<<endl;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=tail;
             while(tail->next != temp){
                tail=tail->next;
             }
             tail->next=head;
             temp->next=NULL;
             delete temp;
        }

    }

    void print(){
        cout<<head->data<<"--> ";
        Node*temp=head->next;
        while(temp != head){
            cout<<temp->data<<"--> ";
            temp=temp->next;
        }
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