class Solution {
public:

    int solve(vector<int>& nums, int i, int sum, int target, int n){

        if(i == n){

            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        int plus = solve(nums, i + 1, sum + nums[i], target, n);

        int minus = solve(nums, i + 1, sum - nums[i], target, n);

        return plus + minus;


    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        return solve(nums, 0,0,target, n);
        
    }
};
