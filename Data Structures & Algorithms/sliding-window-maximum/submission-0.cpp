class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});

            while(i-k+1>pq.top().second){
                pq.pop();
            }

            if(i>=k-1 && !pq.empty()){
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};
