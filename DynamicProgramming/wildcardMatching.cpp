#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s==p) return true;
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n]= true;
        for(int i=m; i>=0;i--){
            for(int j =n; j>=0;j--){
                if(p[j]=='*'){
                    dp[i][j] = dp[i][j+1];
                    if(i < m) dp[i][j] = dp[i][j] | dp[i+1][j];
                }
                else if(p[j]=='?'){
                    if(i < m) dp[i][j] = dp[i+1][j+1];
                }
                else if(i < s.size() && s[i] == p[j]) dp[i][j] = dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
