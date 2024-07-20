// Next greater element
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        unordered_map<int,int>map;
//        stack<int>stk;
//        int i=nums2.size()-1;
//         while(i>=0){
//             while(!stk.empty() && stk.top()<=nums2[i]){
//                 stk.pop();
//             }
//             if(stk.empty()){
//                 map[nums2[i]]=-1;
//             }
//             else{
//                 map[nums2[i]]=stk.top();
//             }
//             stk.push(nums2[i]);
//             i--;
//         }

//         vector<int>ans;
//         for(int&num:nums1){
//             ans.push_back(map[num]);
//         }
//         return ans;
//     }
// };

//Next greater element 2
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         stack<int>stk;
//         int n=nums.size(),i=n*2-1;
//         vector<int>ans(n);
//         while(i>=0){
//             while(!stk.empty() && stk.top()<=nums[i%n]){
//                 stk.pop();
//             }
//             if(i<n){
//                 if(stk.empty()){
//                     ans[i]=-1;
//                 }
//                 else{
//                     ans[i]=stk.top();
//                 }
//             }
//             stk.push(nums[i%n]);
//             i--;
//         }
//         return ans;
//     }
// };

//Next smaller element
// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         vector<int>ans(prices.size());
//         int i=prices.size()-1;
//         stack<int>stk;
//         while(i>=0){
//             while(!stk.empty() && stk.top()>prices[i]){
//                 stk.pop();
//             }
//             if(stk.empty()){
//                 ans[i]=prices[i];
//             }
//             else{
//                 ans[i]=prices[i]-stk.top();
//             }
//             stk.push(prices[i]);
//             i--;
//         }
//         return ans;
//     }
// };

//Number of NGE's to the right
// class Solution{
// public:
//     vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
//         vector<int>ans;
//         for(int&index:indices){
//              int count=0;
//              for(int i=index+1;i<arr.size();i++){
//                  if(arr[i]>arr[index]){
//                      count++;
//                  }
//              }
//              ans.push_back(count);
//         }
//        return ans;
//     }
// };