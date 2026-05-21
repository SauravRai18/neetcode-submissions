class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();

        /*        for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (nums[i] == nums[j]) {
                            return true;
                        }
                    }
                }

                return false;
            }
            time - n*2
            space - 1

            */

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) != st.end()) {
                return true;
            }

            st.insert(nums[i]);
        }

         return false;
            /* time - n
            space - n  */
        }   
    };