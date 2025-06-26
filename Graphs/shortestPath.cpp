//Shortest path in DAG
// class Solution {
//       public:
//         //Function to find topo sort
//         void dfs(vector<vector<pair<int,int>>>&adj,int node,vector<bool>&visited,stack<int>&stk){
//             if(visited[node]){
//                 return;
//             }
            
//             visited[node]=true;
            
//             for(int i=0;i<adj[node].size();i++){
//                 pair<int,int>p=adj[node][i];
//                 dfs(adj,p.first,visited,stk);
//             }
            
//             stk.push(node);
//         }
        
//         vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
//             //First we'll make the adjacency list
//             vector<vector<pair<int,int>>>adj(V);
            
//             for(int i=0;i<E;i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
//                 int wt=edges[i][2];
                
//                 adj[u].push_back({v,wt});
//             }
            
//             //Finding the topoSort
            
//             vector<bool>visited(V,false);
//             stack<int>stk;
            
//             for(int i=0;i<V;i++){
//                 if(!visited[i]){
//                     dfs(adj,i,visited,stk);
//                 }
//             }
            
//             vector<int>ans(V,INT_MAX);
//             ans[0]=0;
            
//             while(!stk.empty()){
//                 int node=stk.top();
//                 stk.pop();
//                 int currNodeDist=ans[node];
                
//                 if(currNodeDist!=INT_MAX){
//                 for(int i=0;i<adj[node].size();i++){
//                     pair<int,int>p=adj[node][i];
//                     int nextNode=p.first;
//                     int wt=p.second;
//                     if(currNodeDist+wt<ans[nextNode]){
//                         ans[nextNode]=currNodeDist+wt;
//                     }
//                 }
                    
//                 }
//             }
            
//             for(int i=0;i<V;i++){
//                 if(ans[i]==INT_MAX){
//                     ans[i]=-1;
//                 }
//             }
            
//             return ans;
//         }
//     };

//Shortest Path in Undirected Graph
// class Solution {
//       public:
//         // Function to find the shortest path from source to all other nodes
//         vector<int> shortestPath(vector<vector<int>>& adj, int src) {
//             int n=adj.size();
//             vector<int>ans(n,1e6);
//             ans[src]=0;
            
            
//             queue<pair<int,int>>q;
//             q.push({src,0});
            
//             while(!q.empty()){
//                 pair<int,int>p=q.front();
//                 q.pop();
//                 int currNode=p.first;
//                 int dist=p.second;
                
//                 for(int i=0;i<adj[currNode].size();i++){
//                     int nextNode=adj[currNode][i];
//                     if(dist+1<ans[nextNode]){
//                         ans[nextNode]=dist+1;
//                         q.push({nextNode,dist+1});
//                     }
//                 }
//             }
            
//             for(int i=0;i<n;i++){
//                 if(ans[i]==1e6){
//                     ans[i]=-1;
//                 }
//             }
            
//             return ans;
//         }
//     };

// Dijkstra Algorithm (Priority Queue)
// class Solution {
//       public:
//         vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//             vector<vector<pair<int,int>>>adj(V);
            
//             for(int i=0;i<edges.size();i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
//                 int wt=edges[i][2];
                
//                 adj[u].push_back({v,wt});
//             }
            
//             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//             //Dist,Node
            
//             vector<int>ans(V,1e9);
//             ans[src]=0;
            
//             pq.push({0,src});
            
//             while(!pq.empty()){
//                 pair<int,int>p=pq.top();
//                 int node=p.second;
//                 int dist=p.first;
//                 pq.pop();
                
//                 for(int i=0;i<adj[node].size();i++){
//                     int nextNode=adj[node][i].first;
//                     int wt=adj[node][i].second;
                    
//                     if(dist+wt<ans[nextNode]){
//                         ans[nextNode]=dist+wt;
//                         pq.push({ans[nextNode],nextNode});
//                     }
//                 }
//             }
            
//             return ans;
            
//         }
//     };

//Dijkstra Algorithm (Set)
// class Solution {
//       public:
//         vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//             vector<vector<pair<int,int>>>adj(V);
            
//             for(int i=0;i<edges.size();i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
//                 int wt=edges[i][2];
                
//                 adj[u].push_back({v,wt});
//             }
            
//             set<pair<int,int>>st;
//             //Dist,Node
            
//             vector<int>ans(V,1e9);
//             ans[src]=0;
            
//             st.insert({0,src});
            
//             while(!st.empty()){
//                 pair<int,int>p=*(st.begin());
//                 int node=p.second;
//                 int dist=p.first;
//                 st.erase(*(st.begin()));
                
//                 for(int i=0;i<adj[node].size();i++){
//                     int nextNode=adj[node][i].first;
//                     int wt=adj[node][i].second;
                    
//                     if(dist+wt<ans[nextNode]){
//                         if(ans[nextNode]!=1e9){
//                             st.erase({ans[nextNode],nextNode});
//                         }
//                         ans[nextNode]=dist+wt;
//                         st.insert({ans[nextNode],nextNode});
//                     }
//                 }
//             }
            
