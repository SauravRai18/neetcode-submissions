class Solution {
public:

    int solve(vector<int>& nums, int i, int sum, int target, int n,  vector<unordered_map<int,int>>& dp){

        if(i == n){

            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[i].find(sum) != dp[i].end()){

            return dp[i][sum];
        }

        int plus = solve(nums, i + 1, sum + nums[i], target, n, dp);

        int minus = solve(nums, i + 1, sum - nums[i], target, n, dp);

        return dp[i][sum] = plus + minus;


    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<unordered_map<int,int>> dp(n);

        return solve(nums, 0,0,target, n, dp);
        
    }
};
