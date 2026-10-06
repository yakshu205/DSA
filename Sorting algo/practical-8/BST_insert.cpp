#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* left;
     Node* right;

     Node(int val){
        data=val;
        left=NULL;
        right=NULL;
     }
};

class BST{
  public:

    Node* insertNode(Node* root,int val){
        if(root==NULL){
            return new Node(val);
        }

        if(val<root->data){
            root->left=insertNode(root->left,val);
        }
        else{
            root->right=insertNode(root->right,val);
        }

        return root;
    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main(){

    BST tree;
    Node* root=NULL;

    root=tree.insertNode(root,50);
    root=tree.insertNode(root,30);
    root=tree.insertNode(root,70);
    root=tree.insertNode(root,20);
    root=tree.insertNode(root,40);
    root=tree.insertNode(root,60);
    root=tree.insertNode(root,80);

    cout<<"Inorder: ";
    tree.inorder(root);
    cout<<endl;
}