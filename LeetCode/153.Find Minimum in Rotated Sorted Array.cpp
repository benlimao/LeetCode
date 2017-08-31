class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int left = 0;
        int right = n - 1;
        int mid = left;
        while(nums[left] >= nums[right])
        {
            if(right - left == 1)
            {
                mid = right;
                break;
            }
            mid = (left+right)/2;
            if(nums[left] < nums[mid])
                left = mid;
            if(nums[right] > nums[mid])
                right = mid;
        }
        return nums[mid];
    }
};
