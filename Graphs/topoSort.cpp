// Topo sort using DFS
// class Solution {
//       public:
//         void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&stk){
//             if(visited[node]){
//                 return;
//             }
//             visited[node]=true;
            
//             for(int i=0;i<adj[node].size();i++){
//                 int nextNode=adj[node][i];
//                 dfs(nextNode,adj,visited,stk);
//             }
            
//             stk.push(node);
//         }
//         vector<int> topoSort(int V, vector<vector<int>>& edges) {
//             vector<int>ans;
//             vector<bool>visited(V,false);
            
//             stack<int>stk;
//             vector<vector<int>>adj(V);
//             for(int i=0;i<edges.size();i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
                
//                 adj[u].push_back(v);
//             }
            
//             for(int i=0;i<V;i++){
//                 if(!visited[i]){
//                     dfs(i,adj,visited,stk);
//                 }
//             }
            
//             while(!stk.empty()){
//                 ans.push_back(stk.top());
//                 stk.pop();
//             }
            
//             return ans;
            
//         }
//     };

//Kahn's Algorithm(BFS approach to find Topo Sort)

// class Solution {
//       public:
//         vector<int> topoSort(int V, vector<vector<int>>& edges) {
                
//                 vector<int>inDegree(V,0);
//                 vector<vector<int>>adj(V);
//                 int n=edges.size();
                
//                 for(int i=0;i<n;i++){
//                     int u=edges[i][0];
//                     int v=edges[i][1];
                    
//                     adj[u].push_back(v);
                    
//                     inDegree[v]++;
//                 }
                
//                 queue<int>q;
//                 for(int i=0;i<V;i++){
//                     if(inDegree[i]==0){
//                         q.push(i);
//                     }
//                 }
                
//                 vector<int>ans;
                
//                 while(!q.empty()){
//                     int currNode=q.front();
//                     q.pop();
//                     ans.push_back(currNode);
                    
//                     for(int i=0;i<adj[currNode].size();i++){
//                         int nextNode=adj[currNode][i];
//                         inDegree[nextNode]--;
//                         if(inDegree[nextNode]==0){
//                             q.push(nextNode);
//                         }
//                     }
                    
//                 }
                
//                 return ans;
            
//         }
//     };

//Detect a cycle using BFS(Kahn's Algorithm)

// class Solution {
//       public:
//         //Using BFS(Kahn's algorithm)
//         bool isCyclic(int V, vector<vector<int>> &edges) {
            
//             vector<int>inDegrees(V,0);
//             vector<vector<int>>adj(V);
            
//             int n=edges.size();
            
//             for(int i=0;i<n;i++){
//                 int u=edges[i][0];
//                 int v=edges[i][1];
                
//                 adj[u].push_back(v);
                
//                 inDegrees[v]++;
//             }
            
//             queue<int>q;
//             for(int i=0;i<V;i++){
//                 if(inDegrees[i]==0){
//                     q.push(i);
//                 }
//             }
            
//             vector<int>ans;
            
//             while(!q.empty()){
//                 int currNode=q.front();
//                 q.pop();
//                 ans.push_back(currNode);
                
//                 for(int i=0;i<adj[currNode].size();i++){
//                     int nextNode=adj[currNode][i];
                    
//                     inDegrees[nextNode]--;
//                     if(inDegrees[nextNode]==0){
//                         q.push(nextNode);
//                     }
//                 }
//             }
            
//             return ans.size()!=V;
            
//         }
//     };

//Course Schedule
// class Solution {
//       public:
//           bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//               vector<vector<int>>adj(numCourses);
//               vector<int>inDegree(numCourses,0);
//               for(int i=0;i<prerequisites.size();i++){
//                   int u=prerequisites[i][1];
//                   int v=prerequisites[i][0];
      
//                   inDegree[v]++;
//                   adj[u].push_back(v);
//               }
      
//               queue<int>q;
//               for(int i=0;i<numCourses;i++){
//                   if(inDegree[i]==0){
//                       q.push(i);
//                   }
//               }
      
//               vector<int>ans;
//               while(!q.empty()){
//                   int currNode=q.front();
//                   q.pop();
//                   ans.push_back(currNode);
      
//                   for(int i=0;i<adj[currNode].size();i++){
//                       int nextNode=adj[currNode][i];
      
