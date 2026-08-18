#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    vector<int> v;
    int minelement=-1;
    MinStack() {}

    void push(int val) { 
        if(v.size()==0){
            v.push_back(val);
        }
        else{
               if(v[v.size()-1]>val){
                    minelement = val;
                    v.push_back(val);
               }
               else{
                v.push_back(val);
               }
        }
    }

    void pop() {
        if (v.size() != 0)
            v.pop_back();
    }

    int top() {
        if (v.size() != 0)
            return v[v.size() - 1];
    }

    int getMin() {
            return minelement;
        }
    };


int main(){
     MinStack* obj = new MinStack();
 obj->push(6);
 obj->push(5);
 obj->push(1);

 int y= obj->getMin();
 obj->pop();
 y= obj->getMin();

 cout<<y<<endl;

}
 
 
