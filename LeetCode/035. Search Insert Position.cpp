//1.遍历
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= target)
                return i;
        } 
        return n;
    }
};

//2.二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};
