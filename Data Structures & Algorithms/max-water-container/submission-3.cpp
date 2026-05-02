class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();


        int maxWater = 0;

        int left = 0;
        int right = n - 1;


        while (left < right){

            int width = right - left;

            int minheight = min(heights[left], heights[right]);

            int currwater = minheight * width;

            maxWater = max(maxWater, currwater);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }

        }

        return maxWater;
        
    }
};
