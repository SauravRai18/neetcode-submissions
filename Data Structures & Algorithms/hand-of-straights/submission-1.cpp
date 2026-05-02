class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0){

            return false;
        }

        map<int,int> freq;

        for(auto x : hand){

            freq[x]++;
        }

        while(!freq.empty()){

            int start = freq.begin()->first;

            int count = freq[start];

            for(int i = start; i < start + groupSize; i++){

                if(freq[i] < count){
                    return false;
                }

                freq[i] -= count;

                if(freq[i] == 0){
                    freq.erase(i);
                }
            } 
        }

        return true;



        
    }
};
