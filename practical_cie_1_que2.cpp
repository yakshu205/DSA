#include<bits/stdc++.h>
using namespace std;
  
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
    };

    class ListNode{
        public:
            Node* head;
            Node* tail;
            ListNode(){
                head=NULL;
                tail=NULL;
            }
            void push_front(int val){ // push from front
                Node* newNode=new Node(val);
                if(head==NULL){
                    head=newNode;
                    tail=newNode;
                    return;
                }
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }

    void push_back(int val){ // push from back
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
    void pop_head(){ // pop from head
       if(head==NULL){
                cout<<"List is empty"<<endl;
              }
              else{
                    Node* temp=head;
                    head=head->next;
                    temp->next=NULL;
                    temp->next->prev=NULL;
                    delete temp;

              }
    }

    void remove_at(int val){ // remove specific tickit id
              if(head==NULL){
                cout<<"List is empty"<<endl;
              }
              else{
                Node* curr= head;
                if(curr->data == val){
                    pop_head();
                }

                while( curr->next!=NULL && curr->next->data!=val ){
                      curr=curr->next;
                }
                if(curr->next ==NULL){
                    cout<<"Value not Found"<<endl;
                }
                else{
                    curr->next->next->prev=curr;
                    curr=curr->next;
                    curr->prev->next=curr->next;
                    curr->next=NULL;
                    curr->prev=NULL;
                    delete curr;
                }
              }
    }

      void addValue(int val,int prio){ // add value according to the priority 
        if(prio < 3){
            push_front(val);

        }
        else{
            push_back(val);
        }


    }

   void changePrio(int val,int prio){ // change priority and rearange
         if(head==NULL){
                cout<<"List is empty"<<endl;
              }
              else{
                Node* curr= head;

                while( curr->next!=NULL && curr->next->data!=val ){
                      curr=curr->next;
                }
                if(curr->next ==NULL){
                    cout<<"Value not Found"<<endl;
                }
                else{
                    //for delete that node firt;
                    curr->next->next->prev=curr;
                    curr=curr->next;
                    curr->prev->next=curr->next;
                    curr->next=NULL;
                    curr->prev=NULL;
                    delete curr;

                    //Then for re arrange the node;
                     if(prio < 3){
                           push_front(val);

                          }
                     else{
                       push_back(val);
                     }

                }

              }
            
    }

    void display(){ // display forward direction
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" <--> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void display_rev(Node* head){ // reverse print
      
        Node* temp=head;
        if(temp==NULL){
            return;
        }
        display_rev(temp->next);
        cout<<temp->data<< " <--> ";
    }

    void current(){ // current Node
        Node* temp = head;
        cout<<temp->data;
    }
    };
int main(){
    ListNode ll;
    ll.addValue(101,1); // 101
    ll.addValue(103,5); // 101 <-> 103
    ll.addValue(102,2); // 102 <-> 101 <-> 103 aavi rite agal chalse ;
    ll.addValue(107,1); 
    ll.addValue(104,4);
    ll.addValue(108,3);
    ll.addValue(109,5);
    ll.display();
    cout<<"\n*********************************************************************\n";
    cout<<"\n After removing Node 104\n";

    ll. remove_at(104);
    ll.display();

    cout<<"\n*********************************************************************\n";
    cout<<"\n After changing priority of  Node 108 to prio=5 \n";
     ll.changePrio(108,5);

     ll.display();

     cout<<"\n*********************************************************************\n";
     cout<<"\n After changing priority of  Node 102 to prio=3\n";
     ll.changePrio(102,3);

     ll.display();

     cout<<"\n*********************************************************************\n";
    cout<<"\n reverese Print \n";

    ll.display_rev(ll.head);

    cout<<"\n*********************************************************************\n";

    cout<<"current Ticket Id  : "<< ll.head->data<<endl;

}