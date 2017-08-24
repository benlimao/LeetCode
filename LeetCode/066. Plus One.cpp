class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        int n = digits.size()-1;
        while(n != -1)
        {
            if(res[n] != 9)
            {
                res[n]++;
                break;
            }
            else
                res[n--] = 0;
        }
        if(res[0] == 0)
            res.insert(res.begin(), 1);
        return res;
    }
};
