#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:

     vector<int>leftview(Node* root){
        vector<int>ans;
       if(root == NULL) {
             return;
        }
       map<int/*level*/,int/*node ka data*/>m;
        queue<pair<Node*,int/*level*/>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
          pair<Node*,int>temp=q.front();
          q.pop();
          Node* frontNode=temp.first;
          int level=temp.second;
           if(m.find(level)==m.end()){
            m[level]=root->val;
           }

           if(frontNode->left){
              q.push(make_pair(frontNode->left,level+1));
           }

           if(frontNode->right){
              q.push(make_pair(frontNode->right,level+1));
           }

        }

        for(auto var : m){
           ans.push_back(var.second);
        }
         return ans;
     }

};