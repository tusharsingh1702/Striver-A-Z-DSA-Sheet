//Subset sum equal to target

//Memoization Approach
// class Solution{   
// public:
// int n;
// vector<vector<int>>dp;
//     bool getAns(vector<int>&arr,int index,int target,vector<vector<int>>&dp){
//         if(target==0){
//             return true;
//         }
//         if(index==0){
//             return arr[0]==target;
//         }
//         if(dp[index][target]!=-1){
//             return dp[index][target];
//         }
//         //not taken
//         bool notTaken=getAns(arr,index-1,target,dp);
//         bool taken=false;
//         if(arr[index]<=target){
//             taken=getAns(arr,index-1,target-arr[index],dp);
//         }
//         return dp[index][target]=notTaken||taken;
//     }
//     bool isSubsetSum(vector<int>arr, int sum){
//         n=arr.size();
//         dp=vector<vector<int>>(n,vector<int>(sum+1,-1));
//         return getAns(arr,n-1,sum,dp);
//     }
// };

//Tabulation Approach
// class Solution{   
// public:
// int n;

//     bool isSubsetSum(vector<int>arr, int sum){
//         n=arr.size();
//         vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
//         for(int i=0;i<n;i++){
//             dp[i][0]=true;
//         }
//         if(arr[0]<=sum){
//             dp[0][arr[0]]=true;
//         }
//         for(int i=1;i<n;i++){
//             for(int target=0;target<=sum;target++){
//                 bool notTaken=dp[i-1][target];
//                 bool taken=false;
//                 if(arr[i]<=target){
//                 taken=dp[i-1][target-arr[i]];
//                 }
//                  dp[i][target]=notTaken||taken;
//             }
//         }
//         return dp[n-1][sum];
//     }
// };

//Space Optimisation
// class Solution{   
// public:
// int n;

//     bool isSubsetSum(vector<int>arr, int sum){
//         n=arr.size();
//         vector<bool>prev(sum+1,false),curr(sum+1,false);
//         prev[0]=true,curr[0]=true;
//         if(arr[0]<=sum){
//             prev[arr[0]]=true;
//         }
//         for(int i=1;i<n;i++){
//             for(int target=0;target<=sum;target++){
//                 bool notTaken=prev[target];
//                 bool taken=false;
//                 if(arr[i]<=target){
//                 taken=prev[target-arr[i]];
//                 }
//                  curr[target]=notTaken||taken;
//             }
//             prev=curr;
//         }
//         return prev[sum];
//     }
// };

//Partition equal subset sum.(Tabulation and space optimisation is similar to previous question.)
// class Solution {
// public:
//     int n;
//     vector<vector<int>>dp;
//     bool getAns(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
//         if(target==0){
//             return false;
//         }
//         if(index==0){
//             return nums[index]==target;
//         }
//         if(dp[index][target]!=-1){
//             return dp[index][target];
//         }
//         bool notTaken=getAns(nums,index-1,target,dp);
//         bool taken=false;
//         if(nums[index]<=target){
//             taken=getAns(nums,index-1,target-nums[index],dp);
//         }
//         return dp[index][target]=notTaken||taken;
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=accumulate(nums.begin(),nums.end(),0);
//         if(sum%2!=0){
//             return false;
//         }
//         sum/=2;
//         n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
//         return getAns(nums,n-1,sum,dp);
//     }
// };

//Count subsets with sum K
//Memoization solution
// class Solution{

// 	public:
// 	const int MOD=1e9+7;
// 	int getAns(int*arr,int index,int target,vector<vector<int>>&dp){
// 	    if(index==0)
//         {
//             if(target==0 && arr[0]==0) return 2;
//             if(arr[0]==target || target==0) return 1;
//             return 0;
//         }

// 	    if(dp[index][target]!=-1){
// 	        return dp[index][target];
// 	    }
// 	    //not Taken
// 	    int notTaken=getAns(arr,index-1,target,dp);
// 	    //taken
// 	    int taken=0;
// 	    if(arr[index]<=target){
// 	        taken=getAns(arr,index-1,target-arr[index],dp);
// 	    }
// 	    return dp[index][target]=(taken+notTaken)%MOD;
// 	}
// 	int perfectSum(int arr[], int n, int sum)
// 	{
// vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
//         return getAns(arr,n-1,sum,dp);
// 	}
	  
// };

