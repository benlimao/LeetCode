class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
            return false;
        int col = matrix[0].size();
        if(col == 0)
            return false;
        int a = row - 1;
        int b = 0;
        while(a >= 0 && b < col)
        {
            if(target == matrix[a][b])
                return true;
            else if(target < matrix[a][b])
                a--;
            else
                b++;
        }
        return false;
    }
};
