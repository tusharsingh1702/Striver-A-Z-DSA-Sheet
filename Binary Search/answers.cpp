// Square root of a number in logn
// class Solution{
//   public:
//     long long int floorSqrt(long long int x) 
//     {
//      long long low=1,high=x,ans;
//      while(low<=high){
//          long long mid=low+(high-low)/2;
//          if(mid*mid<=x){
//              ans=mid;
//              low=mid+1;
//          }
//          else{
//              high=mid-1;
//          }
//      }
//      return ans;
//     }
// };

//Nth root of M
// class Solution{
// 	public:
// 	int func(int mid,int n,int m){
// 	    long long ans=1;
// 	    for(long long i=0;i<n;i++){
// 	        ans*=mid;
// 	       if(ans>m){
// 	           return 2;
// 	       }
// 	    }
// 	    if(ans==m){
// 	        return 0;
// 	    }
// 	    return 1;
	   
// 	}
// 	int NthRoot(int n, int m)
// 	{
// 	    long long low=1,high=m,ans=-1;
// 	    while(low<=high){
// 	        long long mid=low+(high-low)/2;
// 	        int val=func(mid,n,m);
// 	        if(val==0){
// 	            ans=mid;
// 	           break;
// 	        }
// 	        else if(val==2){
// 	            high=mid-1;
// 	        }
// 	        else{
// 	            low=mid+1;
// 	        }
// 	    }
// 	    return ans;
// 	}  
// };

//Koko eating bananas
// class Solution {
// public:
//     int findMaxi(vector<int>&piles){
//         int maxi=INT_MIN;
//         for(auto it:piles){
//             maxi=max(maxi,it);
//         }
//         return maxi;
//     }
//     long long getTime(vector<int>&piles,int mid){
//         long long totalTime=0;
//         for(auto it:piles){
//             long long time=ceil((double)it/(double)mid);
//             totalTime+=time;
//         }
//         return totalTime;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxi=findMaxi(piles);
//         int low=1,high=maxi;
//         long long ans=maxi;
//         while(low<=high){
//             long long mid=low+(high-low)/2;
//             long long totalTime=getTime(piles,mid);
//             if(totalTime<=h){
//                 ans=min(ans,mid);
//                 high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return ans;
//     }
// };

//Minimum days to make M bouquets
// class Solution {
// public:
//     pair<int,int>getminmax(vector<int>&bloomDay){
//         int mini=INT_MAX,maxi=INT_MIN;
//         for(auto it:bloomDay){
//             mini=min(mini,it);
//             maxi=max(maxi,it);
//         }
//         return {mini,maxi};
//     }
//     bool possible(vector<int>&bloomDay,int mid,int m,int k){
//         int possibleBs=0,count=0;
//         for(auto it:bloomDay){
//             if(it<=mid){
//                 count++;
//             }
//             else{
//                 possibleBs+=count/k;
//                 count=0;
//             }
//         }
//         possibleBs+=count/k;
//         if(possibleBs>=m){
//             return true;
//         }
//         return false;
//     }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         long long val = m * 1ll * k * 1ll;
//         if(bloomDay.size()<val){
//             return -1;
//         }
//         pair<int,int>p=getminmax(bloomDay);
//         int low=p.first,high=p.second,ans=high;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(possible(bloomDay,mid,m,k)){
//               ans=min(ans,mid);
//               high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return ans;
//     }
// };

//Find the smallest divisor
// class Solution {
// public:
// bool divisionSum(vector<int>&nums,int mid,int threshold){
//     int sum=0;
//     for(auto it:nums){
//         sum+=ceil((double)it/(double)mid);
//     }
//     return sum<=threshold;
// }
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int low=1,high=INT_MIN;
//         for(auto it:nums){
//             high=max(high,it);
//         }
//         int ans=high;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(divisionSum(nums,mid,threshold)){
//                 ans=min(ans,mid);
//                 high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return ans;
//     }
// };

//Capacity to ship packages with D days
// class Solution {
// public:
//     int getDays(vector<int>&weights,int mid,int days){
//         int totalDays=1,sum=0;
//         for(int i=0;i<weights.size();i++){
//             if(sum+weights[i]>mid){
//                 totalDays++;
//                 sum=weights[i];
//             }
//             else{
//                 sum+=weights[i];
//             }
//         }

//         if(totalDays<=days){
//             return true;
//         }
//         return false;

//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//         int low=*max_element(weights.begin(),weights.end()),high=accumulate(weights.begin(),weights.end(),0);
//         for(auto it:weights){
//             high+=it;
//         }
//         int ans=high;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(getDays(weights,mid,days)){
//                 ans=min(ans,mid);
//                 high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return ans;
//     }
// };

//Kth missing positive number
//Brute Force approach
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         for(auto it:arr){
//             if(it<=k){
//                 k++;
//             }
//             else{
//                 break;
//             }
//         }
//         return k;
//     }
// };

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int low=0,n=arr.size(),high=n-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             int missing=arr[mid]-(mid+1);
//             if(missing<k){
//                 low=mid+1;
//             }
//             else{
//                 high=mid-1;
//             }
//         }
//         return k+high+1;
//     }
// };

//Aggressive Cows/Magnetic Force between two balls
// class Solution {
// public:
//     bool isPossible(vector<int>&position,int dist,int m){
//       int balls=1,last=position[0];
//       for(int i=1;i<position.size();i++){
//          if(position[i]-last>=dist){
//             last=position[i];
//             balls++;
//       if(balls>=m){
//     return true;
//       }
//          }
//       }
//       return false;
//     }
//     int maxDistance(vector<int>& position, int m) {
//         sort(position.begin(),position.end());
//         int n=position.size(),limit=position[n-1]-position[0],low=1,ans=limit,high=limit;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(isPossible(position,mid,m)==false){
//                 high=mid-1;
//             }
//             else{
//                 ans=mid;
//                 low=mid+1;
//             }
//         }
//         return ans;

//     }
// };

//Allocate books
// int getStudents(vector<int>&arr,int pages,int n){
//     long long student=1,nPages=0;
//     for(int i=0;i<n;i++){
//         if(nPages+arr[i]<=pages){
//             nPages+=arr[i];
//         }
//         else{
//             student++;
//             nPages=arr[i];
//         }
//     }
//     return student;
// }
// int findPages(vector<int>& arr, int n, int m) {
//     if(m>n){
//         return -1;
//     }
// long long low=*max_element(arr.begin(),arr.end()),high=accumulate(arr.begin(),arr.end(),0);
// long long ans=high;
// while(low<=high){
//     int mid=low+(high-low)/2;
//     int students=getStudents(arr,mid,n);
//     if(students>m){
//         low=mid+1;
//     }
//     else{
//         high=mid-1;
//     }
// }
// return low;
// }

//Split Array largest sum.
// class Solution {
// public:
//     int getSubarrays(vector<int>&nums,int limit){
//         int subarrays=1,sum=0;
//         for(auto it:nums){
//             if(sum+it<=limit){
//                 sum+=it;
//             }
//             else{
//                 subarrays++;
//                 sum=it;
//             }
//         }
//         return subarrays;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         if(k>nums.size()){
//             return -1;
//         }
//         long long low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             int subarrays=getSubarrays(nums,mid);
//             if(subarrays>k){
//                 low=mid+1;
//             }
//             else{
//                 high=mid-1;
//             }
//         }
//         return low;
//     }
// };
