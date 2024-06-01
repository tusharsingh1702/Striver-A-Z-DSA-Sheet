//Row with maximum number of 1's
// class Solution{
// public:
// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    int maxZeros=0,ansRow=-1;
// 	    for(int i=0;i<n;i++){
// 	        int lb=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
// 	        int nZeros=m-lb;
//             if(nZeros>maxZeros){
//                 maxZeros=nZeros;
//                 ansRow=i;
//             }
// 	    }
// 	    return ansRow;
// 	}
// };

//Search in a 2D Matrix
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size(),m=matrix[0].size();
//          for(int i=0;i<n;i++){
//             if(target>=matrix[i][0] && target<=matrix[i][m-1]){
//                if(binary_search(matrix[i].begin(),matrix[i].end(),target)){
//                 return true;
//                }
//             }
//          }
//          return false;
//     }
// };

//Search a 2D matrix II
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row=0,col=matrix[0].size()-1,n=matrix.size();
//         while(row<n && col>=0){
//             if(matrix[row][col]==target){
//                 return true;
//             }
//             else if(matrix[row][col]<target){
//                 row++;
//             }
//             else{
//                 col--;
//             }
//         }
//         return false;
//     }
// };

//Find peak element (2D matrix)
// class Solution {
// public:
//     int findMaxRow(vector<vector<int>>&mat,int col){
//         int index=-1,maxElement=INT_MIN;
//         for(int i=0;i<mat.size();i++){
//             if(mat[i][col]>maxElement){
//                 maxElement=mat[i][col];
//                 index=i;
//             }
//         }
//         return index;
//     }
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//       int low=0,high=mat[0].size()-1;
//       vector<int>v;
//       while(low<=high){
//         int mid=low+(high-low)/2;
//         int maxRow=findMaxRow(mat,mid);
//         int left=mid-1>=0?mat[maxRow][mid-1]:-1;
//         int right=mid+1<mat[0].size()?mat[maxRow][mid+1]:-1;
//         if(mat[maxRow][mid]>left && mat[maxRow][mid]>right){
//             v.push_back(maxRow);
//             v.push_back(mid);
//             return v;
//         }
//         if(left>mat[maxRow][mid]){
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//       }
//       v.push_back(-1);
//       v.push_back(-1);
//       return v;

//     }
// };

//Matrix Median
// class Solution{   
// public:
//     void findHighLow(vector<vector<int>>&matrix,int&low,int&high){
//         int m=matrix.size(),n=matrix[0].size();
//         int maxi=INT_MIN,mini=INT_MAX;
//         for(int i=0;i<m;i++){
//             mini=min(mini,matrix[i][0]);
//         }
//         for(int i=0;i<m;i++){
//             maxi=max(maxi,matrix[i][n-1]);
//         }
//         low=mini;high=maxi;
//     }
//     int findCount(vector<vector<int>>&matrix,int mid,int R,int C){
//         int count=0;
//         for(int i=0;i<R;i++){
//             int up=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
//             count+=up;
//         }
//         return count;
//     }
//     int median(vector<vector<int>> &matrix, int R, int C){
//         int low,high;
//         findHighLow(matrix,low,high);
//         // cout<<low<<endl;
//         // cout<<high<<endl;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             int count=findCount(matrix,mid,R,C);
//             if(count<=(R*C)/2){
//                 low=mid+1;
//             }
//             else{
//                 high=mid-1;
//             }
//         }
//         return low;
//     }
// };

//Painter's partition
// Similar to split array largest sum

//Minimise maximum distance to to gas station

//Median of 2 sorted arrays
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1=nums1.size(),n2=nums2.size();
//         if(n1>n2){
//             return findMedianSortedArrays(nums2,nums1);
//         }
//         int left=(n1+n2+1)/2,low=0,high=n1,n=n1+n2;
//         while(low<=high){
//             int mid1=low+(high-low)/2;
//             int mid2=left-mid1,l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
//             if(mid1<n1){
//                 r1=nums1[mid1];
//             }
//             if(mid2<n2){
//                 r2=nums2[mid2];
//             }
//            if(mid1-1>=0){
//                 l1=nums1[mid1-1];
//             } 
//             if(mid2-1>=0){
//                 l2=nums2[mid2-1];
//             }
//             if(l1<=r2 && l2<=r1){
//                 if(n%2==0){
//                     double ans=(double)(max(l1,l2)+min(r1,r2))/2;
//                     return ans;
//                 }
//                 else{
//                     return (double)max(l1,l2);
//                 }
//             }
//             else if(l1>r2){
//                 high=mid1-1;
//             }
//             else{
//                 low=mid1+1;
//             }
//         }
//         return -1;
//     }
// };

//kth element of two sorted arrays
//  class Solution{
//     public:
//     int kthElement(int arr1[], int arr2[], int n, int m, int k)
//     {
//         if(n>m){
//             return kthElement(arr2,arr1,m,n,k);
//         }
//         int left=k,low=max(0,k-m),high=min(k,n);
//         while(low<=high){
//             int mid1=low+(high-low)/2;
//             int mid2=left-mid1,l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
//             if(mid1-1>=0){
//                 l1=arr1[mid1-1];
//             }
//             if(mid2-1>=0){
//                 l2=arr2[mid2-1];
//             }
//             if(mid1<n){
//                 r1=arr1[mid1];
//             }
//              if(mid2<m){
//                 r2=arr2[mid2];
//             }
//             if(l1<=r2 && l2<=r1){
//                 return max(l1,l2);
//             }
//             else if(l1>l2){
//                 high=mid1-1;
//             }
//             else{
//                 low=mid1+1;
//             }
            
//         }
//         return -1;
//     }
// };