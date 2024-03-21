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

//Frog Jump DP-3
// #include <bits/stdc++.h> 
//Using Recursion- This approach will produce TLE.
// int getAns(int n,vector<int>&heights){
//     if(n==0){
//     return 0;
// }
// int oneJump=getAns(n-1,heights)+abs(heights[n]-heights[n-1]);
// int twoJump=INT_MAX;
// if(n>1){
//     twoJump=getAns(n-2,heights)+abs(heights[n]-heights[n-2]);
// }
// return min(oneJump,twoJump);
// }
// int frogJump(int n, vector<int> &heights)
// {
// return getAns(n-1,heights);
// }

//Using memoisation
// int getAns(int n,vector<int>&dp,vector<int>&heights){
//     if(n==0){
//         return 0;
//     }
//     if(dp[n]!=-1)return dp[n];
//     int oneJump=getAns(n-1,dp,heights)+abs(heights[n]-heights[n-1]);
//     int twoJump=INT_MAX;
//     if(n>1){
//         twoJump=getAns(n-2,dp,heights)+abs(heights[n]-heights[n-2]);
//     }
//     return dp[n]=min(oneJump,twoJump);
// }
// int frogJump(int n,vector<int>&heights){
//     vector<int>dp(n,-1);
//     return getAns(n-1,dp,heights);
// }

//Using Tabulation- Without space optmisation
// int frogJump(int n,vector<int>&heights){
//     vector<int>dp(n);
//     dp[0]=0;
//     for(int i=1;i<n;i++){
//         int oneJump=dp[i-1]+abs(heights[i]-heights[i-1]);
//         int twoJump=INT_MAX;
//         if(i>1){
//             twoJump=dp[i-2]+abs(heights[i]-heights[i-2]);
//         }
//         dp[i]=min(oneJump,twoJump);
//     }
//     return dp[n-1];
// }

//Using Tabulation-Space optimisation
// int frogJump(int n,vector<int>&heights){
//     int prev2=0,prev=0;
//     for(int i=1;i<n;i++){
//         int oneJump=prev+abs(heights[i]-heights[i-1]);
//         int twoJump=INT_MAX;
//         if(i>1){
//             twoJump=prev2+abs(heights[i]-heights[i-2]);
//         }
//         int curri=min(oneJump,twoJump);
//         prev2=prev;
//         prev=curri;
//     }
//     return prev;
// }

//Frog jump with k distances (DP-4)
//Using Recursion
// int getAns(int n,int k,vector<int>&height){
//     if(n==0){
//        return 0;
//      }
//      int minValue=INT_MAX;
//      for(int i=1;i<=k;i++){
//        int iJump=INT_MAX;
//        if(n>=i){
//         iJump=getAns(n-i,k,height)+abs(height[n]-height[n-i]);
//        }
//        minValue=min(minValue,iJump);
//      }
//      return minValue;
// }
// int minimizeCost(int n, int k, vector<int> &height){
//    return getAns(n-1,k,height);
// }

//Using memoization
// int getAns(int n,int k,vector<int>&height,vector<int>&dp){
//   if(n==0)return 0;
//   if(dp[n]!=-1)return dp[n];
//   int minValue=INT_MAX;
//   for(int i=1;i<=k;i++){
//     int curri=INT_MAX;
//     if(n>=i){
//       curri=getAns(n-i,k,height,dp)+abs(height[n]-height[n-i]);
//     }
//     minValue=min(minValue,curri);
//   }
//   return dp[n]=minValue;
// }
// int minimizeCost(int n,int k,vector<int>&height){
//   vector<int>dp(n,-1);
//   return getAns(n-1,k,height,dp);
// }

//Using tabulation- Without space optimisation
// int minimizeCost(int n,int k,vector<int>&height){
//    vector<int>dp(n,-1);
//    dp[0]=0;
//     for(int i=1;i<n;i++){
//         int minValue=INT_MAX;
//         for(int j=1;j<=k;j++){
//           if(i-j>=0){
//             int curri=dp[i-j]+abs(height[i]-height[i-j]);
//             minValue=min(minValue,curri);
//           }
//         }
//         dp[i]=minValue;
//     }
//     return dp[n-1];
// }