//Count subsets with sum K(V. V. Imp. Question)
//Memoization Solution
// class Solution{
//     const int MOD=1e9+7;
//     vector<vector<int>>dp;
// 	public:
// 	int getAns(int*arr,int index,int target){
// 	    if(index==0){
// 	        if(target==0 && arr[index]==0){
// 	            return 2;
// 	        }
// 	       else if(target==0 || arr[index]==target){
// 	            return 1;
// 	        }
// 	        else{
// 	       return 0;
	            
// 	        }
// 	    }
// 	    if(dp[index][target]!=-1){
// 	        return dp[index][target];
// 	    }
// 	    //not Taken
// 	    int notTaken=getAns(arr,index-1,target);
// 	    //taken
// 	    int taken=0;
// 	    if(arr[index]<=target){
// 	    taken=getAns(arr,index-1,target-arr[index]);
// 	    }
// 	    return dp[index][target]= (notTaken+taken)%MOD;
// 	}
// 	int perfectSum(int arr[], int n, int sum)
// 	{
// 	    dp=vector<vector<int>>(n,vector<int>(sum+1,-1));
//         return getAns(arr,n-1,sum);
// 	}	  
// };

//Tabulation Solution
	// int perfectSum(int arr[], int n, int sum)
	// {
	//     dp=vector<vector<int>>(n,vector<int>(sum+1,0));
      //   if(arr[0]==0){
      //       dp[0][0]=2;
      //   }
      //   else{
      //       dp[0][0]=1;
      //   }
      //   if(arr[0]!=0 && arr[0]<=sum){
      //  dp[0][arr[0]]=1;
      //   }
      //   for(int index=1;index<n;index++){
      //       for(int target=0;target<=sum;target++){
	//             //not Taken
	//             int notTaken=dp[index-1][target];
	//             //taken
	//             int taken=0;
	//             if(arr[index]<=target){
	//             taken=dp[index-1][target-arr[index]];
	//             }
	//             dp[index][target]=(taken+notTaken)%MOD;
      //       }
      //   }
      //   return dp[n-1][sum];
	// }