//             return ans;
            
//         }
//     };

//Shortest Path in a binary matrix
// class Solution {
//       public:
//           int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//               int n = grid.size();
//               if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
//                   return -1;
//               }
      
//               if(n*n==1){
//                   return 1;
//               }
      
//               vector<int> ans(n * n, 1e9);
      
//               priority_queue<pair<int, pair<int, int>>,
//                              vector<pair<int, pair<int, int>>>,
//                              greater<pair<int, pair<int, int>>>>
//                   pq;
//               pq.push({1, {0, 0}});
//               // dist,node;
//               ans[0] = 1;
      
//               int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
//               int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
      
//               while (!pq.empty()) {
//                   pair<int, pair<int, int>> p = pq.top();
//                   pq.pop();
      
//                   int dist = p.first;
//                   int x = p.second.first;
//                   int y = p.second.second;
      
//                   for (int i = 0; i < 8; i++) {
//                       int nrow = x + dr[i];
//                       int ncol = y + dc[i];
      
//                       if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n)
//                           continue;
      
//                       if (grid[nrow][ncol] == 0 && 1 + dist < ans[nrow * n + ncol]) {
//                           ans[nrow * n + ncol] = 1 + dist;
//                           pq.push({ans[nrow * n + ncol], {nrow, ncol}});
//                       }
//                   }
//               }
//               return ans[n * n - 1] == 1e9 ? -1 : ans[n * n - 1];
//           }
//       };

// Path with minimum effort.
// class Solution {
//       public:
//           int minimumEffortPath(vector<vector<int>>& heights) {
//               int n=heights.size(),m=heights[0].size();
      
//               vector<vector<int>>dist(n,vector<int>(m,1e9));
//               dist[0][0]=0;
      
//               int dr[]={-1,0,1,0};
//               int dc[]={0,1,0,-1};
      
//               priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//               //{currEffort,{row,col}}
      
//               pq.push({0,{0,0}});
      
//               while(!pq.empty()){
//                   pair<int,pair<int,int>>p=pq.top();
//                   pq.pop();
//                   int currEffort=p.first;
//                   int row=p.second.first;
//                   int col=p.second.second;
      
//                   if(row==n-1 && col==m-1){
//                       return currEffort;
//                   }
                  
//                   for(int i=0;i<4;i++){
//                       int nRow=row+dr[i];
//                       int nCol=col+dc[i];
//                       if(nRow<0 || nCol<0 || nRow>=n || nCol>=m){
//                           continue;
//                       }
//                       int nextEffort=max(abs(heights[nRow][nCol]-heights[row][col]),currEffort);
//                       if(dist[nRow][nCol]>nextEffort){
//                           dist[nRow][nCol]=nextEffort;
//                           pq.push({nextEffort,{nRow,nCol}});
//                       }
//                   }
//               }
      
//               return dist[n-1][m-1];
      
//           }
//       };

//Cheapest flights with k stops
// class Solution {
//       public:
//           int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//               vector<vector<pair<int,int>>>adj(n);
//               for(int i=0;i<flights.size();i++){
//                   int u=flights[i][0];
//                   int v=flights[i][1];
//                   int wt=flights[i][2];
//                   adj[u].push_back({v,wt});
//               }
              
//               vector<int>ans(n,1e9);
//               ans[src]=0;
//               // pair<int,pair<int,int>>
//               queue<pair<int,pair<int,int>>>q;
//               q.push({0,{src,0}});
      
//               while(!q.empty()){
//                   pair<int,pair<int,int>>p=q.front();
//                   q.pop();
//                   int stops=p.first;
//                   int node=p.second.first;
//                   int price=p.second.second;
//                   if(stops>k){
//                       continue;
//                   }
      
//                   for(int i=0;i<adj[node].size();i++){
//                       int nextNode=adj[node][i].first;
//                       int wt=adj[node][i].second;
      
//                       if(price+wt<ans[nextNode] && stops<=k){
//                           ans[nextNode]=price+wt;
//                           q.push({stops+1,{nextNode,price+wt}});
//                       }
//                   }
//               }
      
//               return ans[dst]==1e9?-1:ans[dst];
//           }
//       };

//Network delay time
// class Solution {
//       public:
//           int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//               vector<vector<pair<int,int>>>adj(n+1);
      
//               for(int i=0;i<times.size();i++){
//                   int u=times[i][0];
//                   int v=times[i][1];
//                   int w=times[i][2];
//                   adj[u].push_back({v,w});
//               }
              
//               vector<int>ans(n+1,1e9);
//               ans[k]=0;
      
//               priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//               pq.push({0,k});
      
//               while(!pq.empty()){
//                   pair<int,int>p=pq.top();
//                   pq.pop();
//                   int wt=p.first;
//                   int node=p.second;
      
//                   for(int i=0;i<adj[node].size();i++){
//                       int nextNode=adj[node][i].first;
//                       int nextWt=adj[node][i].second;
      
