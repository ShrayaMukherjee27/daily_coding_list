class Solution {
public:
    int dp[100005][101][2];

    int func(vector<int>& prices, int i, int k, bool ongoing) {
        if(i == prices.size() || k == 0) return 0;
        if(dp[i][k][ongoing] != -1) return dp[i][k][ongoing];
      
        int ans = func(prices, i + 1, k, ongoing);
        if(ongoing){
            ans = max(ans, prices[i] + func(prices, i + 1, k - 1, false));
        }
        else{
            ans = max(ans, func(prices, i + 1, k, true) - prices[i]);
        }
        return dp[i][k][ongoing] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return func(prices, 0, k, false);
    }
};