//Space Optimization
// 	int perfectSum(int arr[], int n, int sum)
// 	{
// 	    vector<int>prev(sum+1,0),curr(sum+1,0);
//         if(arr[0]==0){
//             prev[0]=2;
//         }
//         else{
//             prev[0]=1;
//         }
//         if(arr[0]!=0 && arr[0]<=sum){
//        prev[arr[0]]=1;
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=sum;target++){
// 	            //not Taken
// 	            int notTaken=prev[target];
// 	            //taken
// 	            int taken=0;
// 	            if(arr[index]<=target){
// 	            taken=prev[target-arr[index]];
// 	            }
// 	            curr[target]=(taken+notTaken)%MOD;
//             }
//             prev=curr;
//         }
//         return prev[sum];
// 	}	  
// };

//Partitions with given difference
//Memoization Solution
// class Solution {
//   public:
//   const int MOD=1e9+7;
//    vector<vector<int>>dp;
//     int getAns(vector<int>&arr,int index,int target){
//         if(index==0){
//             if(target==0 && arr[0]==0){
//                 return 2;
//             }
//            else if(target==0 || arr[index]==target){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
            
//         }
//         if(dp[index][target]!=-1){
//             return dp[index][target];
//         }
//         //notTaken
//         int notTaken=getAns(arr,index-1,target);
//         int taken=0;
//         if(arr[index]<=target){
//             taken=getAns(arr,index-1,target-arr[index]);
//         }
//         return dp[index][target]=(notTaken+taken)%MOD;
//     }
//     int countPartitions(int n, int d, vector<int>& arr) {
//         int totalSum=accumulate(arr.begin(),arr.end(),0);
//         int reqdSum=totalSum-d;
//         if(reqdSum%2!=0 || reqdSum<0){
//             return 0;
//         }
//         reqdSum/=2;
//         dp=vector<vector<int>>(n,vector<int>(reqdSum+1,-1));
//         return getAns(arr,n-1,reqdSum);
//     }
// };

//Tabulation Solution
//     int countPartitions(int n, int d, vector<int>& arr) {
//         int totalSum=accumulate(arr.begin(),arr.end(),0);
//         int reqdSum=totalSum-d;
//         if(reqdSum%2!=0 || reqdSum<0){
//             return 0;
//         }
//         reqdSum/=2;
//         dp=vector<vector<int>>(n,vector<int>(reqdSum+1,0));
//         if(arr[0]==0){
//             dp[0][0]=2;
//         }
//         else{
//             dp[0][0]=1;
//         }
//         if(arr[0]!=0 && arr[0]<=reqdSum){
//             dp[0][arr[0]]=1;
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=reqdSum;target++){
//                 int notTaken=dp[index-1][target];
//         int taken=0;
//         if(arr[index]<=target){
//             taken=dp[index-1][target-arr[index]];
//         }
//         dp[index][target]=(notTaken+taken)%MOD;
//             }
//         }
//         return dp[n-1][reqdSum];
//     }
// };

//Space Optimization
//     int countPartitions(int n, int d, vector<int>& arr) {
//         int totalSum=accumulate(arr.begin(),arr.end(),0);
//         int reqdSum=totalSum-d;
//         if(reqdSum%2!=0 || reqdSum<0){
//             return 0;
//         }
//         reqdSum/=2;
//         vector<int>prev(reqdSum+1,0),curr(reqdSum+1,0);
//         if(arr[0]==0){
//             prev[0]=2;
//         }
//         else{
//             prev[0]=1;
//         }
//         if(arr[0]!=0 && arr[0]<=reqdSum){
//             prev[arr[0]]=1;
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=reqdSum;target++){
//                 int notTaken=prev[target];
//         int taken=0;
//         if(arr[index]<=target){
//             taken=prev[target-arr[index]];
//         }
//             curr[target]=(notTaken+taken)%MOD;
//             }
//             prev=curr;
//         }
//         return prev[reqdSum];
//     }
// };

//Coin Change
//Memoization Solution
// class Solution {
// public:
// vector<vector<int>>dp;
//     int getAns(vector<int>&coins,int index,int target){
//         if(target==0){
//             return 0;
//         }
//         if(index<0){
//             return 1e8;
//         }
//         if(dp[index][target]!=-1)return dp[index][target];
//         //notTaken
//         int notTaken=getAns(coins,index-1,target);
//         int taken=INT_MAX;
//         if(coins[index]<=target){
//             taken=1+getAns(coins,index,target-coins[index]);
//         }
//         return dp[index][target]=min(notTaken,taken);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         dp=vector<vector<int>>(n,vector<int>(amount+1,-1));
//         int ans=getAns(coins,coins.size()-1,amount);
//         if(ans==1e8){
//             return -1;
//         }
//         return ans;
//     }
// };

//Tabulation Solution
//  int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         dp=vector<vector<int>>(n,vector<int>(amount+1,1e8));
//         for(int i=0;i<n;i++){
//             dp[i][0]=0;
//         }
//         for(int i=1;i<=amount;i++){
//           if (i % coins[0] == 0) {
//             dp[0][i] = i / coins[0];
//         }
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=amount;target++){
//                 int notTaken=dp[index-1][target];
//         int taken=1e8;;
//         if(coins[index]<=target){
//             taken=1+dp[index][target-coins[index]];
//         }
//              dp[index][target]=min(notTaken,taken);
//             }
//         }
//         int ans=dp[n-1][amount];
//         if(ans==1e8){
//             return -1;
//         }
//         return ans;
//     }

//Space Optimisation
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
// vector<int>prev(amount+1,1e8),curr(amount+1,1e8);
//         prev[0]=0;
//         for(int i=1;i<=amount;i++){
//           if (i % coins[0] == 0) {
//             prev[i] = i / coins[0];
//         }
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=amount;target++){
//                 int notTaken=prev[target];
//         int taken=1e8;;
//         if(coins[index]<=target){
//             taken=1+curr[target-coins[index]];
//         }
//              curr[target]=min(notTaken,taken);
//             }
//             prev=curr;
//         }
//         int ans=prev[amount];
//         if(ans==1e8){
//             return -1;
//         }
//         return ans;
//     }

//Coin Change 2
//Memoization Solution
// class Solution {
// public:
//     vector<vector<int>>dp;
//     int getAns(vector<int>&coins,int index,int target){
//         if(target==0){
//             return 1;
//         }
//         if(index<0){
//             return 0;
//         }
//         if(dp[index][target]!=-1){
//             return dp[index][target];
//         }
//         //not Taken
//         int notTaken=getAns(coins,index-1,target);
//         int taken=0;
//         if(coins[index]<=target){
//             taken=getAns(coins,index,target-coins[index]);
//         }
//         return dp[index][target]=notTaken+taken;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         dp=vector<vector<int>>(n,vector<int>(amount+1,-1));
//         return getAns(coins,n-1,amount);
//     }
// };

//Tabulation Solution
// int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         dp=vector<vector<int>>(n,vector<int>(amount+1,0));
//         for(int i=0;i<n;i++){
//             dp[i][0]=1;
//         }
//         for(int i=1;i<=amount;i++){
//             if(i%coins[0]==0){
//                 dp[0][i]=1;
//             }
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=amount;target++){
//         //not Taken
//         int notTaken=dp[index-1][target];
//         int taken=0;
//         if(coins[index]<=target){
//             taken=dp[index][target-coins[index]];
//         }
//             dp[index][target]=notTaken+taken;
//             }
//         }
// return dp[n-1][amount];
//     }

//Space Optimisation Solution
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<int>prev(amount+1,0),curr(amount+1,0);
//      prev[0]=1;
//         for(int i=1;i<=amount;i++){
//             if(i%coins[0]==0){
//                 prev[i]=1;
//             }
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=amount;target++){
//         //not Taken
//         int notTaken=prev[target];
//         int taken=0;
//         if(coins[index]<=target){
//             taken=curr[target-coins[index]];
//         }
//             curr[target]=notTaken+taken;
//             }
//             prev=curr;
//         }
// return prev[amount];
//     }

//0/1 KnapSack Problem
//Memoization Solution
// class Solution
// {
//     public:
//     vector<vector<int>>dp;
//     int getAns(int*wt,int*val,int W,int index){
//         if(index==0){
//             if(wt[0]<=W){
//                 return val[0];
//             }
//             return 0;
//         }
//         if(dp[index][W]!=-1){
//             return dp[index][W];
//         }
//         int notTake=getAns(wt,val,W,index-1);
//         int take=INT_MIN;
//         if(wt[index]<=W){
//             take=val[index]+getAns(wt,val,W-wt[index],index-1);
//         }
//         return dp[index][W]=max(notTake,take);
//     }
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//         dp=vector<vector<int>>(n,vector<int>(W+1,-1));
//        return getAns(wt,val,W,n-1);
//     }
// };

//Tabulation Solution;
// int knapSack(int W, int wt[], int val[], int n) 
//     { 
//         dp=vector<vector<int>>(n,vector<int>(W+1,0));
//         for(int i=wt[0];i<=W;i++){
//             dp[0][i]=val[0];
//         }
//         for(int index=1;index<n;index++){
//             for(int weight=0;weight<=W;weight++){
//                 int notTake=dp[index-1][weight];
//                 int take=INT_MIN;
//                 if(wt[index]<=weight){
//                 take=val[index]+dp[index-1][weight-wt[index]];
//                 }
//             dp[index][weight]=max(notTake,take);
//             }
//         }
//        return dp[n-1][W];
//     }

//Unbounded Knapsack
//Memoization Solution
// class Solution{
// public:
//     vector<vector<int>>dp;
//     int getAns(int*val,int*wt,int index,int W){
//         if(index==0){
//             int n=W/wt[0];
//             return val[0]*n;
//         }
//         if(dp[index][W]!=-1){
//             return dp[index][W];
//         }
//         //not taken
//         int notTaken=getAns(val,wt,index-1,W);
//         int taken=INT_MIN;
//         if(wt[index]<=W){
//             taken=val[index]+getAns(val,wt,index,W-wt[index]);
//         }
//         return dp[index][W]=max(notTaken,taken);
//     }
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         dp=vector<vector<int>>(N,vector<int>(W+1,-1));
//         return getAns(val,wt,N-1,W);
//     }
// };

//Tabulation Solution
// int knapSack(int N, int W, int val[], int wt[])
//     {
//         dp=vector<vector<int>>(N,vector<int>(W+1,0));
//         for(int i=wt[0];i<=W;i++){
//             int n=i/wt[0];
//             dp[0][i]=n*val[0];
//         }
//         for(int index=1;index<N;index++){
//             for(int weight=0;weight<=W;weight++){
//                 int notTaken=dp[index-1][weight];
//                 int taken=INT_MIN;
//                 if(wt[index]<=weight){
//                 taken=val[index]+dp[index][weight-wt[index]];
//                 }
//             dp[index][weight]=max(notTaken,taken);
//             }
//         }
//         return dp[N-1][W];
//     }

//Space Optimisation
// int knapSack(int N, int W, int val[], int wt[])
//     {
//         curr=vector<int>(W+1,0);
//         prev=vector<int>(W+1,0);
//         for(int i=wt[0];i<=W;i++){
//             int n=i/wt[0];
//             prev[i]=n*val[0];
//         }
//         for(int index=1;index<N;index++){
//             for(int weight=0;weight<=W;weight++){
//                 int notTaken=prev[weight];
//                 int taken=INT_MIN;
//                 if(wt[index]<=weight){
//                 taken=val[index]+curr[weight-wt[index]];
//                 }
//             curr[weight]=max(notTaken,taken);
//             }
//             prev=curr;
//         }
//         return prev[W];
//     }

//Target Sum(Tabulation Solution)
// class Solution {
// public:
// vector<vector<int>>dp;
//  int countPartitions(int n, int d, vector<int>& arr) {
//         long long totalSum=accumulate(arr.begin(),arr.end(),0);
//         int reqdSum=totalSum-d;
//         if(reqdSum<0 || reqdSum%2!=0){
//             return 0;
//         }
//         reqdSum/=2;
//         dp=vector<vector<int>>(n,vector<int>(reqdSum+1,0));
//         for(int i=0;i<n;i++){
//             dp[i][0]=1;
//         }
//         if(arr[0]==0){
//             dp[0][0]=2;
//         }
//         if(arr[0]<=reqdSum && arr[0]!=0){
//             dp[0][arr[0]]=1;
//         }
//         for(int index=1;index<n;index++){
//             for(int target=0;target<=reqdSum;target++){
//                 int notTake=dp[index-1][target];
//                 int take=0;
//                 if(arr[index]<=target){
//                 take=dp[index-1][target-arr[index]];
//                 }
//                 dp[index][target]=(notTake+take);
//             }
//         }
        
//         return dp[n-1][reqdSum];
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         //S1-S2=target //S1+S2=totalSum
//         // S2=totalSum-target/2
//        return countPartitions(nums.size(),target,nums);

//     }
// };

//Shortest common supersequence
// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         int n1=str1.length(),n2=str2.length();
//         vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
//         string str="";
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                 if(str1[i-1]==str2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         int i=n1,j=n2;
//         while(i>0 && j>0){
//             if(str1[i-1]==str2[j-1]){
//                 str.push_back(str1[i-1]);
//                 i--;
//                 j--;
//             }
//             else{
//                 if(dp[i-1][j]>dp[i][j-1]){
//                    str.push_back(str1[i-1]);
//                    i--;
//                 }
//                 else{
//                    str.push_back(str2[j-1]);
//                    j--;
//                 }
//             }
//         }

//             while(j>0){
//                 str.push_back(str2[j-1]);
//                 j--;
//             }


//             while(i>0){
//                 str.push_back(str1[i-1]);
//                 i--;
//             }

//         reverse(str.begin(),str.end());
//         return str;

//     }
// };

//Distinct Subsequences
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n1=s.length(),n2=t.length();
//         vector<double>prev(n2+1,0),curr(n2+1,0);
//         prev[0]=curr[0]=1;
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                  if(s[i-1]==t[j-1]){
//                 curr[j]=prev[j-1]+prev[j];
//                 }
//         else{
//             curr[j]=prev[j];
//         }
//             }
//             prev=curr;
//         }
//         return (int)prev[n2];
//     }
// };

//Edit Distance
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n1=word1.length(),n2=word2.length();
//         vector<int>prev(n2+1,0),curr(n2+1,0);
//         for(int i=0;i<=n2;i++){
//             prev[i]=i;
//         }
//         for(int i=1;i<=n1;i++){
//             //This line is very very important.
//             curr[0]=i;
//             for(int j=1;j<=n2;j++){
//                  if(word1[i-1]==word2[j-1]){
//                     curr[j]=0+prev[j-1];
//                 }
//                 else{
//                     //insert
//                     int insert=curr[j-1];
//                     //delete
//                     int del=prev[j];
//                     //replace
//                     int rep=prev[j-1];
//                     curr[j]=1+min(insert,min(del,rep));
//                 }
//             }
//             prev=curr;
//         }
//         return prev[n2];
//     }
// };

//Wild Card Matching
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int n1=s.length(),n2=p.length();
//         vector<bool>prev(n2+1,false),curr(n2+1,false);
//         prev[0]=true;
//         for(int i=1;i<=n2;i++){
//             bool flag=true;
//             for(int j=1;j<=i;j++){
//                 if(p[j-1]!='*'){
//                     flag=false;
//                     break;
//                 }
//             }
//             prev[i]=flag;
//         }
//         for(int i=1;i<=n1;i++){
//             curr[0]=false;
//             for(int j=1;j<=n2;j++){
//                     if(s[i-1]==p[j-1] || p[j-1]=='?'){
//                         curr[j]=prev[j-1];
//                     }
//                     else if(p[j-1]=='*'){
//                      curr[j]=prev[j] || curr[j-1];
//                     }
//                     else{
//                     curr[j]=false;
//                     }
//             }
//             prev=curr;
//         }
//         return prev[n2];
//     }
// };


