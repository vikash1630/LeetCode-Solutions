class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell;
        int profit = 0;
        for (int i = 1;i<prices.size();i++) {
            sell = prices[i];
            if (buy > sell) {
                buy = prices[i];
            }
            else {  
                profit = max(profit,sell - buy);
            }
        }

        return profit;

    }
};