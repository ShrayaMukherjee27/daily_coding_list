class Solution {
public:
vector<int> dp;
    bool helper(vector<int>& nums, int idx){
        if(idx>=nums.size()-1) return true;    //limit exceeded

        if(nums[idx]>=nums.size()-1-idx) {   //{2,0,0} -> at idx=0 , 2>=3-1-0 true
            return dp[idx] = 1;
        }
        
        if(dp[idx]!= -1) return dp[idx];

        for(int j = 1; j<=nums[idx]; j++){
            if(helper(nums,idx+j) == true){
                return dp[idx] = 1;
            }
        }
        
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        dp.resize(n,-1);

        return helper(nums,0);
    }
};
