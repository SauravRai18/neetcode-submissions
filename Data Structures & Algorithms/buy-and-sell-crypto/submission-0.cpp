class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int maxProfit = 0;

        int bestBuy = prices[0];

        for(int i = 1; i < n; i++){

            bestBuy = min(bestBuy, prices[i]);

            maxProfit = max(maxProfit, prices[i] - bestBuy);

        }

        return maxProfit;
        
    }
};
