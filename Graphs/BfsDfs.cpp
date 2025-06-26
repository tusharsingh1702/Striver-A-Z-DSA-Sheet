//Number of provinces
// class Solution {
//       public:
//           void dfs(int node,vector<vector<int>>&isConnected,vector<bool>&visited,int n){
//               if(visited[node]){
//                   return;
//               }
      
//               visited[node]=true;
      
//               for(int i=0;i<n;i++){
//                   if(isConnected[node-1][i]==1 && visited[i+1]==false){
//                       dfs(i+1,isConnected,visited,n);
//                   }
//               }
//           }
//           int findCircleNum(vector<vector<int>>& isConnected) {
//               int n=isConnected.size();
      
//               vector<bool>visited(n+1,false);
//               int ans=0;
      
//               for(int i=1;i<=n;i++){
//                   if(visited[i]==false){
//                       dfs(i,isConnected,visited,n);
//                       ans++;
//                   }
//               }
      
//               return ans;
//           }
//       };

//Rotting Oranges
// class Solution {
//       public:
//           int orangesRotting(vector<vector<int>>& grid) {
      
//               int m=grid.size(),n=grid[0].size();
//               // {{row,col},time}
//               queue<pair<pair<int,int>,int>>q;
      
//               int freshOranges=0;
//               vector<vector<int>>visited(m,vector<int>(n,0));
      
//               for(int i=0;i<m;i++){
//                   for(int j=0;j<n;j++){
//                       if(grid[i][j]==2){
//                           q.push({{i,j},0});
//                           visited[i][j]=2;
//                       }
      
//                       if(grid[i][j]==1){
//                           freshOranges++;
//                       }
//                   }
//               }
      
//               if(freshOranges==0){
//                   return 0;
//               }
      
//               int delRow[4]={-1,0,1,0};
//               int delCol[4]={0,1,0,-1};
//               int time=0;
      
//               while(!q.empty()){
//                   int row=q.front().first.first;
//                   int col=q.front().first.second;
//                   int t=q.front().second;
//                   q.pop();
      
//                   time=max(time,t);
      
//                   for(int i=0;i<4;i++){
//                   int rr=row+delRow[i];
//                   int cc=col+delCol[i];
      
//                   if(rr>=0 && rr<m && cc>=0 && cc<n && grid[rr][cc]==1 && visited[rr][cc]!=2){
//                       q.push({{rr,cc},t+1});
//                       visited[rr][cc]=2;
//                       freshOranges--;
//                   }
//               }
//               }
//               return freshOranges==0?time:-1;
              
//           }
//       };

//Flood Fill
// class Solution {
//       public:
//           int delRow[4] = {-1, 0, 1, 0};
//           int delCol[4] = {0, 1, 0, -1};
//           int m, n;
          
//           void getAns(vector<vector<int>>& image, int row, int col, int color, vector<vector<int>>& visited, int initialColor) {
//               if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || image[row][col] != initialColor) {
//                   return;
//               }
      
//               visited[row][col] = 1;
//               image[row][col] = color;  
              
//               for (int i = 0; i < 4; i++) {
//                   int rr = row + delRow[i];
//                   int cc = col + delCol[i];
//                   getAns(image, rr, cc, color, visited, initialColor);
//               }
//           }
          
//           vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//               if (image[sr][sc] == color) {
//                   return image;  
//               }
      
//               m = image.size();
//               n = image[0].size();
//               vector<vector<int>> visited(m, vector<int>(n, 0));
      
//               int initialColor = image[sr][sc];  
//               getAns(image, sr, sc, color, visited, initialColor);
              
//               return image;
//           }
//       };

//Undirected Graph Cycle (BFS)
// class Solution {
//       public:
//         bool bfs(queue<pair<int,int>>&q,vector<bool>&visited,vector<vector<int>>&adj){
//              while(!q.empty()){
//                 int node=q.front().first;
//                 int comingFrom=q.front().second;
//                 q.pop();
                
