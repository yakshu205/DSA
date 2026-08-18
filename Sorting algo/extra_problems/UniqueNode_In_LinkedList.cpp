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

   void print(){
        Node*temp = head;
            
        while(temp != NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"NULL";
      }

    void findUniqueNode(){
              unordered_map<int,int>m;
           
            Node* temp=head;
            if(head==NULL){
                cout<<"List Is Empty"<<endl;
            }
            else{
            while(temp != NULL){
                m[temp->data]++;
                temp=temp->next;
            }
            vector<int>ans;
          temp=head;
          while(temp != NULL){
             auto y=m.find(temp->data);
             if(y !=m.end() && y->second ==1 ){
                ans.push_back(temp->data);
             }
             temp=temp->next;
          }

         int n=ans.size();
         for(int i=0;i<n;i++){
            cout<<ans[i]<<" , ";
         }
    }
    }

 // ********************************************* //part-2 of practical 1 ends***************************************************************************************************************

};

int main(){
    LinkedList ll;

    //push at front
    

    //Push At Back
      ll.push_back(1);

     ll.push_back(2);

      ll.push_back(1);

       ll.push_back(5);

       ll.push_back(5);
       ll.push_back(3);
    
       ll.findUniqueNode();
    

}