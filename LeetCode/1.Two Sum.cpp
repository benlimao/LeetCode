//1.直接的方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(2 > nums.size())
            return result;
        
        for(int i = 0; i < nums.size() - 1; i++)
            for(int j = i+1; j < nums.size(); j++)
                if(target == nums[i] + nums[j])
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        return result;
    } 
};

//2.哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> result(2, 0);
        for(int i = 0; i < nums.size(); i ++)
        {
            if(hash.find(target - nums[i]) != hash.end())
            {
                result[0] = hash[target - nums[i]];
                result[1] = i;
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};
