#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={4,3,5,4,2,2,3,6,7,6,4};
    unordered_map<int,int>freq;
    for(auto val : arr){
        freq[val]++;
    }
    int maxcount=0;
    int maxnum=0;
    for(const auto&pair :freq){
        if(pair.second>maxcount){
            maxcount=pair.second;
            maxnum=pair.first;
        }

    }
    
    cout<<"maxcount : "<<maxcount<<endl;
    cout<<"maxnum : "<<maxnum<<endl;
}