#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:

     vector<int>topView(Node* root){
        vector<int>ans;
       if(root == NULL) {
             return;
        }
        map<int/*horizontal distance*/,int/*root ke deta ke liye*/>m;
        queue<pair<Node*,int/*horizontal distnce*/>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            int hd=temp.second;
            Node* fnode=temp.first;
            

            if(m.find(hd)==m.end()){
                m[hd]=root->data;
            }
            if(fnode->left){
                q.push(make_pair(fnode->left,hd-1));
            }
            if(fnode->right){
                q.push(make_pair(fnode->right,hd+1));
            }
        }

        for(auto var : m){
           ans.push_back(var);
        }
         return ans;
     }

};