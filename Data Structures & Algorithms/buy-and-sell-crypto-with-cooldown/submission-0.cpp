class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(3, 0));

        //0 do nothing
        //1 buy
        //2 sell

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for(int i = 0; i < prices.size()-1; i++){
            dp[i+1][0] = max(dp[i][0], dp[i][2]);

            dp[i+1][1] = max(dp[i][1], dp[i][0]-prices[i+1]);

            dp[i+1][2] =  dp[i][1]+prices[i+1];
        }

        return max(dp[prices.size()-1][0], dp[prices.size()-1][2]);
    }
};
