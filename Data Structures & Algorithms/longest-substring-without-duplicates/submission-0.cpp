class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        map<int, int> mpp;
        int maxlen = 0;
        
        while(right < s.size()){
            if(mpp.find(s[right])!=mpp.end()){
                left = max(left, mpp[s[right]] + 1);
            }

            mpp[s[right]] = right;

            maxlen = max(maxlen, right - left + 1);

            right++;

        }
        return maxlen;
    }
};
