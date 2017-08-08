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
