//dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(pairs.size(), 1);
        int tail = pairs[0][1];
        for(int i = 1; i < dp.size(); i++)
        {
            if(tail < pairs[i][0])
            {
                dp[i] = dp[i-1] + 1;
                tail = pairs[i][1];
            }
            else
                dp[i] = dp[i-1];
        }
        return dp[pairs.size()-1];
    }

private:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
};