//                       if(wt+nextWt<ans[nextNode]){
//                           ans[nextNode]=wt+nextWt;
//                           pq.push({wt+nextWt,nextNode});
//                       }
//                   }
//               }
//              int maxVal=*max_element(ans.begin()+1,ans.end());
//               return maxVal==1e9?-1:maxVal;
//           }
//       };

//No. of ways to arrive at destination
// class Solution {
// public:
//     int MOD=1e9+7;
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int,long long>>>adj(n);

//         for(int i=0;i<roads.size();i++){
//             int u=roads[i][0];
//             int v=roads[i][1];
//             long long time=roads[i][2];

//             adj[u].push_back({v,time});
//             adj[v].push_back({u,time});
//         }

//         vector<pair<long long,int>>ans(n,{1e18,0});
//         //time,ways
//         ans[0]={0,1};

//         priority_queue< pair<long long,int>, vector< pair<long long,int> >,greater<pair<long long,int>> >pq;
//         //time,node

//         pq.push({0,0});

//         while(!pq.empty()){
//             pair<long long,int>p=pq.top();
//             pq.pop();

//             long long time=p.first;
//             int node=p.second;

//             if(time>ans[node].first){
//                 continue;
//             }

//             for(int i=0;i<adj[node].size();i++){
//                 pair<int,int>pp=adj[node][i];
//                 int nextNode=pp.first;
//                 long long nextTime=pp.second;
//                 long long totalTime=time+nextTime;

//                 if(ans[nextNode].first>=totalTime){
//                     if(ans[nextNode].first==totalTime){
//                         ans[nextNode].second=(ans[nextNode].second+ans[node].second)%MOD;
//                     }
//                     else{
//                         ans[nextNode].first=totalTime;
//                         ans[nextNode].second=(ans[node].second)%MOD;
//                         pq.push({totalTime,nextNode});
//                     }
//                 }
//             }
//         }

//         return (ans[n-1].second)%MOD;

//     }
// };

//Minimum Multiplications to reach End
// class Solution {
//   public:
//     int MOD=1e5;
//     int minimumMultiplications(vector<int>& arr, int start, int end) {
//         // code here
        
//         vector<int>dist(MOD,1e9);
//         dist[start]=0;
//         queue<pair<int,int>>q;
//         q.push({0,start});
        
        
//         while(!q.empty()){
//             pair<int,int>p=q.front();
//             q.pop();
//             int steps=p.first;
//             int value=p.second;
            
//             for(int i=0;i<arr.size();i++){
//                 int nextValue=(value*arr[i])%MOD;
                
//                 if(dist[nextValue]>steps+1){
//                 dist[nextValue]=steps+1;
//                 q.push({steps+1,nextValue});
//                 }
//             }
//         }
        
//         return dist[end]==1e9?-1:dist[end];
//     }
// };

//Bellman Ford Algorithm
// class Solution {
//   public:
//     vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
            
//         vector<int>dist(V,1e8);
        
//         dist[src]=0;
        
//         for(int i=0;i<V-1;i++){
            
            
//             for(int i=0;i<edges.size();i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
//                 int w=edges[i][2];
                
//                 if(dist[u]!=1e8 && dist[u]+w<dist[v]){
//                     dist[v]=w+dist[u];
//                 }
//             }
            
//         }
        
//         for(int i=0;i<edges.size();i++){
//             int u=edges[i][0];
//             int v=edges[i][1];
//             int w=edges[i][2];
            
//             if(dist[u]!=1e8 && dist[u]+w<dist[v]){
//                 return {-1};
//             }
//         }
        
//         return dist;
        
//     }
// };

//Floyd Warshall
// class Solution {
//   public:
//     void floydWarshall(vector<vector<int>> &dist) {
//         int n=dist.size();
        
//         for(int k=0;k<n;k++){
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<n;j++){
// if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
//     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
// }
//                 }
//             }
//         }
        
//     }
// };

// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>>mat(n,vector<int>(n,1e8));

//         for(int i=0;i<edges.size();i++){
            
//             int u=edges[i][0];
//             int v=edges[i][1];
//             int wt=edges[i][2];
//             if(mat[u][u]==1e8){
//                 mat[u][u]=0;
//             }

//             if(mat[v][v]==1e8){
//                 mat[v][v]=0;
//             }
//             mat[u][v]=wt;
//             mat[v][u]=wt;
//         }

//         for(int k=0;k<n;k++){
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<n;j++){
//                     if(mat[i][k]!=1e8 && mat[k][j]!=1e8){
//                         mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
//                     }
//                 }
//             }
//         }

//         int ansCity=-1,minCities=INT_MAX;


//         for(int i=0;i<n;i++){
//             int count=0;
//             // cout<<i<<": ";
//             for(int j=0;j<n;j++){
//                 // cout<<mat[i][j]<<" ";
//                 if(mat[i][j]==1e8){
//                     continue;
//                 }

//                 if(mat[i][j]<=distanceThreshold){
//                     count++;
//                 }

//             }
//             // cout<<endl;

//             if(count<=minCities){
//                 minCities=count;
//                 ansCity=i;
//             }
//         }



//         return ansCity;
//     }
// };