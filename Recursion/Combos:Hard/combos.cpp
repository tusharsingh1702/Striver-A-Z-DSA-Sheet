//N Queens

// void getAns(int col,vector<string>board,vector<vector<string>>&ans,vector<int>leftRow,vector<int>lowerDiagonal,vector<int>upperDiagonal,int n){
//     if(col==n){
//         ans.push_back(board);
//         return;
//     }
//     for(int row=0;row<n;row++){
//         if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
//             leftRow[row]=1;
//             lowerDiagonal[row+col]=1;
//             upperDiagonal[n-1+col-row]=1;
//             board[row][col]='Q';
//             getAns(col+1,board,ans,leftRow,lowerDiagonal,upperDiagonal,n);
//             board[row][col]='.';
//             leftRow[row]=0;
//             lowerDiagonal[row+col]=0;
//             upperDiagonal[n-1+col-row]=0;
//         }
//     }
// }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         vector<string>board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++){
//             board[i]=s;
//         }
//         vector<int>leftRow(n,0),lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
//         getAns(0,board,ans,leftRow,lowerDiagonal,upperDiagonal,n);
//         return ans;
//     }
