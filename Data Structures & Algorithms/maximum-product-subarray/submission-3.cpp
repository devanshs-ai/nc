class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int maxnum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            prefix = (prefix==0 ? 1 : prefix) * nums[i];
            suffix = (suffix==0 ? 1 : suffix) * nums[nums.size()- i - 1];
            maxnum = max(maxnum, max(prefix, suffix));
        }

        return maxnum;
    }
};
