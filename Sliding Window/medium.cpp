// Longest substring without repeating characters
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.length(),l=0,r=0,ans=0;
//         vector<int>hash(256,-1);
//         while(r<n){
//            if(hash[s[r]]!=-1){
//                 l=max(l,hash[s[r]]+1);
//            }
//            hash[s[r]]=r;
//            ans=max(ans,r-l+1);
//            r++;
//         }
//         return ans;
//     }
// };

//Maximum consequtive 1's
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int tempK=k,n=nums.size(),l=0,r=0,ans=0;

//         for(;r<n;r++){

//             if(nums[r]==0){
//                 tempK--;
//             }

//             if(tempK<0){
//                 if(nums[l]==0){
//                     tempK++;
//                 }
//                 l++;
//             }

//             ans=max(ans,r-l+1);
//         }

//         return ans;
//     }
// };

//Fruits into baskets
// class Solution {
//   public:
//     int totalFruits(vector<int> &arr) {
//         unordered_map<int,int>freq;
//         int n=arr.size(),l=0,r=0,ans=0;
        
//         for(;r<n;r++){
//             freq[arr[r]]++;
            
//             if(freq.size()>2){
//                 if(freq[arr[l]]==1){
//                     freq.erase(arr[l]);
//                 }
//                 else{
//                     freq[arr[l]]--;
//                 }
//                 l++;
//             }
            
//             ans=max(ans,r-l+1);
//         }
        
//         return ans;
//     }
// };

// Longest repeating character replacement
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         vector<int>hash(26,0);
//         int l=0,r=0,maxFreq=0,ans=0,n=s.length();

//         for(;r<n;r++){
//             hash[s[r]-'A']++;
//             maxFreq=max(maxFreq,hash[s[r]-'A']);

//             while(l<n && r-l+1-maxFreq>k){
//                 hash[s[l]-'A']--;
//                 maxFreq=0;
//                 for(int i=0;i<26;i++){
//                     maxFreq=max(maxFreq,hash[i]);
//                 }
//                 l++;
//             }
//             ans=max(ans,r-l+1);
//         }
//         return ans;
//     }
// };

//Binary Subarrays with sum
// class Solution {
// public:
//     int getAns(vector<int>&nums,int goal){
//         if(goal<0){
//             return 0;
//         }
//         int n=nums.size(),l=0,r=0,cnt=0,sum=0;
//         for(;r<n;r++){
//             sum+=nums[r];
//             while(sum>goal){
//                 sum-=nums[l];
//                 l++;
//             }
//             cnt+=(r-l+1);
//         }
//         return cnt;

//     }
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         return getAns(nums,goal)-getAns(nums,goal-1);
//     }
// };

//Count number of nice subarrays
// class Solution {
// public:
//     int getAns(vector<int>&nums,int k){
//         if(k<0){
//             return 0;
//         }
//         int l=0,r=0,n=nums.size(),cnt=0,oddCount=0;
//         for(;r<n;r++){
//             if(nums[r]%2!=0){
//                 oddCount++;
//             }
//             while(oddCount>k){
//                 if(nums[l]%2!=0){
//                     oddCount--;
//                 }
//                 l++;
//             }
//             cnt+=(r-l+1);
//         }
//         return cnt;
//     }
//     int numberOfSubarrays(vector<int>& nums, int k) {
//             return getAns(nums,k)-getAns(nums,k-1);
//     }
// };

//Maximum points you can obtain from cards.
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n=cardPoints.size(),leftSum=0,rightSum=0,ans=0;
//         int j=n-1;
//         for(int i=0;i<k;i++){
//             leftSum+=cardPoints[i];
//         }
//         ans=leftSum;
//         int i=k-1;
//         for(;i>=0;i--){
//             leftSum-=cardPoints[i];
//             rightSum+=cardPoints[j];
//             ans=max(ans,leftSum+rightSum);
//             j--;
//         }

//         return ans;
//     }
// };

