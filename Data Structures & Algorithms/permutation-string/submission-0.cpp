class Solution {
public:

    bool winFreqsame(int freq1[], int freq2[]){

        for(int i =0; i<26; i++){

            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;

    }
    bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};


        for(int i =0; i<s1.size(); i++){

            freq[s1[i] - 'a']++;

        }

        int winSize = s1.size();


        for(int i =0; i<s2.size(); i++){

            int idx = i;
            int winIdx = 0;
            int winFreq[26] = {0};

            while(winIdx < winSize && idx < s2.size()){
                 winFreq[s2[idx] - 'a']++;
                 winIdx++;
                 idx++;
            }

            if(winFreqsame(freq, winFreq)){
                return true;
            }


        }
        return false;


        
    }
};
