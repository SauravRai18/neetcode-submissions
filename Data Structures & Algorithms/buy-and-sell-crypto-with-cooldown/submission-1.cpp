class Solution {
public:

    int solve(int i, int canBuy, int n, vector<int>& prices){

        if(i >= n) return 0;

        int profit = 0;

        if(canBuy){

            int buy = solve(i + 1, false, n, prices) - prices[i];

            int not_buy = solve(i + 1, true, n, prices);

            profit = max( buy, not_buy);
        }
        else{

            int sell = prices[i] + solve(i + 2, true, n, prices);

            int not_sell = solve(i + 1, false, n, prices);

            profit = max( sell, not_sell);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        return solve(0, true, n, prices);
        
    }
};
