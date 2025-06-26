//Graph and Types
// class Solution {
//       public:
//         long long count(int n) {
//             long long x=n*(n-1)/2;
//             long long ans=pow(2,x);
            
//             return ans;
//         }
//     };


//Graph Representation
// class Solution {
//       public:
//         // Function to return the adjacency list for each vertex.
//         vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
//             vector<vector<int>>adj(V);
            
//             int n=edges.size();
            
//             for(int i=0;i<n;i++){
//                 int u=edges[i].first;
//                 int v=edges[i].second;
//                 adj[u].push_back(v);
//                 adj[v].push_back(u);
//             }
            
//             return adj;
//         }
//     };

//BFS of a graph aka level order traversal
// class Solution {
//       public:
//         // Function to return Breadth First Traversal of given graph.
//         vector<int> bfsOfGraph(vector<vector<int>> &adj) {
            
//             vector<int>ans;
//             queue<int>q;
//             q.push(0);
//             unordered_map<int,bool>visited;
//             visited[0]=true;
            
//             while(!q.empty()){
//                 int front=q.front();
//                 q.pop();
//                 ans.push_back(front);
                
//                 for(int it:adj[front]){
//                     if(visited[it]==true){
//                         continue;
//                     }
//                     visited[it]=true;
//                     q.push(it);
//                 }
//             }
            
//             return ans;
//         }
//     };

//DFS
// class Solution {
//       public:
//         void getAns(int node,vector<vector<int>>&adj,unordered_map<int,bool>&visited,vector<int>&ans){
//             if(visited[node]==true){
//                 return;
//             }
//             ans.push_back(node);
            
//             for(auto it:adj[node]){
//                 if(visited.find(it)==visited.end()){
//                     getAns(it,adj,visited,ans);
//                 }
//             }
//         }
        
        
//         vector<int> dfsOfGraph(vector<vector<int>>& adj) {
//             vector<int>ans;
//             unordered_map<int,bool>visited;
//             getAns(0,adj,visited,ans);
            
//             return ans;
//         }
//     };