class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        unordered_map<char, int> mp;

        int maxLen = 0;

        int maxfreq = 0;

        int left = 0;


        for(int right = 0; right<n; right++){

            mp[s[right]]++;

            maxfreq = max(maxfreq, mp[s[right]]);

            while((right - left + 1 ) - maxfreq > k){

                mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
        
    }
};

