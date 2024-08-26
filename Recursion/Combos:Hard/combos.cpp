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

// M Coloring Problem
// class Solution{
// public:
//     // Function to determine if graph can be coloured with at most M colours such
//     // that no two adjacent vertices of graph are coloured with same colour.
//     bool isSafe(int node,bool graph[101][101],int i,int*color,int n){
//             for(int k=0;k<n;k++){
//                 if(k!=node && graph[k][node]==1 && color[k]==i){
//                     return false;
//                 }
//             }
//             return true;
//     }
//     bool getAns(int node,bool graph[101][101],int*color,int m,int n){
//         if(node==n){
//             return true;
//         }
//         for(int i=1;i<=m;i++){
//             if(isSafe(node,graph,i,color,n)){
//                 color[node]=i;
//                if(getAns(node+1,graph,color,m,n)){
//                    return true;
//                }
//                else{
//                    color[node]=0;
//                }
//             }
//         }
//         return false;
//     }
//     bool graphColoring(bool graph[101][101], int m, int n) {
//         int color[n]={0};
//         return getAns(0,graph,color,m,n);
//     }
// };

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