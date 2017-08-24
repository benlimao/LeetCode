/***************************
0 0 0 
0 0 1
------ n = 1 
0 1 1 
0 1 0 
------ n = 2
1 1 0 
1 1 1 
1 0 1 
1 0 0 
------ n = 3
***************************/
//1.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n > 0)
            grayCode(n, res);
        else
            res.push_back(0);
        return res;
    }
    void grayCode(int n, vector<int>& res) {
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }
        grayCode(n-1, res);
        int size = res.size()-1;
        for (int i = size; i >= 0; i--) {
            int num = res[i] | (1<<(n-1));
            res.push_back(num);
        }
    }
};

//2.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1<<n);
        for (int i=0; i<(1<<n); i++) 
            res[i] = i^(i>>1);
        return res;
    }
};
