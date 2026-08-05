class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        priority_queue<pair<int, int>>pq;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto& it: mpp){
            pq.push({it.second, it.first});
        }

        vector<int> res;

        while(!pq.empty() && k>0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};