//                       inDegree[nextNode]--;
//                       if(inDegree[nextNode]==0){
//                           q.push(nextNode);
//                       }
//                   }
//               }
      
//               return ans.size()==numCourses;
//           }
//       };

// Course Schedule II
// class Solution {
//       public:
//           vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//                       vector<vector<int>>adj(numCourses);
//               vector<int>inDegree(numCourses,0);
//               for(int i=0;i<prerequisites.size();i++){
//                   int u=prerequisites[i][1];
//                   int v=prerequisites[i][0];
      
//                   inDegree[v]++;
//                   adj[u].push_back(v);
//               }
      
//               queue<int>q;
//               for(int i=0;i<numCourses;i++){
//                   if(inDegree[i]==0){
//                       q.push(i);
//                   }
//               }
      
//               vector<int>ans;
//               while(!q.empty()){
//                   int currNode=q.front();
//                   q.pop();
//                   ans.push_back(currNode);
      
//                   for(int i=0;i<adj[currNode].size();i++){
//                       int nextNode=adj[currNode][i];
      
//                       inDegree[nextNode]--;
//                       if(inDegree[nextNode]==0){
//                           q.push(nextNode);
//                       }
//                   }
//               }
      
//               return ans.size()==numCourses?ans:vector<int>{};
//           }
//       };


// Find eventual safe states
// class Solution {
//       public:
//           vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//               int n=graph.size();
//               vector<vector<int>>adj(n);
//               vector<int>inDegree(n);
      
//              for(int i=0;i<n;i++){
//                   int v=i;
//                   for(int j=0;j<graph[i].size();j++){
//                       int u=graph[i][j];
//                       adj[u].push_back(v);
//                       inDegree[v]++;
//                   }
//              }
      
//              queue<int>q;
//              for(int i=0;i<n;i++){
//                   if(inDegree[i]==0){
//                       q.push(i);
//                   }
//              }
      
//              vector<int>ans;
      
//              while(!q.empty()){
//               int currNode=q.front();
//               q.pop();
//               ans.push_back(currNode);
      
//               for(int i=0;i<adj[currNode].size();i++){
//                   int nextNode=adj[currNode][i];
      
//                   inDegree[nextNode]--;
//                   if(inDegree[nextNode]==0){
//                       q.push(nextNode);
//                   }
//               }
//              }
//               sort(ans.begin(),ans.end());
//              return ans;
      
//           }
//       };

// Alien Dictionary
// class Solution {
//       public:
//           string findOrder(vector<string> &words) {
//               if (words.empty()) return "";
      
//               map<int, vector<int>> adj;
//               map<int, int> inDegree;
      
//               // Initialize adjacency list and inDegree for all unique characters
//               for (const auto &word : words) {
//                   for (char c : word) {
//                       int key = c - 'a';
//                       if (adj.find(key) == adj.end()) {
//                           adj[key] = vector<int>();
//                           inDegree[key] = 0;
//                       }
//                   }
//               }
      
//               // Build the adjacency list and inDegree
//               for (int i = 0; i < words.size() - 1; i++) {
//                   string str1 = words[i];
//                   string str2 = words[i + 1];
//                   int j = 0;
//                   while (j < str1.size() && j < str2.size()) {
//                       if (str1[j] != str2[j]) {
//                           adj[str1[j] - 'a'].push_back(str2[j] - 'a');
//                           inDegree[str2[j] - 'a']++;
//                           break;
//                       }
//                       j++;
//                   }
//                   // Check if str2 is a prefix of str1 (invalid order)
//                   if (j == str2.size() && str1.size() > str2.size()) {
//                       return "";
//                   }
//               }
      
//               // Kahn's algorithm
//               queue<int> q;
//               for (const auto &it : inDegree) {
//                   if (it.second == 0) {
//                       q.push(it.first);
//                   }
//               }
      
//               string ans;
//               while (!q.empty()) {
//                   int currNode = q.front();
//                   q.pop();
//                   ans.push_back(currNode + 'a');
      
//                   for (int neighbor : adj[currNode]) {
//                       inDegree[neighbor]--;
//                       if (inDegree[neighbor] == 0) {
//                           q.push(neighbor);
//                       }
//                   }
//               }
      
//               // If ans doesn't include all characters, there's a cycle
//               return ans.size() == adj.size() ? ans : "";
//           }
//       };