class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n;
        int len = n;
        for(int i = 0, j = 1; j < n; j++)
        {
            if(nums[i] < nums[j])
                nums[++i] = nums[j];
            else
                len--;
        }
        nums.resize(len);
        return len;
    }
};
