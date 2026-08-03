class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        unordered_map<char, int>mp;
        for(char ch: s1){
            mp[ch]++;
        }

        int k = s1.size();
        unordered_map<char, int>mpp;
        int left = 0;
        int right = 0;
        while(right<s2.size()){
            mpp[s2[right]]++;
            if(right-left+1>k){
                mpp[s2[left]]--;
                if(mpp[s2[left]]==0){
                    mpp.erase(s2[left]);
                }
                left++;
            }
            if(mpp==mp){
                return true;
            }
            right++;
        }
        return false;

    }
};
