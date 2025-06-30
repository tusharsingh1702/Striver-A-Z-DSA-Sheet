//Longest Substring with atmost K distinct characters
// int longestKSubstr(string s, int k)
// {
//     int i = 0;
//     int j = 0;
//     int ans = -1;
//     unordered_map<char, int> mp;
//     while (j < s.size()) {
//         mp[s[j]]++;
//         while (mp.size() > k) {
//             mp[s[i]]--;
//             if (mp[s[i]] == 0)
//                 mp.erase(s[i]);
//             i++;
//         }
//         if (mp.size() == k) {
//             ans = max(ans, j - i + 1);
//         }
//         j++;
//     }
//     return ans;
// }

//Subarray with k different integers
// class Solution {
// public:
//     int getAns(vector<int>&nums,int k){
//         if(k<0){
//             return 0;
//         }
//         int n=nums.size(),l=0,r=0,count=0;
//         unordered_map<int,int>mp;

//         for(;r<n;r++){
//             mp[nums[r]]++;

//             while(mp.size()>k){
//                 mp[nums[l]]--;
//                 if(mp[nums[l]]==0){
//                     mp.erase(nums[l]);
//                 }
//                 l++;
//             }
//             count+=(r-l+1);
//         }

//         return count;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return getAns(nums,k)-getAns(nums,k-1);
//     }
// };

//Minimum Window Substring
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<char,int>mp;
//         int m=t.length(),n=s.length(),len=INT_MAX,startIndex=-1,count=0;
//         for(int i=0;i<m;i++){
//             mp[t[i]]++;
//         }

//         int r=0,l=0;

//         for(;r<n;r++){
//             if(mp[s[r]]>0){
//                 count++;
//             }
//             mp[s[r]]--;
//             while(count==m){
//                 if((r-l+1)<len){
//                     len=(r-l+1);
//                     startIndex=l;
//                 }
//                 mp[s[l]]++;
//                 if(mp[s[l]]>0){
//                     count--;
//                 }
//                 l++;
//             }
//         }
//         return len==INT_MAX?"":s.substr(startIndex,len);
//     }
// };