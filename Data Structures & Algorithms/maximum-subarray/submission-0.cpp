class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int num = nums[0];
        for(int i : nums){
            if(sum<0){
                sum = 0;
            }
            sum+=i;
            num = max(num, sum);
        }
        return num;
    }
};
