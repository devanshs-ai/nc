class Solution {
public:
    bool dfs(vector<int>&nums, int i, int sum){
        if(sum==0){
            return true;
        }
        if(i==nums.size()-1 && sum != 0){
            return false;
        }
        return dfs(nums, i + 1, sum - nums[i]) || dfs(nums, i+1, sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            sum+=i;
        }

        if(sum%2!=0){
            return false;
        }

        int target = sum/2;

        return dfs(nums, 0, target);
    }
};
