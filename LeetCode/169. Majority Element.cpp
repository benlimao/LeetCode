//1
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

//2
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return -1;
		if (n == 1)
			return nums[0];
		int mid = n >> 1;
		int start = 0;
		int end = n - 1;
		int pos = partition(nums, start, end);
		while (pos != mid)
		{
			if (pos > mid)
			{
				end = pos - 1;
				pos = partition(nums, start, end);
			}
			else
			{
				start = pos + 1;
				pos = partition(nums, start, end);
			}
		}
		return nums[mid];
	}

	int partition(vector<int>& nums, int start, int end) {
		//if (start > end)
			//return -1;
		int left = start;
		int right = end;
		int key = nums[start];
		while (left < right)
		{
			while (left < right && nums[right] >= key)
				right--;
			while (left < right && nums[left] <= key)
				left++;
			if (left < right)
				swap(nums[left], nums[right]);
		}
		swap(nums[start], nums[left]);
		return left;
	}
};
