//Best time to buy and sell stocks
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit=0,mini=prices[0],n=prices.size();
//         for(int i=1;i<n;i++){
//             int cost=prices[i]-mini;
//             profit=max(profit,cost);
//             mini=min(mini,prices[i]);
//         }
//         return profit;
//     }
// };

//Best time to buy and sell stocks 2
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size(),prevNo=0,prevYes=0,currNo,currYes;
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                  if(buy==1){
//                 currYes=max(-prices[index]+prevNo,prevYes);
//                 }
//                 else{
//                 currNo=max(prices[index]+prevYes,prevNo);
//                 }
//             }
//             prevNo=currNo;
//             prevYes=currYes;
//         }
//         return prevYes;
//     }
// };

//Best Time to buy and sell stocks 3
// class Solution {
// public:
// int n;
//     int maxProfit(vector<int>& prices) {
//         n=prices.size();
//         vector<vector<int>>prev(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int trans=1;trans<=2;trans++){
//                     int profit=0;
//                     if(buy){
//             profit= max(-prices[index]+prev[0][trans],prev[1][trans]);
//         }
//         else{
//             profit=max(prices[index]+prev[1][trans-1],prev[0][trans]);
//         }
//     curr[buy][trans]=profit;
//                 }
//                 prev=curr;
//             }
//         }
//         return prev[1][2];
//     }
// };

//Best Time to buy and sell stocks 4
// class Solution {
// public:
//     int n;
//     int maxProfit(int k, vector<int>& prices) {
//         n=prices.size();
//         vector<vector<int>>prev(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int trans=1;trans<=k;trans++){
//                     int profit=0;
//                     if(buy){
//             profit= max(-prices[index]+prev[0][trans],prev[1][trans]);
//         }
//         else{
//             profit=max(prices[index]+prev[1][trans-1],prev[0][trans]);
//         }
//     curr[buy][trans]=profit;
//                 }
//                 prev=curr;
//             }
//         }
//         return prev[1][k];
//     }
// };

//Best Time to buy and sell stock with cooldown period
// class Solution {
// public:
// int n;
//     int maxProfit(vector<int>& prices) {
//         n=prices.size();
//         int prevNo=0,prevYes=0,currNo=0,currYes=0,prev1No=0,prev1Yes=0;
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                 int profit=0;
//         if(buy){
//             profit=max(-prices[index]+prevNo,prevYes);
//             currYes=profit;
//         }
//         else{
//             if(index==n-1){
//             profit=max(prices[index]+prevYes,prevNo);
//             }
//             else{
//             profit=max(prices[index]+prev1Yes,prevNo);
//             }
//             currNo=profit;
//         }
//             }
//             prev1No=prevNo;
//             prev1Yes=prevYes;
//             prevNo=currNo;
//             prevYes=currYes;
//         }
//         return prevYes;
//     }
// };

//Best Time to buy and sell stock with transaction fee
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n=prices.size(),prevNo=0,prevYes=0,currNo,currYes;
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                  if(buy==1){
//                 currYes=max(-prices[index]+prevNo,prevYes);
//                 }
//                 else{
//                 currNo=max(prices[index]-fee+prevYes,prevNo);
//                 }
//             }
//             prevNo=currNo;
//             prevYes=currYes;
//         }
//         return prevYes;
//     }
// };