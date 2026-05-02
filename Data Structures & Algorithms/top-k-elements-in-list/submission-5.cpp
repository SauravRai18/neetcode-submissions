class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int n = nums.size();

        for(auto it : nums){

            mp[it]++;
        }

        

        vector<vector<int>> bucket(n+1);
      
        for(auto &it : mp){

            int val = it.first;

            int freq = it.second;

            bucket[freq].push_back(val);

        }

        vector<int> ans;

        for(int i = n ; i>=0; i--){

            for(auto &it : bucket[i]){

                ans.push_back(it);

                if(ans.size() == k){

                    return ans;
                }
            }
        }
        return ans;
        
    }
};
