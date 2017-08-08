//1.动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(0 == n)
            return 0;
        if(1 == n)
            return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for(int i = 2; i < n; i++)
            dp[i] = (dp[i - 2] + nums[i]) > dp[i - 1] ? (dp[i - 2] + nums[i]) : dp[i - 1];
        return dp[n - 1];
    }
};

//2.节省空间的方法
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i % 2 == 0)
                a = (a + nums[i]) > b ? (a + nums[i]) : b;
            else
                b = (b + nums[i]) > a ? (b + nums[i]) : a;
        }
        return a > b ? a : b;
    }
};
