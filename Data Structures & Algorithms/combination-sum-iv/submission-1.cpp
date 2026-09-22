class Solution {
public:
    vector<int>dp;
    int dfs(vector<int>&nums, int target){
        if(target==0){
            return 1;
        }
        
        if(target < 0){
            return 0;
        }

        if(dp[target]!=-1){
            return dp[target];
        }

        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            count += dfs(nums, target-nums[i]);
        }

        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target+1, -1);
        int ans = dfs(nums, target);
        return ans;
    }
};