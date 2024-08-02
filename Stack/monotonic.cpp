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

// Trapping rainwater
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0;

//         vector<int> leftMax(n), rightMax(n);
//         leftMax[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//         }

//         rightMax[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             rightMax[i] = max(rightMax[i + 1], height[i]);
//         }

//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             int count = min(leftMax[i], rightMax[i]) - height[i];
//             if (count > 0) {
//                 ans += count;
//             }
//         }
//         return ans;
//     }
// };

//Sum of subarray minimum
// class Solution {
// public:
//     vector<int> getNSE(vector<int>&arr){
//         int n=arr.size();
//         vector<int>ans(n);
//         stack<int>stk;
//         for(int i=n-1;i>=0;i--){
//             while(!stk.empty() && arr[stk.top()]>=arr[i]){
//                 stk.pop();
//             }
//             stk.empty()?ans[i]=n:ans[i]=stk.top();
//             stk.push(i);
//         }
//         return ans;
//     }

//     vector<int> getPSE(vector<int>&arr){
//         int n=arr.size();
//         vector<int>ans(n);
//         stack<int>stk;
//         for(int i=0;i<n;i++){
//             while(!stk.empty() && arr[stk.top()]>arr[i]){
//                 stk.pop();
//             }
//             stk.empty()?ans[i]=-1:ans[i]=stk.top();
//             stk.push(i);
//         }
//         return ans;
//     }

//     int sumSubarrayMins(vector<int>& arr) {
//             vector<int>nextSmallerElement=getNSE(arr);
//             vector<int>prevSmallerElement=getPSE(arr);
//             long long total=0,MOD=1e9+7;
//             int n=arr.size();
//             for(int i=0;i<n;i++){
//                 long long numRight=nextSmallerElement[i]-i;
//                 long long numLeft=i-prevSmallerElement[i];
//                 total=(total+((numRight*numLeft)*arr[i])%MOD)%MOD;
//             }
//             return total;
//     }
// };

//Sum of subarray ranges
// class Solution {
// public:

//     vector<int>getNSE(vector<int>&nums,int n){
//         vector<int>ans(n);
//         stack<int>stk;
//         for(int i=n-1;i>=0;i--){
//             while(!stk.empty() && nums[stk.top()]>=nums[i]){
//                 stk.pop();
//             }
//             stk.empty()?ans[i]=n:ans[i]=stk.top();
//             stk.push(i);
//         }
//         return ans;
//     }
//     vector<int>getPSE(vector<int>&nums,int n){
//         vector<int>ans(n);
//         stack<int>stk;
//         for(int i=0;i<n;i++){
//             while(!stk.empty() && nums[stk.top()]>nums[i]){
//                 stk.pop();
//             }
//             stk.empty()?ans[i]=-1:ans[i]=stk.top();
//             stk.push(i);
//         }
//         return ans;
//     }

//     vector<int>getNGE(vector<int>&nums,int n){
//         vector<int>ans(n);
//         stack<int>stk;
//         for(int i=n-1;i>=0;i--){
//             while(!stk.empty() && nums[stk.top()]<=nums[i]){
//                 stk.pop();
//             }
//             stk.empty()?ans[i]=n:ans[i]=stk.top();
//             stk.push(i);
//         }
//         return ans;
//     }

//     vector<int>getPGE(vector<int>&nums,int n){
//         vector<int>ans(n);
//         stack<int>stk;
//         for(int i=0;i<n;i++){
//             while(!stk.empty() && nums[stk.top()]<nums[i]){
//                 stk.pop();
//             }
//             stk.empty()?ans[i]=-1:ans[i]=stk.top();
//             stk.push(i);
//         }
//         return ans;
//     }

//     long long subArrayRanges(vector<int>& nums) {
//             int n=nums.size();
//             vector<int>nse=getNSE(nums,n);
//             vector<int>pse=getPSE(nums,n);
//             vector<int>nge=getNGE(nums,n);
//             vector<int>pge=getPGE(nums,n);

//             long long total=0;

//             for(int i=0;i<n;i++){
//                 long long numRight=nse[i]-i;
//                 long long numLeft=i-pse[i];

//                 long long nRight=nge[i]-i;
//                 long long nLeft=i-pge[i];

//                 total+=(nRight*nLeft*nums[i]-numRight*numLeft*nums[i]);

//             }
//             return total;
//     }
// };

//Asteroid Collision
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int>ans;
//         stack<int>stk;
//         int n=asteroids.size();
//         for(int i=0;i<n;i++){

//             if(asteroids[i]>0){
//                 stk.push(asteroids[i]);
//             }

