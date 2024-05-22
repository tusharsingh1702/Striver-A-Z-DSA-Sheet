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