//                 for(int i=0;i<adj[node].size();i++){
//                     if(adj[node][i]==comingFrom){
//                         continue;
//                     }
//                     else if(visited[adj[node][i]]){
//                         return true;
//                     }
//                     else{
//                         q.push({adj[node][i],node});
//                         visited[adj[node][i]]=true;
//                     }
//                 }
//             }
            
//             return false;
//         }
//         bool isCycle(vector<vector<int>>& adj) {
//             //{node, coming from}
//             queue<pair<int,int>>q;
//             vector<bool>visited(adj.size(),false);
            
//             for(int i=0;i<adj.size();i++){
//                 if(!visited[i]){
//             q.push({i,-1});
//             visited[i]=true;
//             bool ans=bfs(q,visited,adj);
//             if(ans==true){
//                 return true;
//             }
//                 }
//             }
    
//             return false;
//         }
//     };

//Using DFS
// class Solution {
//       public:
    
//         bool dfs(int node,int comingFrom,vector<vector<int>>&adj,vector<bool>&visited){
//             if(visited[node]){
//                 return true;
//             }
            
//             visited[node]=true;
            
//             for(int i=0;i<adj[node].size();i++){
//                 if(adj[node][i]!=comingFrom){
//                     bool ans=dfs(adj[node][i],node,adj,visited);
//                     if(ans){
//                         return true;
//                     }
//                 }
//             }
            
//             return false;
//         }
//         bool isCycle(vector<vector<int>>& adj) {
//             int n=adj.size();
            
//             vector<bool>visited(n,false);
            
//             for(int i=0;i<n;i++){
//                 if(!visited[i]){
//                     bool ans=dfs(i,-1,adj,visited);
//                     if(ans){
//                         return true;
//                     }
//                 }
//             }
            
            
//             return false;
//         }
//     };

// 0/1 Matrix
// class Solution {
//       public:
//           vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//               int m=mat.size(),n=mat[0].size();
//               queue<pair<pair<int,int>,int>>q;
//               vector<vector<int>>ans(m,vector<int>(n,0));
//               vector<vector<bool>>visited(m,vector<bool>(n,false));
      
//               for(int i=0;i<m;i++){
//                   for(int j=0;j<n;j++){
//                       if(mat[i][j]==0){
//                           q.push({{i,j},0});
//                           visited[i][j]=true;
//                       }
//                   }
//               }
      
//               int dr[4]={-1,0,1,0};
//               int dc[4]={0,1,0,-1};
      
//               while(!q.empty()){
//                   int row=q.front().first.first;
//                   int col=q.front().first.second;
//                   int dist=q.front().second;
//                   q.pop();
      
//                   if(mat[row][col]==1){
//                       ans[row][col]=dist;
//                   }
      
//                   for(int i=0;i<4;i++){
//                       int nRow=row+dr[i];
//                       int nCol=col+dc[i];
//                       int nDist=dist+1;
      
//                       if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && !visited[nRow][nCol]){
//                           q.push({{nRow,nCol},nDist});
//                           visited[nRow][nCol]=true;
//                       }
//                   }
      
//               }
      
//               return ans;
      
//           }
//       };

//Sorrounded Regions
//sabse pehle boundary cells mein jo O's hn unpe jaake DFS karna hoga, un O's se jo O's connected hn unko hum X nhi bna sakte.
// fir jo O's bache unko jaake X bna denge
// class Solution {
//       public:
//           int dr[4]={-1,0,1,0};
//           int dc[4]={0,1,0,-1};
//           int m,n;
//           void dfs(int row,int col,vector<vector<char>>&board,vector<vector<bool>>&visited){
//               if(row<0 || row>=m || col<0 || col>=n || visited[row][col] || board[row][col]=='X'){
//                   return;
//               }
      
//               visited[row][col]=true;
      
//               for(int i=0;i<4;i++){
//                   int nRow=row+dr[i];
//                   int nCol=col+dc[i];
//                   dfs(nRow,nCol,board,visited);
//               }
//           }
      
