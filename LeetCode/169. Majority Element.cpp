class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return -1;
        if(n == 1)
            return nums[0];
        int cnt = 1;
        int res = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(cnt == 0)
            {
                res = nums[i];
                cnt = 1;
            }
            else
            {
                if(res == nums[i])
                    cnt++;
                else
                    cnt--;
            }
        }
        return res;
    }
};
