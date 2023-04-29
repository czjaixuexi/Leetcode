/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
//dp[i]表示爬到第i阶楼梯共有多少种方法
//dp[i]可以由dp[i-1]爬1步到达，也可以由dp[i-2]爬两步到达
//所以dp[i]=dp[i-1]+dp[i-2]
//初始化： dp[1]=1,dp[0]=1
//优化后的方案：
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        const int len=n;
        int dp[2];
        dp[0]=1,dp[1]=1;
        
        for(int i=2;i<=len;i++){
           int sum=dp[0]+dp[1];
           dp[0]=dp[1];
           dp[1]=sum; 
        
        }
        return dp[1];
    }
};
// @lc code=end

