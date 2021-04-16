class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[100000];
        int maxindex = 0;
        dp[0] =nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = dp[maxindex] + nums[i];
            if(nums[i] > 0) {
                maxindex = i;
                continue;
            }
            if(i >= k && maxindex == (i-k))  maxindex = getmax(dp, k, i);
        }


        return dp[nums.size()-1];
    }

    int getmax(int* dp, int k, int start){
        int ret = start;
        for(int i = 0; i < k; i++){
            dp[start-i] > dp[ret] ? ret = start-i : ret;
        }
        return ret;
    }
};
