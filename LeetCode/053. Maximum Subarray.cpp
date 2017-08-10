//dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        int max = dp[0];
        for(int i = 1; i < dp.size(); i++)
        {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            max = dp[i] > max ? dp[i] : max;
        }
        return max;
    }
};
