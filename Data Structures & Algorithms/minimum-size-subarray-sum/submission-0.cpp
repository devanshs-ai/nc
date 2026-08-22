class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int,int>mpp;
        int left = 0;
        int right = 0;
        int minlen = INT_MAX;
        int sum = 0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>=target){
                sum-=nums[left];
                minlen = min(minlen, right-left+1);
                left++;
            }
            right++;
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
    }
};