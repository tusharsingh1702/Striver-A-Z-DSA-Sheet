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

//Largest Divisible Subset
// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n=nums.size();
//          if(n==1){
//             return {nums[0]};
//         }
//         sort(nums.begin(),nums.end());
//         vector<int>dp(n,1),hash(n);
//         int maxi=1,maxIndex=-1;
//         for(int i=0;i<n;i++){
//             hash[i]=i;
//             for(int prev=0;prev<i;prev++){
//                  if(nums[i]%nums[prev]==0){
//                       if(1+dp[prev]>dp[i]){
//                         dp[i]=dp[prev]+1;
//                         hash[i]=prev;
//                         if(dp[i]>maxi){
//                             maxi=dp[i];
//                             maxIndex=i;
//                         }
//                       }
//                  }
//             }
//         }
//         vector<int>ans;
//         if(maxIndex==-1){
//             return {nums[0]};
//         }
//         int index=maxIndex;
//         while(hash[index]!=index){
//             ans.push_back(nums[index]);
//             index=hash[index];
//         }
//         ans.push_back(nums[index]);
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };

//Longest string chain
// class Solution {
// public:
//     bool compare(string&word1,string&word2){
//         if(word2.size()+1!=word1.size()){
//             return false;
//         }
//         int n=word1.size(),m=word2.size(),first=0,second=0;
//         while(first<n){
//             if(second<m && word1[first]==word2[second]){
//                 first++;
//                 second++;
//             }
//             else{
//                 first++;
//             }
//         }
//         if(first==n && second==m){
//             return true;
//         }
//         return false;
//     }
//     bool static comp(string&word1,string&word2){
//         return word1.size()<word2.size();
//     }
//     int longestStrChain(vector<string>& words) {
//         int n=words.size();
//         if(n==1){
//             return 1;
//         }
//         int maxi=1;
//         sort(words.begin(),words.end(),comp);
//         vector<int>dp(n,1);
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i;prev++){
//                 if(compare(words[i],words[prev])){
//                     if(1+dp[prev]>dp[i]){
//                         dp[i]=dp[prev]+1;
//                         maxi=max(maxi,dp[i]);
//                     }
//                 }
//             }
//         }
//         return maxi;
//     }
// };

//Number of longest increasing subsequence
// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,1),count(n,1);
//         //count stores the count of longest increasing subsequence ending at an index i.
//         int maxi=1;
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i;prev++){
//                 if(nums[i]>nums[prev]){
//                     if(dp[prev]+1>dp[i]){
//                         dp[i]=dp[prev]+1;
//                         //inherited count
//                         count[i]=count[prev];
//                     }
//                     else if(dp[prev]+1==dp[i]){
//                         //inherited count
//                         count[i]+=count[prev];
//                     }
//                 }
//             }
//             maxi=max(maxi,dp[i]);
//         }
//             int cnt=0;
//             for(int i=0;i<n;i++){
//                 if(dp[i]==maxi){
//                     cnt+=count[i];
//                 }
//             }
//             return cnt;
//     }
// };

//Longest Bitonic Subsequence
// class Solution {
//   public:
//     int LongestBitonicSequence(int n, vector<int> &nums) {
//         vector<int>dp1(n,1),dp2(n,1),bitonic(n,0);
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i;prev++){
//                 if(nums[i]>nums[prev]){
//                      dp1[i]=max(dp1[i],1+dp1[prev]);
//                 }
//             }
//         }
//         for(int i=n-1;i>=0;i--){
//             for(int prev=n-1;prev>i;prev--){
//                 if(nums[i]>nums[prev]){
//                     dp2[i]=max(dp2[i],1+dp2[prev]);
//                 }
//             }
//         }
//         int maxi=0;
//         for(int i=0;i<n;i++){
//            if(dp1[i]==1 || dp2[i]==1){
//                continue;
//            }
//             maxi=max(maxi,dp1[i]+dp2[i]-1);
//         }
//         return maxi;
//     }
// };