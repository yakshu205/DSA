#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int i , int j,int n,int m, vector<vector<int>>&grid,int maxfish){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
            return 0;
        }
        maxfish=grid[i][j];
        grid[i][j]=0;
         maxfish+=dfs(i-1,j,n,m,grid,maxfish);
        maxfish+=dfs(i,j+1,n,m,grid,maxfish);
         maxfish+=dfs(i+1,j,n,m,grid,maxfish);
         maxfish+=dfs(i,j-1,n,m,grid,maxfish);

         return maxfish;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxfish=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    maxfish=max(maxfish,dfs(i,j,n,m,grid,maxfish));
                }
            }
        }

        return maxfish;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> grid ={
        {0,2,1,0},
       {4,0,0,3},
       {1,0,0,4},
       {0,3,2,0}
    };
    int result = solution.findMaxFish(grid);
    cout << result << endl;
    return 0;
}