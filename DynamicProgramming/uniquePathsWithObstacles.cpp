class Solution {
public:
int m,n;
vector<vector<int>> dp;
    int f(int i, int j, vector<vector<int>> obs){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(obs[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = f(i+1,j,obs) + f(i,j+1,obs);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        m = obs.size(), n = obs[0].size();
        dp.assign(m,vector<int> (n,-1));
        if(obs[m-1][n-1]==1) return 0;
        return f(0,0,obs);
    }
};
