//You are given coins of different denominations and a total amount of money amo
//unt. Write a function to compute the fewest number of coins that you need to mak
//e up that amount. If that amount of money cannot be made up by any combination o
//f the coins, return -1. 
//
// Example 1: 
//
// 
//Input: coins = [1, 2, 5], amount = 11
//Output: 3 
//Explanation: 11 = 5 + 5 + 1 
//
// Example 2: 
//
// 
//Input: coins = [2], amount = 3
//Output: -1
// 
//
// Note: 
//You may assume that you have an infinite number of each kind of coin. 
// Related Topics Dynamic Programming 
// 👍 4683 👎 146


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0]=0;
        for (int i = 1; i <= amount; ++i) {
            dp[i]=amount+1;
            for (auto const& coin:coins) {
            if (coin<=i)
            {
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
            }
        }
        if (dp[amount]<amount+1)
            return dp[amount];
        return -1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
