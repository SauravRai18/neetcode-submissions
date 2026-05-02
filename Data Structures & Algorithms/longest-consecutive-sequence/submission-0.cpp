class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(auto it : st){

            if(st.find(it - 1) == st.end()){

                int x = it;
                int count = 1;

                while(st.find(x + 1) != st.end()){

                    x++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};
