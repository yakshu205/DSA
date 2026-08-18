
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i<n){
         long long int  cor=arr[i]-1;
           if(arr[i]>0 && arr[i]<=n && arr[i]!=arr[cor]){
            int temp=arr[i];
            arr[i]=arr[cor];
            arr[cor]=temp;
            
           }
           else{
            i++;
           }
            
                    
        }
            for(int i=0;i<n;i++){
                     
                     if(arr[i]!=i+1){
                         return i+1;
                     }

           }  

       return n+1;      
    }
};
int main(){
    vector<int>arr;
           
}