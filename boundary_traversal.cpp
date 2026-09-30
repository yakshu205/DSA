#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


bool isLeaf(Node* root) {
    return (root->left == nullptr && root->right == nullptr);
}

void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }
      
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}


void addLeaves(Node* root, vector<int>& res) {
    if (root == nullptr) return;
    
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    
 
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}


void addRightBoundary(Node* root, vector<int>& res) {
   if (root == nullptr) return;
    
    if (isLeaf(root)) {
        return;
    }

 if (root->right) addRightBoundary(root->right, res);
    else{
        addRightBoundary(root->lest, res);
    }
}


vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (root == nullptr) return res;
    
    
    if (!isLeaf(root)) {
        res.push_back(root->data);
    }
    
   
    addLeftBoundary(root, res);
    
    
    addLeaves(root, res);
    
    addRightBoundary(root, res);
    
    return res;
}