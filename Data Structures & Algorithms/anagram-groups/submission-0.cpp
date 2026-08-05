class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>res;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto& it: mp){
            vector<string>group;
            for(string s:it.second){
                group.push_back(s);
            }
            res.push_back(group);
        }

        return res;
    }
};
