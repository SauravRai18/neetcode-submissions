class Solution {
public:

    int solve(int i, int canBuy, int n, vector<int>& prices, vector<vector<int>>& dp){

        if(i >= n) return 0;

        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy){

            int buy = solve(i + 1, false, n, prices, dp) - prices[i];

            int not_buy = solve(i + 1, true, n, prices, dp);

            return dp[i][canBuy] = max(buy, not_buy);
        }
        else{

            int sell = prices[i] + solve(i + 2, true, n, prices, dp);

            int not_sell = solve(i + 1, false, n, prices, dp);

           return dp[i][canBuy] = max(sell, not_sell);
        }    
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, true, n, prices, dp);
        
    }
};