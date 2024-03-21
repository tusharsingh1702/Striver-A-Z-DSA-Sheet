//Climbing Stairs
//Recursive Solution that gives TLE
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=1){
//             return 1;
//         }
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };

//Memoization solution O(n) space.
//  class Solution{
//     public:
//     int getAns(int n,vector<int>&dp){
//         if(n<=1){
//             return 1;
//         }
//         if(dp[n]!=-1)return dp[n];
//         return dp[n]=getAns(n-1,dp)+getAns(n-2,dp);
//     }
//     int climbStairs(int n){
//         vector<int>dp(n+1,-1);
//         return getAns(n,dp);
//     }
//  };

//Tabulation without space optimisation.
// class Solution{
//     public:
//     int climbStairs(int n){
//         vector<int>dp(n+1);
//         dp[0]=1;dp[1]=1;
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
// };

//Tabulation with space optimisation.
// class Solution{
//     public:
//     int climbStairs(int n){
//     int prev2=1,prev=1;
//     for(int i=2;i<=n;i++){
//         int curri=prev+prev2;
//         prev2=prev;
//         prev=curri;
//     }
//     return prev;
//     }
// };