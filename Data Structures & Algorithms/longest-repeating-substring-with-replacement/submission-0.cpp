class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int freq = 0;
        int maxlen = 0;
        unordered_map<char, int> mpp;

        while(right<s.size()){
            mpp[s[right]]++;
            freq = max(freq, mpp[s[right]]);

            if(right-left+1-freq>k){
                mpp[s[left]]--;
                left++;
            }

            maxlen = max(maxlen, right-left+1);
            right++;
        }
        
        return maxlen;
    }
};
