class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;

    int helper;
    KthLargest(int k, vector<int>& nums) : helper(k){
        
        for(auto x: nums){

            pq.push(x);

            if(pq.size() > k){
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {

        pq.push(val);

        if(pq.size() > helper){

            pq.pop();
        }

        return pq.top();
        
    }
};
