class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int i =0; 
        int j = 0;

        vector<int> merge;

        while(i < m && j < n){

            if(nums1[i] < nums2[j]){

                merge.push_back(nums1[i]);
                i++;
            }else{

                merge.push_back(nums2[j]);
                j++;
            }

           
        }

        while(i < m){
            merge.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            merge.push_back(nums2[j]);
            j++;
        }

        int total = m + n;

        if(total % 2 != 0){
            return merge[total /2];
        }else{

            return (merge[total/2 - 1] + merge[total/2])/2.0;
        }


        
    }
};
