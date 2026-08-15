class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), 0);
        if(nums.size()==1){ 
            return nums[0]; 
        }
        if(nums.size() == 2){ 
            return max(nums[0], nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int i = 2; i < nums.size()-1; i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }

        vector<int>dp2(nums.size(), 0);
        dp2[1] = nums[1];
        dp2[2] = max(nums[2], nums[1]);

        for(int i = 3; i < nums.size(); i++){
            dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
        }

        int maximum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maximum = max(maximum, max(dp[i], dp2[i]));
        }

        return maximum;

    }
};
