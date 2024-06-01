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

