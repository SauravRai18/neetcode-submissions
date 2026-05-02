class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();
        
        
        int maxWater = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = i +1; j<n; j++){

                int h = min(heights[i], heights[j]);

                int w = j - i;

                int area = h * w;

                maxWater = max(maxWater, area);
            }
        }

        return maxWater;



    }
};
