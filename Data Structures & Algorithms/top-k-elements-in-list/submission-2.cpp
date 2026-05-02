class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for(int i =0; i<nums.size(); i++){

            freq[nums[i]]++;

        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);

        for(auto &it : freq ){

            int value = it.first;
            int count = it.second;

            bucket[count].push_back(value);
        }

        vector<int> ans;

        for(int i = n; i>=0; i--){

            for(auto val : bucket[i]){

                ans.push_back(val);

                if(ans.size() == k){

                    return ans;
                }
            }
        }

        return ans;


        
    }
};