//           void solve(vector<vector<char>>& board) {
//               m=board.size(),n=board[0].size();
      
//               vector<vector<bool>>visited(m,vector<bool>(n,false));
      
//               //first row && last row;
//               for(int i=0;i<n;i++){
//                   if(board[0][i]=='O' && !visited[0][i]){
//                       cout<<0<<' '<<i<<endl;
//                       dfs(0,i,board,visited);
//                   }
//                   if(board[m-1][i]=='O' && !visited[m-1][i]){
//                                       cout<<m-1<<' '<<i<<endl;
//                       dfs(m-1,i,board,visited);
//                   }
//               }
      
//               //first col and last col
//               for(int i=1;i<m-1;i++){
//                   if(board[i][0]=='O' && !visited[i][0]){
//                                       cout<<i<<' '<<0<<endl;
//                       dfs(i,0,board,visited);
//                   }
//                   if(board[i][n-1]=='O' && !visited[i][n-1]){
//                                       cout<<i<<' '<<n-1<<endl;
//                       dfs(i,n-1,board,visited);
//                   }
//               }
      
//               //marking rest of the O's to X's
//               for(int i=1;i<m-1;i++){
//                   for(int j=1;j<n-1;j++){
//                       if(board[i][j]=='O' && !visited[i][j]){
//                           board[i][j]='X';
//                       }
//                   }
//               }
      
      
//           }
//       };

//Number of Enclaves
// class Solution {
//       public:
//       int m,n;
//       int dr[4]={-1,0,1,0};
//       int dc[4]={0,1,0,-1};
//           pair<bool,int>dfs(vector<vector<int>>&grid,int row,int col,vector<vector<bool>>&visited){
//               if(row<0 || row>=m || col<0 || col>=n){
//                   return {true,0};
//               }
//               if(visited[row][col] || grid[row][col]==0){
//                   return {false,0};
//               }
//               visited[row][col]=true;
//               bool walkOff=false;
//               int count=1;
//               for(int i=0;i<4;i++){
//                   int nRow=row+dr[i];
//                   int nCol=col+dc[i];
//                   pair<bool,int>ans=dfs(grid,nRow,nCol,visited);
//                   walkOff|=ans.first;
//                   count+=ans.second;
//               }
      
//               return {walkOff,count};
      
//           }
//           int numEnclaves(vector<vector<int>>& grid) {
//               m=grid.size(),n=grid[0].size();
//               int count=0;
//               vector<vector<bool>>visited(m,vector<bool>(n,false));
      
//               for(int i=0;i<m;i++){
//                   for(int j=0;j<n;j++){
//                       if(grid[i][j]==1 && !visited[i][j]){
//                           pair<bool,int>ans=dfs(grid,i,j,visited);
//                           if(ans.first==false){
//                               count+=ans.second;
//                           }
//                       }
//                   }
//               }
      
//               return count;
      
//           }
//       };

//Number of distinct islands
// class Solution {
//       // private:
//       public:
//       int m,n;
//       int dr[4]={-1,0,1,0};
//       int dc[4]={0,1,0,-1};
//     public:
//       void dfs(vector<vector<int>>&grid,int row,int col,vector<vector<bool>>&visited,int r0,int c0,vector<pair<int,int>>&vec){
//           if(row<0 || row>=m || col<0 || col>=n || visited[row][col] || grid[row][col]==0){
//               return;
//           }
//           visited[row][col]=true;
//           vec.push_back({row-r0,col-c0});
//           // cout<<row<<' '<<col<<endl;
//           for(int i=0;i<4;i++){
//               int nRow=row+dr[i];
//               int nCol=col+dc[i];
//               dfs(grid,nRow,nCol,visited,r0,c0,vec);
//           }
          
//       }
//       int countDistinctIslands(vector<vector<int>>& grid) {
//           m=grid.size(),n=grid[0].size();
//           vector<vector<bool>>visited(m,vector<bool>(n,false));
          
