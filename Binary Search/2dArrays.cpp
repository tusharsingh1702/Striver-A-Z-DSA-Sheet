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
class Solution{   
public:
    void findHighLow(vector<vector<int>>&matrix,int&low,int&high){
        int m=matrix.size(),n=matrix[0].size();
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,matrix[i][0]);
        }
        for(int i=0;i<m;i++){
            maxi=max(maxi,matrix[i][n-1]);
        }
        low=mini;high=maxi;
    }
    int findCount(vector<vector<int>>&matrix,int mid,int R,int C){
        int count=0;
        for(int i=0;i<R;i++){
            int up=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            count+=up;
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low,high;
        findHighLow(matrix,low,high);
        // cout<<low<<endl;
        // cout<<high<<endl;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=findCount(matrix,mid,R,C);
            if(count<=(R*C)/2){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};