class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int num : nums){
            if(mpp.find(num)!=mpp.end()){
                return num;
            }
            mpp[num]++;
        }
    }
};
