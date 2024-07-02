//Length of the longest increasing subsequence
// class Solution {
// public:
//     int n;
//     int lengthOfLIS(vector<int>& nums) {
//         n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int index=n-1;index>=0;index--){
//             for(int prevIndex=index-1;prevIndex>=-1;prevIndex--){
//                 int notTake=dp[index+1][prevIndex+1];
//                 int take=-1e6;
//                 if(prevIndex==-1 || nums[index]>nums[prevIndex]){
//                     take=1+dp[index+1][index+1];
//                 }
//                 dp[index][prevIndex+1]=max(take,notTake);
//             }
//         }
//         return dp[0][0];
//     }
// };

//Print longest increasing subsequence
// class Solution {
//   public:
//     vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
//         if(n==1){
//             return {arr[0]};
//         }
//         vector<int>dp(n,1),hash(n);
//         int maxIndex=-1,maxi=1;
//         for(int i=0;i<n;i++){
//             hash[i]=i;
//             for(int prev=0;prev<i;prev++){
//                 if(arr[prev]<arr[i]){
//                     if(dp[prev]+1>dp[i]){
//                         dp[i]=dp[prev]+1;
//                         if(dp[i]>maxi){
//                             maxi=dp[i];
//                             maxIndex=i;
//                         }
//                         hash[i]=prev;
//                     }
//                 }
//             }
//         }
//             vector<int>ans;
//             int index=maxIndex;
//             while(hash[index]!=index){
//                 ans.push_back(arr[index]);
//                 index=hash[index];
//             }
//             ans.push_back(arr[index]);
//             reverse(ans.begin(),ans.end());
//             return ans;
           
//     }
// };