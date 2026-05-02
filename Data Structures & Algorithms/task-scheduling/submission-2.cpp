class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        for(auto x : tasks){

            freq[x]++;
        }

        int maxcount = 0; 
        int count = 0;

        for(auto &p : freq){

            maxcount = max(maxcount, p.second);
        }

        for(auto &p : freq){

            if(maxcount == p.second){

                count++;
            }
        }

        int minFreq = (maxcount - 1) * (n + 1) + count;

        return max((int)tasks.size(), minFreq);

        
    }
};
