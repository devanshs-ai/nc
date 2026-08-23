class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int>mpp;
        int count = 0;
        mpp[0] = 1;

        for(int num:nums){
            sum+=num;
            int rem = sum-k;
            if(mpp.find(rem)!=mpp.end()){
                count += mpp[rem];
            }
            mpp[sum]++;
        }
        return count;   
    }
};