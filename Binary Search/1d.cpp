//Binary Search to find x in a sorted array.
// class Solution {
// public:
// int getAns(vector<int>&nums,int start,int end,int target){
//     if(start>end){
//         return -1;
//     }
//     int mid=(start+end)/2;
//     if(nums[mid]==target){
//         return mid;
//     }
//     else if(target>nums[mid]){
//         return getAns(nums,mid+1,end,target);
//     }
//     else{
//         return getAns(nums,start,mid-1,target);
//     }
// }
//     int search(vector<int>& nums, int target) {
//         int ans=getAns(nums,0,nums.size()-1,target);
//         return ans;
//     }
// };

//Implement Lower Bound:- Smallest value of index such that arr[index]>=target.
// int findLowerBound(vector<int>nums,int target){
//       int low=0,high=nums.size()-1,ans=nums.begin();
//       while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]>=target){
//                   ans=mid;
//                   high=mid-1;
//             }
//             else{
//                   low=mid+1;
//             }
//       }
//       return ans;
// }

//Or simply use the lower_bound() function, it returns an iterator to the lower bound index.

//Implement Upper Bound=Smallest value of index such taht arr[index]>target.
// int findUpperBound(vector<int>nums,int target){
//       int low=0,high=nums.size()-1,ans=nums.begin();
//       while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]>target){
//                   ans=mid;
//                   high=mid-1;
//             }
//             else{
//                   low=mid+1;
//             }
//       }
//       return ans;
// }
// Or simply use the upper_bound() function, it returns an iterator to the lower bound index.

//Search Insert Position
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
//     }
// };

//Find floor/ceil
// pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
// //finding the ceiling
// int ans1=-1,low=0,high=n-1;
// while(low<=high){
// 	int mid=low+(high-low)/2;
// 	if(a[mid]>=x){
// 		ans1=a[mid];
// 		high=mid-1;
// 	}
// 	else{
// 		low=mid+1;
// 	}
// }
// //finding the floor
// int ans2=-1;
// low=0;
// high=n-1;
// while(low<=high){
// 	int mid=low+(high-low)/2;
// 	if(a[mid]<=x){
// 		ans2=a[mid];
// 		low=mid+1;
// 	}
// 	else{
// 		high=mid-1;
// 	}
// }
// pair<int,int>p=make_pair(ans2,ans1);
// return p;
// }

//First and last occurence of a number in a sorted array.
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin(),n=nums.size();
//         vector<int>ans;
//         if(lb>=n || nums[lb]!=target){
//             ans.push_back(-1);
//             ans.push_back(-1);
//             return ans;
//         }
//         int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
//         ans.push_back(lb);
//         ans.push_back(ub-1);
//         return ans;
//     }
// };

//Count occurrences of a number in a sorted array with duplicates
// class Solution{
// public:	
// 	/* if x is present in arr[] then returns the count
// 		of occurrences of x, otherwise returns 0. */
// 	int count(int arr[], int n, int x) {
// 	    int lb=lower_bound(arr,arr+n,x)-arr;
// 	    if(arr[lb]!=x){
// 	        return 0;
// 	    }
// 	    int ub=upper_bound(arr,arr+n,x)-arr;
// 	    return ub-lb;
// 	}
// };

//Search in a rotated sorted array.
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n=nums.size(),low=0,high=n-1,ans=-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]==target){
//                 ans=mid;
//                 return ans;
//             }
//             //If left part is sorted
//             if(nums[low]<=nums[mid]){
//                if(target>=nums[low] && target<nums[mid]){
//                 high=mid-1;
//                }
//                else{
//                 low=mid+1;
//                }
//             }
//             //If right part is sorted.
//             else{
//                 if(target>nums[mid] && target<=nums[high]){
//                     low=mid+1;
//                 }
//                 else{
//                     high=mid-1;
//                 }
//             }
            
//         }
//         return ans;
//     }
// };

//Search in a rotated sorted array part 2
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int n=nums.size(),low=0,high=n-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]==target){
//                 return true;
//             }
//             if(nums[low]==nums[mid] && nums[low]==nums[high]){
//                 low++;
//                 high--;
//                 continue;
//             }
//             if(nums[low]<=nums[mid]){
//                 if(target>=nums[low] && target<nums[mid]){
//                     high=mid-1;
//                 }
//                 else{
//                     low=mid+1;
//                 }
//             }
//             else{
//                 if(target>nums[mid] && target<=nums[high]){
//                     low=mid+1;
//                 }
//                 else{
//                     high=mid-1;
//                 }
//             }
//         }
//         return false;
//     }
// };

//Find minimum in rotated sorted array
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int ans=INT_MAX,low=0,n=nums.size(),high=n-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             //completely sorted
//             if(nums[low]<=nums[mid] && nums[mid]<=nums[high]){
//                 ans=min(ans,nums[low]);
//                 break;
//             }
//             //left sorted
//             if(nums[low]<=nums[mid]){
//               ans=min(ans,nums[low]);
//               low=mid+1;
//             }
//             //right sorted
//             else{
//                 ans=min(ans,nums[mid]);
//                 high=mid-1;
//             }
//         }
//         return ans;
//     }
// };

//Find out how many times an array has been rotated
// class Solution{
// public:	
// 	int findKRotation(int arr[], int n) {
//         int low=0,high=n-1,ans=INT_MAX,index=-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(arr[low]<=arr[mid]){
//                 if(arr[low]<ans){
//                     ans=arr[low];
//                     index=low;
//                 }
//                 low=mid+1;
//             }
//             else{
//                if(arr[mid]<ans){
//                    ans=arr[mid];
//                    index=mid;
//                } 
//                high=mid-1;
//             }
//         }
//         return index;
// 	}

// };