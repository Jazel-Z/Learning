class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, -1);
        return dfs(nums,target,dp);

    }

    int dfs(vector<int>& nums, int target, vector<int>& dp) {
        if(target < 1 ) return 0;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target == nums[i]) ans++;
            else{
                ans += dfs(nums, target-nums[i],dp);
            }
        }
        dp[target] = ans;
        return ans;
    }

};