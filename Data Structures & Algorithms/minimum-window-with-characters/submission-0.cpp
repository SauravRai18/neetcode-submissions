class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for(auto ch : t){

            mp[ch]++;
        }
        
        int minlen = INT_MAX;

        int n = s.size();

        int left = 0;

        int count = t.size();

        int start = 0;


        for(int right = 0; right < n; right++){

            if(mp[s[right]] > 0){
                count--;
            }

            mp[s[right]]--;

            while(count == 0){

                if((right - left +1 ) < minlen){

                    minlen = right - left + 1;

                    start = left;
                }

                mp[s[left]]++;

                if(mp[s[left]] > 0){
                    count++;
                }

                left++;
               
            }
        
        }

        if(minlen == INT_MAX){

            return "";
        }

        return s.substr(start, minlen);


    }
};
