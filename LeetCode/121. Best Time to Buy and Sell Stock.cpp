class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            minPrice = prices[i] < minPrice ? prices[i] : minPrice;
            maxPro = (prices[i] - minPrice) > maxPro ? (prices[i] - minPrice) : maxPro;
        }
        return maxPro;
    }
};
