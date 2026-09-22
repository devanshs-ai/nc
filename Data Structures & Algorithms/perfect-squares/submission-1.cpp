class Solution {
public:
    vector<int>dp;
    int dfs(int n){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1+dfs(n-i*i));
        }

        return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.assign(n+1, -1);
        int res = dfs(n);
        return res;
    }
};