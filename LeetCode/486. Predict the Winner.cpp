//1.
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        for(int i = 1; i < n; i++)
            sums[i] = nums[i] + sums[i-1];
        for(int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for(int i = 1; i < n; i++)
            for(int j = 0; i+j < n; j++)
                dp[j][i+j] = max(sums[i+j]-sums[j]+nums[j]-dp[j+1][i+j],sums[i+j]-sums[j]+nums[j]-dp[j][i+j-1]);
        return 2*dp[0][n-1]>=sums[n-1];
    }
};


//2.从Discuss得到的思路
/*
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for(int i = 1; i < n; i++)
            for(int j = 0; j+i < n; j++)
                dp[j][j+i] = max(nums[j+i] - dp[j][j+i-1],nums[j] - dp[j+1][j+i]);
        return dp[0][n-1] >= 0;
    }
};
