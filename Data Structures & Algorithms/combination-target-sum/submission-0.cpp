class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& ans, int i, int target, vector<int>temp){

        if(i == nums.size() || target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
 
         
         helper(nums, ans, i , target - nums[i], temp);
         temp.pop_back();
         helper(nums, ans, i + 1, target, temp);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
         helper(nums, ans, 0, target, temp);

         return ans;
         
    }
};
