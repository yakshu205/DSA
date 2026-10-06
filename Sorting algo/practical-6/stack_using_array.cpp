#include<iostream>
#include<vector>
using namespace std;
class Stack{
  public:
    vector<int> arr;
    void push(int val){
        arr.push_back(val);
    }
    void pop(){
        if(arr.empty()){
            cout<<"Stack Is Empty"<<endl;
            return;
        }
        arr.pop_back();
    }
    int top(){
        if(arr.empty()){
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return arr.back();
    }
    void print(){
        if(arr.empty()){
            cout<<"Stack Is Empty"<<endl;
            return;
        }
        for(int i=arr.size()-1;i>=0;i--){
            cout<<arr[i]<<" ";
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