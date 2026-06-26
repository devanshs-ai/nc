class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>mpp;
        if(nums.size()==0){
            return 0;
        }
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        auto it = mpp.begin();
        int prev = it->first;
        int maxlen = 1;
        int len = 1;
        mpp.erase(prev);

        for (const auto& pair : mpp) {
            if(pair.first-prev==1){
                len++;
                prev = pair.first;
            }
            else{
                maxlen = max(len, maxlen);
                prev = pair.first;
                len = 1;
            }
        }
        return max(maxlen, len);

    }
};
