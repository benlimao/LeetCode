class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
            return 0; 
        vector<int> dp(A.size()-2, 0);
        if(A[2] - A[1] == A[1] - A[0])
            dp[0] = 1;
        int res = dp[0];
        for(int i = 1; i < dp.size(); i++)
        {
            if(A[i+2] - A[i+1] == A[i+1] - A[i])
                dp[i] = dp[i-1] + 1;
            res += dp[i];
        }
        return res;
    }
};
