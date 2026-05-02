class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for(auto x : nums){

            mp[x]++;
        }

        int n = nums.size();

        vector<vector<int>> bucket(n+1);

        for(auto &it : mp){

            int value = it.first;
            int count = it.second;

            bucket[count].push_back(value);
        }


        vector<int> ans;

        for(int i =n; i>=0; i--){

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
