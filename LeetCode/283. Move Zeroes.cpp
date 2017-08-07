class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(0 != nums[i])
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        for(int j = cnt; j < nums.size(); j++)
            nums[j] = 0;
    }
};
