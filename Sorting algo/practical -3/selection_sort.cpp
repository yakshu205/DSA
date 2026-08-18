#include<iostream>
#include<algorithm>
using namespace std;
class DSA{
    public:
    void bubblesort(int arr[],int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }


        void selectionsort(int arr[],int n){
            for(int i=0;i<n-1;i++){
                int small_idx=i;
                for(int j=i+1;j<n;j++){
                    if(arr[j]<arr[small_idx]){
                        small_idx=j;
                    }
                }
                swap(arr[i],arr[small_idx]);
            }
        }

        void insertionsort(int arr[],int n){
                 for(int i=1;i<n;i++){
                    int curr=arr[i];
                    int prev=i-1;
                    while(prev>=0 && arr[prev]>curr){
                        arr[prev+1]=arr[prev];
                        prev--;
                    }
                    arr[prev+1]=curr;
                 }
        }

        
        void printarray(int arr[],int n){
            for(int i=0;i<n;i++){
                cout<<arr[i];
            }
            cout<<endl;
        }

};

int main(){
    DSA d;
    int arr[]={4,1,5,2,3};
    int n=5;
    cout<<"Bubble Sort : ";
    d.bubblesort(arr,n);
    d.printarray(arr,n);

    cout<<"\n***********************"<<endl;
    cout<<"Selection Sort : ";
    d.selectionsort(arr,n);
    d.printarray(arr,n);

    cout<<"\n***********************"<<endl;
     cout<<"insertion Sort : "<<endl;
    d.insertionsort(arr,n);
    d.printarray(arr,n);

}