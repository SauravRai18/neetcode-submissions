class Solution {
public:

    bool solve(vector<int>& nums, int i, int target, int n, vector<vector<int>>& dp){

        if(target == 0) return true;

        if(i >= n) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = false;

        if(target >= nums[i]){

            take = solve(nums, i + 1, target - nums[i], n, dp);
        }

        int skip = solve(nums, i + 1, target, n, dp);

        return dp[i][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

      

        int totalSum = 0;
               
        for(int i = 0; i<n; i++){

            totalSum += nums[i];
        }

        if(totalSum % 2 != 0){

            return false;
        }

        int target = totalSum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(nums, 0, target, n, dp);

        
    }
};
