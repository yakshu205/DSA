#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
          int n=s.length();
          string ans;
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string word=" ";
        while(i<n&&s[i]!=' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
         ans+=" "+word;
        }
        return ans.substr(1);
    }
};
int main(){
    Solution s;
 string str=s.reverseWords("the pen");
    cout<<str<<endl;
}