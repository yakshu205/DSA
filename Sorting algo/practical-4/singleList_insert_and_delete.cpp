#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
     int data;
     Node* next;
     Node(int val){
        data = val;
        next = NULL;
     }
};

class LinkedList{
      public:
    unordered_map<int,Node*>m;
      Node* head;
      Node* tail;
      LinkedList(){
        head = tail = NULL;
      }
    
      //*******************************************part-1 of prectical-1 start***************************************************************
 
      //insert at front_______________________;
      void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;  
        }
      }


      //insert at back__________________________________;
      void push_back(int val){
        Node* newNode = new Node(val);\
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;  
        }
      }


      //PUSH AT ANY POSITION __________________________;

      void push_at(int pos,int val){
          
          int co=1;
        Node* newNode= new Node(val);
        Node* prev=head;
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        

        if(head == NULL){
            head = tail = newNode;
        }
       
            while(co < pos-1){
                prev = prev->next;
                co++;
            }

             if (prev == NULL) {
            cout<<"Invalid Position"<<endl;
            delete newNode;
            return;
        }
            
            newNode->next = prev->next;
            prev->next = newNode;
        
         
      }

      //find length of Linked List___________________________________;

      int length(){
        Node* temp = head;
        int count = 0;

        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        return count;
      }

      //*******************************************part-1 of prectical-1 endss***************************************************************







    // ********************************************* //part-2 of practical 1 start***************************************************************************************************************
       void remove(int val){
         
        if (head == NULL) {
        cout<<"List is Empty"<<endl;
        return;
           }
             
           if(head->data == val){
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
              }
           
              Node* prev = head;
              
              while(prev->next != NULL && prev->next->data != val){
                      prev = prev->next;
              }

                if (prev->next == NULL) {
                       cout<<"Value Not Found"<<endl;
                       return;
                  }

              Node* temp = prev->next;
              prev->next=temp->next;
              temp->next=NULL;
              delete temp;

       }

       

    void reverse_print(Node* temp){
        if(temp == NULL){
            cout<<"NULL-->";
            return;
        }
        reverse_print(temp->next);
        cout<<temp->data<<"-->";
          
    }

      void print(){
        Node*temp = head;
            
        while(temp != NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"NULL";
      }

 // ********************************************* //part-2 of practical 1 ends***************************************************************************************************************

};

int main(){
    LinkedList ll;

    //push at front
    

    //Push At Back
      ll.push_back(1);

     ll.push_back(2);

      ll.push_back(3);

       ll.push_back(4);

       ll.push_back(5);

      int n = ll.length();

    //push At Any Position
       ll.push_at(3,20);
      
    //Print List
       ll.print();

       cout<<"\n*********************\n";

      ll.remove(20);
       ll.print();
           
       cout<<"\n*********************\n";
       
          ll.reverse_print(ll.head);

}