#include<bits/stdc++.h>
using namespace std;
class DSA{
    public:
        void bruteforce(vector<int>&arr,int n){ //O(nlogn)
            sort(arr.begin(),arr.end());
        }

        void optimized(vector<int>&arr,int n){ //O(n) with 2 passes
            int c0=0,c1=0,c2=0;
            
                 for(int i=0;i<n;i++){
                   (arr[i]==0)?c0++:(arr[i]==1)?c1++:c2++;
                 }

                 int idx=0;
                  for(int i=0;i<c0;i++){
                   arr[idx++]=0;
                 }

                 for(int i=0;i<c1;i++){
                   arr[idx++]=1;
                 }

                 for(int i=0;i<c2;i++){
                   arr[idx++]=2;
                 }
        }

        void optimal(vector<int>&arr,int n){ //O(n) with 1 passes
                 int mid=0,high=n-1,low=0;
                 while(mid<=high){
                    if(arr[mid]==0){
                        swap(arr[low],arr[mid]);
                        low++;
                        mid++;
                    }
                    else if(arr[mid]==1){
                        mid++;
                    }
                    else{
                        swap(arr[high],arr[mid]);
                        high--;
                    }

                 }
        }
        
        void printarray(vector<int>&arr,int n){
            for(int i=0;i<n;i++){
                cout<<arr[i];
            }
            cout<<endl;
        }

};

int main(){
    DSA d;
    vector<int>arr={2,0,2,1,1,0,1,2,0,0};
    int n=10;
    d.bruteforce(arr,n);
    d.printarray(arr,n);

    cout<<"***********************"<<endl;

    d.optimized(arr,n);
    d.printarray(arr,n);

    cout<<"***********************"<<endl;
    d.optimal(arr,n);
    d.printarray(arr,n);

}