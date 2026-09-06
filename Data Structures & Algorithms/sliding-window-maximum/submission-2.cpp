class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        int right = 0;
        vector<int> ans;

        while (right<nums.size()) {
            pq.push({nums[right], right});

            while ((right - k + 1) > pq.top().second){
                pq.pop();
            }

            if (right>=k-1 && !pq.empty()) {
                ans.push_back(pq.top().first);
            }
            right++;
        }
        return ans;
    }
};
