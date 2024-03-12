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

// Sudoku Solver
//     void solveSudoku(vector<vector<char>>& board) {
//          solve(board);
//     }
//     bool solve(vector<vector<char>>&board){
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 if(board[i][j]=='.'){
//                     for(char c='1';c<='9';c++){
//                         if(isValid(board,c,i,j)){
//                             board[i][j]=c;
//                             if(solve(board)){
//                                 return true;
//                             }
//                             else{
//                                 board[i][j]='.';
//                             }

//                         }
//                     }
//                         return false;
//                 }
//             }
//         }
//                 return true;
//     }
//     bool isValid(vector<vector<char>>&board,char c,int row,int col){
//          for(int i=0;i<9;i++){
//             if(board[i][col]==c){
//                 return false;
//             }
//             if(board[row][i]==c){
//                 return false;
//             }
//             if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c){
//                 return false;
//             }
//          }
//          return true;
//     }