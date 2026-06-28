class Solution {
public:
    bool dfs(unordered_map<char, int>& visited, unordered_map<char, vector<char>>& adj, char s, string&res){
        visited[s] = 1;
        for(char c: adj[s]){
            if(visited[c]==1){
                return false;
            }
            if(visited[c]==0){
                if(!dfs(visited, adj, c, res)){
                    return false;
                }
            }

        }

        visited[s] = 2;
        res.push_back(s);
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> visited;
        string res;
        for (string word : words) {
            for (char c : word)
                adj[c];
        }
        for(int i = 0; i < words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            
            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2){
                return "";
            }
            int j = 0;
            while(j < word1.size() && j < word2.size()){
                if(word1[j]!=word2[j]){
                    adj[word1[j]].push_back(word2[j]);
                    break;
                }
                j++;
            }
        }
        for (auto &it : adj) {
            if (visited[it.first] == 0) {
                if (!dfs(visited, adj, it.first, res))
                    return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
