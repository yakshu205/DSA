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
class Stack{
  public:
    Node* topNode=NULL;
    void push(int val){
        Node* newNode=new Node(val);
        newNode->next=topNode;
        topNode=newNode;
    }
    void pop(){
        if(topNode==NULL){
            cout<<"Stack Is Empty"<<endl;
            return;
        }
        Node* temp=topNode;
        topNode=topNode->next;
        temp->next=NULL;
        delete temp;
    }
    int top(){
        if(topNode==NULL){
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return topNode->data;
    }
    void print(){
        if(topNode==NULL){
            cout<<"Stack Is Empty"<<endl;
            return;
        }
        Node* temp=topNode;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.print();
    cout<<"Top: "<<st.top()<<endl;
    st.pop();
    st.pop();
    st.print();
    cout<<"Top: "<<st.top()<<endl;
}