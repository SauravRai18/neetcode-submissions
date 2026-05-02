class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;

        for(auto s : strs){

            string key = s;

            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }


        for(auto x : mp){

            result.push_back(x.second);
        }

        return result;

        
    }
};
