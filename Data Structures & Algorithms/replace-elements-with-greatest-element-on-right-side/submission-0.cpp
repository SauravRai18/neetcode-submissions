class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int n = arr.size();

        int last = -1;

        for(int i = n - 1; i >= 0; i--){

            int curr = arr[i];

            arr[i] = last;

            last = max(last, curr);
        }

        return arr;

        
    }
};