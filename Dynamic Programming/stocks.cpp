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