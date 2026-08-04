class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }

        string res;
        unordered_map<char, int>mp;
        for(char ch:t){
            mp[ch]++;
        }

        unordered_map<char, int>mpp;

        int left = 0;
        int right = 0;

        int required = mp.size();
        int formed = 0;
        int minlen = INT_MAX;

        while(right<s.size()){
            mpp[s[right]]++;

            if(mpp[s[right]]==mp[s[right]]){
                formed++;
            }

            while(formed==required){
                if(minlen>right-left+1){
                    res = s.substr(left, right - left+1);
                    minlen = right-left+1;
                }
                mpp[s[left]]--;
                if(mp.count(s[left]) && mpp[s[left]] < mp[s[left]])
                    formed--;
                
                left++;
            }
            right++;
        }

        return res;
    }
};
