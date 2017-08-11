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
For example: if player 1 get A, player 2 get B, we can use dp' to store A-B.
if A = dp(i, j), then B = sum(i, j) - dp(i, j)
So dp'(i, j) = dp(i, j) - ( sum(i, j) - dp(i, j) ) = 2*dp(i, j) - sum(i, j), so
2*dp(i, j) = dp'(i, j) + sum(i, j) (this will be used below)
dp'(i, j) = dp(i, j) - ( sum(i, j) - dp(i, j) ) = 2dp(i, j) - sum(i, j)
          = 2 * max( sum(i, j) - dp(i, j-1), sum(i, j) - dp(i+1, j) ) - sum(i, j)
          = max(sum(i, j) - 2*dp(i, j-1), sum(i, j) - 2*dp(i+1, j) )
          = max(sum(i, j) - ( dp'(i, j-1) + sum(i, j-1) ), sum(i, j) - ( dp'(i+1, j) + sum(i+1, j)))
          = max(sum(i, j) - sum(i, j-1) - dp'(i, j-1), sum(i, j) - sum(i+1, j) - dp'(i+1, j))
          = max(nums[j] - dp'(i, j-1), nums[i] - dp'(i+1, j))
Final formula: dp(i, j) = max(nums[j] - dp(i, j-1), nums[i] - dp(i+1, j))
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));   //dp为当子数组[i,j]时，Player1和Player2得到的分数之差
        for(int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for(int i = 1; i < n; i++)
            for(int j = 0; j+i < n; j++)
                dp[j][j+i] = max(nums[j+i] - dp[j][j+i-1],nums[j] - dp[j+1][j+i]);
        return dp[0][n-1] >= 0;     //分数差大于等于0，则Player1胜出
    }
};