//             else{
//                 while(!stk.empty() && stk.top()>0 && stk.top()<abs(asteroids[i])){
//                     stk.pop();
//                 }
//                 if(stk.empty() || stk.top()<0){
//                     stk.push(asteroids[i]);
//                 }
//                 else if(stk.top()==abs(asteroids[i])){
//                     stk.pop();
//                 }
            
//             }
//         }
//         while(!stk.empty()){
//             ans.push_back(stk.top());
//             stk.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };

//Remove K digits
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         int n=num.length();
//         if(k>=n){
//             return "0";
//         }
//         stack<char>stk;
//         for(int i=0;i<n;i++){
//             int digit=num[i]-'0';
//             if(stk.empty() || digit>=stk.top()-'0'){
//                 // cout<<"pushing "<<num[i]<<endl;
//                 stk.push(num[i]);
//             }
//             else{
//                 while(k>0 && !stk.empty() && stk.top()-'0'>digit){
//                     // cout<<"popping "<<stk.top()<<endl;
//                     stk.pop();
//                     k--;
//                 }
//                 stk.push(num[i]);
//             }
//         }
//         string ans="";
//         while(!stk.empty()){
//             ans+=stk.top();
//             stk.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         // cout<<ans<<endl;
//         int i=ans.length()-1;
//         while(k!=0){
//             ans.pop_back();
//             i--;
//             k--;
//         }
//         i=ans.length()-1;
//         while(ans[0]=='0'){
//             ans.erase(ans.begin());
//         }
//         if(ans.empty()){
//             return "0";
//         }
//         return ans;
//     }
// };

//Largest area in a histogram
// class Solution {
// public:
// void getNSE(vector<int>&heights,vector<int>&nse,int n){
//             stack<int>stk;
//             int i=n-1;
//             while(i>=0){
//                 while(!stk.empty() && heights[stk.top()]>=heights[i]){
//                     stk.pop();
//                 }
//                 if(stk.empty()){
//                     nse[i]=n;
//                 }
//                 else{
//                     nse[i]=stk.top();
//                 }
//                 stk.push(i);
//                 i--;
//             }
//     }

//     void getPSE(vector<int>&heights,vector<int>&pse,int n){
//             stack<int>stk;
//             int i=0;
//             while(i<n){
//                 while(!stk.empty() && heights[stk.top()]>=heights[i]){
//                     stk.pop();
//                 }
//                 if(stk.empty()){
//                     pse[i]=-1;
//                 }
//                 else{
//                     pse[i]=stk.top();
//                 }
//                 stk.push(i);
//                 i++;
//             }
//     }

//     int largestRectangleArea(vector<int>& heights) {
//         //Calculate next smaller element and previous smaller element
//         int n=heights.size();
//         vector<int>nse(n),pse(n);
//         getNSE(heights,nse,n);
//         getPSE(heights,pse,n);

//         int maxArea=0;
//         for(int i=0;i<n;i++){
//             maxArea=max(maxArea,heights[i]*(nse[i]-pse[i]-1));
//         }
//         return maxArea;
//     }
// };

//Maximal Rectangles
// class Solution {
// public:
//     vector<int> getNSE(vector<int> height, int n) {
//         stack<int> stk;
//         vector<int> ans(n);
//         for (int i = n - 1; i >= 0; i--) {
//             while (!stk.empty() && height[stk.top()] >= height[i]) {
//                 stk.pop();
//             }
//             if (stk.empty()) {
//                 ans[i] = n;
//             } else {
//                 ans[i] = stk.top();
//             }
//             stk.push(i);
//         }
//         return ans;
//     }

//     vector<int> getPSE(vector<int> height, int n) {
//         stack<int> stk;
//         vector<int> ans(n);
//         for (int i = 0; i < n; i++) {
//             while (!stk.empty() && height[stk.top()] >= height[i]) {
//                 stk.pop();
//             }
//             if (stk.empty()) {
//                 ans[i] = -1;
//             } else {
//                 ans[i] = stk.top();
//             }
//             stk.push(i);
//         }
//         return ans;
//     }

//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty()) return 0;
//         int n = matrix.size(), m = matrix[0].size();
//         vector<int> height(m, 0);
//         int maxArea = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
//             }

//             vector<int> nse = getNSE(height, m);
//             vector<int> pse = getPSE(height, m);

//             for (int j = 0; j < m; j++) {
//                 int width = nse[j] - pse[j] - 1;
//                 maxArea = max(maxArea, height[j] * width);
//             }
//         }
//         return maxArea;
//     }
// };
