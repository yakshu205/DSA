#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:

     vector<int>verticalOrder(Node* root){
         map<int,map<int,vector<int>>>m;
         queue<pair<Node*,pair<int,int>>>q;

         if(root==NULL){
            return;
         }

         q.push(make_pair(root,make_pair(0,0)));

         while(!q.empty()){
            pair<Node*,pair<int,int>>yak=q.front();
               q.pop();
            Node* fnode=yak.first;
            
            int hd=yak.second.first;
            int level=yak.second.second;

            m[hd][level].push_back(fnode->val);

            if(fnode->left){
                q.push(make_pair(fnode->left,make_pair(hd-1,level+1)));
            }
            if(fnode->right){
                q.push(make_pair(fnode->right,make_pair(hd+1,level+1)));
            }
         }
         vector<int>ans;
         for(auto var : m){
            for(auto va : var.second){
                for(auto v : va.second){
                      ans.push_back(v);
                }
            }
         }

         return ans;
     }

};