#include<bits/stdc++.h>
using namespace std;
class Stack {
      public:
      stack<char> s2;
      stack<char> s1;

      void push(stack<char> &s1, char c){
          s1.push(c);
      }
      void pop(stack<char> &s1, stack<char> &s2){
          s1.pop();
      }
   void unpark(char c){ 
           while(s1.top() != c){
      s2.push(s1.top());
      s1.pop();
  }
  s1.pop();
  while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
  }
  while(!s1.empty()){
      cout<<s1.top()<<" ";
      s1.pop();
  }

    }

    void display(stack<char> &s1){
        while(!s1.empty()){
            cout<<s1.top()<<" ";
            s1.pop();
        }
    }
};

int main(){
   
  
  
    Stack obj;
    obj.push(obj.s1,'a');
    obj.push(obj.s1,'b');
    obj.push(obj.s1,'c');
    obj.push(obj.s1,'d');

    obj.unpark('b');
    obj.unpark('d');
   
    obj.display(obj.s1);

}