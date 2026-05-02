class Solution {
public:

    bool issame( vector<int>& freq,  vector<int>& freq2){

        for(int i = 0; i<26; i++){

            if(freq[i] != freq2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        vector<int> freq(26, 0);

        for(auto ch : s1){

            freq[ch - 'a']++;
        }

        int winSize = s1.size();

        for(int i = 0; i<s2.size(); i++){

            int winIdx = 0;
            int idx = i;

            vector<int> freq2(26, 0);

            while(winIdx < winSize && idx < s2.size()){

                freq2[s2[idx] - 'a']++;

                winIdx++;
                idx++;
            }

            if(issame(freq, freq2)){
                return true;
            }

        }

        return false;
        
    }
};
