class Solution {
public:


    int solve(vector<int>& nums, int i, int prev, int n,  vector<vector<int>>& dp){

        if(i >= n){
            return 0;
        }

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int take = 0;
        if( prev == -1 || nums[prev] < nums[i]){

            take = 1 + solve(nums,i + 1, i, n, dp);
        }

        int skip = solve(nums, i + 1, prev, n, dp);


        return dp[i][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(nums, 0, -1, n, dp);
        
    }
};