//           set<vector<pair<int,int>>>st;
          
//           for(int i=0;i<m;i++){
//               for(int j=0;j<n;j++){
//                   if(grid[i][j]==1 && !visited[i][j]){
//                       vector<pair<int,int>>vec;
//                       dfs(grid,i,j,visited,i,j,vec);
//                       st.insert(vec);
//                   }
//               }
//           }
          
//           return st.size();
          
//       }

//Is Graph Bipartite (Using BFS)
// class Solution {
//       public:
//           bool dfs(vector<vector<int>>&graph,int node,int n,vector<int>&colors){
//               queue<int>q;
//               q.push(node);
//               colors[node]=0;
      
//               while(!q.empty()){
//                   int node=q.front();
//                   int color=colors[node];
//                   q.pop();
      
//                   for(int i=0;i<graph[node].size();i++){
//                       int adjNode=graph[node][i];
      
//                       if(colors[adjNode]!=-1){
//                           if(colors[adjNode]==color){
//                               return false;
//                           }
//                       }
//                       else{
//                           int adjColor=(color==1?0:1);
//                           colors[adjNode]=adjColor;
//                           q.push(adjNode);
//                       }
//                   }
//               }
      
//               return true;
//           }
      
//           bool isBipartite(vector<vector<int>>& graph) {
//               int n=graph.size();
//               vector<int>colors(n,-1);
      
//               for(int i=0;i<n;i++){
//                   if(colors[i]==-1){
//                       bool ans=dfs(graph,i,n,colors);
//                       if(!ans){
//                           return false;
//                       }
//                   }
//               }
//               return true;
              
//           }
//       };

//Using DFS
// class Solution {
//       public:
//           bool dfs(vector<vector<int>>&graph,int node,int n,vector<int>&colors){
//               for(int i=0;i<graph[node].size();i++){
//                   int adjNode=graph[node][i];
//                   int color=colors[node];
//                   int adjColor=(color==0?1:0);
//                   if(colors[adjNode]!=-1){
//                       if(colors[adjNode]!=adjColor){
//                           return false;
//                       }
//                       continue;
//                   }
//                   colors[adjNode]=adjColor;
//                   bool ans=dfs(graph,adjNode,n,colors);
//                   if(ans==false){
//                       return false;
//                   }
//               }
//               return true;
//           }
//           bool isBipartite(vector<vector<int>>& graph) {
//               int n=graph.size();
//               vector<int>colors(n,-1);
      
//               for(int i=0;i<n;i++){
//                   if(colors[i]==-1){
//                       colors[i]=0;
//                      bool ans= dfs(graph,i,n,colors);
//                      if(!ans){
//                       return false;
//                      }
//                   }
//               }
      
//               return true;
//           }
//       };

//Detecting a cycle in a directed graph
// class Solution {
//       public:
//         bool dfs(int currNode,int V,vector<int>adj[],vector<int>&visited,vector<int>&path){
//             if(visited[currNode]!=-1){
//                 if(path[currNode]!=-1){
//                     return true;
//                 }
//                 return false;
//             }
            
//             visited[currNode]=1;
//             path[currNode]=1;
            
//             for(auto it:adj[currNode]){
//                 int nextNode=it;
                
//                 if(dfs(nextNode,V,adj,visited,path)){
//                     return true;
//                 }
//             }
            
//             path[currNode]=-1;
            
//             return false;
//         }
//         bool isCyclic(int V, vector<vector<int>> &edges) {
//             vector<int>adj[V];
//             int n=edges.size();
            
//             for(int i=0;i<n;i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
                
//                 adj[u].push_back(v);
//             }
            
//             vector<int>visited(V,-1),path(V,-1);
            
            
//             for(int i=0;i<V;i++){
//                 if(visited[i]==-1){
//                     if(dfs(i,V,adj,visited,path)){
//                         return true;
//                     }
//                 }
//             }
            
//             return false;
            
//         }
//     };

