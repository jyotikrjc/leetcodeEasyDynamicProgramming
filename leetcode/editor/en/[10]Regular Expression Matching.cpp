//Given an input string (s) and a pattern (p), implement regular expression matc
//hing with support for '.' and '*'. 
//
// 
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
// 
//
// The matching should cover the entire input string (not partial). 
//
// Note: 
//
// 
// s could be empty and contains only lowercase letters a-z. 
// p could be empty and contains only lowercase letters a-z, and characters like
// . or *. 
// 
//
// Example 1: 
//
// 
//Input:
//s = "aa"
//p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
// 
//
// Example 2: 
//
// 
//Input:
//s = "aa"
//p = "a*"
//Output: true
//Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, 
//by repeating 'a' once, it becomes "aa".
// 
//
// Example 3: 
//
// 
//Input:
//s = "ab"
//p = ".*"
//Output: true
//Explanation: ".*" means "zero or more (*) of any character (.)".
// 
//
// Example 4: 
//
// 
//Input:
//s = "aab"
//p = "c*a*b"
//Output: true
//Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, i
//t matches "aab".
// 
//
// Example 5: 
//
// 
//Input:
//s = "mississippi"
//p = "mis*is*p*."
//Output: false
// 
// Related Topics String Dynamic Programming Backtracking 
// 👍 4578 👎 733


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        bool dp[m+1][n+1];
        for (int i = 0; i <=m ; ++i) {
            for (int j = 0; j <=n; ++j) {
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;
        for (int i = 1; i <=m ; ++i) {
          dp[i][0]=false;
        }
        for (int j = 1; j <=n; ++j) {
            dp[0][j]= j>1 && p[j-1]=='*' && dp[0][j-2];
        }
        for (int i = 1; i <=m; ++i) {
            for (int j = 1; j <=n; ++j) {
            if (p[j-1]!='*')
                dp[i][j]=dp[i-1][j-1] && (p[j-1]==s[i-1] || p[j-1]=='.');
            else
                dp[i][j]=dp[i][j-2] || (s[i-1]==p[j-2] || '.'==p[j-2] ) && dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
