// root to leaf node path
// class Solution {
//   public:
    
//     void getPath(Node*root,vector<int>path,vector<vector<int>>&ans){
//         if(root==NULL){
//             return;
//         }
//         path.push_back(root->data);
//         getPath(root->left,path,ans);
//         getPath(root->right,path,ans);
//         if(root->left==NULL && root->right==NULL){
//             ans.push_back(path);
//         }
        
//     }
//     vector<vector<int>> Paths(Node* root) {
//             vector<int>path;
//             vector<vector<int>>ans;
//             getPath(root,path,ans);
//             return ans;
//     }
// };

//Lowest Common Ancestor
// class Solution {
// public:
//     TreeNode*getAns(TreeNode*root,TreeNode*p,TreeNode*q){
//         if(root==NULL || root==p || root==q){
//             return root;
//         }
//         TreeNode*left=getAns(root->left,p,q);
//         TreeNode*right=getAns(root->right,p,q);

//         if(!left){
//             return right;
//         }
//         else if(!right){
//             return left;
//         }
//         else{
//             return root;
//         }
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return getAns(root,p,q);
//     }
// };


//Maximum width of a binary tree
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if (!root) return 0;

//         queue<pair<TreeNode*, unsigned long long int>> q;
//         unsigned long long int maxWidth = 0;
//         q.push({root, 0});

//         while (!q.empty()) {
//             int size = q.size();
//             unsigned long long int firstIndex = q.front().second;
//             unsigned long long int lastIndex = q.back().second;

//             maxWidth = max(maxWidth, lastIndex - firstIndex + 1);

//             for (int i = 0; i < size; i++) {
//                 pair<TreeNode*, unsigned long long int> p = q.front();
//                 q.pop();

//                 unsigned long long int currentIndex = p.second - firstIndex;

//                 if (p.first->left) {
//                     q.push({p.first->left, 2 * currentIndex + 1});
//                 }

//                 if (p.first->right) {
//                     q.push({p.first->right, 2 * currentIndex + 2});
//                 }
//             }
//         }
//         return maxWidth;
//     }
// };

//Check for children sum property
// class Solution{
//     public:
//     int checkSum(Node*root){
//         if(root==NULL){
//             return 0;
//         }
//         if(root->left==NULL && root->right==NULL){
//             return root->data;
//         }
//         int left=checkSum(root->left);
//         int right=checkSum(root->right);
//         if(left==1e6 || right==1e6){
//             return 1e6;
//         }
//         if(left+right==root->data){
//             return root->data;
//         }
//         else{
//             return 1e6;
//         }
//     }
//     int isSumProperty(Node *root)
//     {
//        int ans=checkSum(root);
//        return ans==1e6?0:1;
     
//     }
// };

//All nodes distance k in binary tree (recursive solution not the most optimal)
// class Solution {
// public:
//     void getParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&childParent){
//         if(root==NULL){
//             return;
//         }
//         if(root->left){
//             childParent[root->left]=root;
//         }
//         if(root->right){
//             childParent[root->right]=root;
//         }
//         getParent(root->left,childParent);
//         getParent(root->right,childParent);
//     }

//     void getAns(TreeNode*root,TreeNode*target,unordered_map<TreeNode*,TreeNode*>childParent,vector<int>&ans,int k,unordered_map<TreeNode*,bool>visited){

//         if(root==NULL){
//             return;
//         }
//         if(k==0){
//             ans.push_back(root->val);
//             return;
//         }
//         visited[root]=true;
//         if(childParent[root] && visited.find(childParent[root])==visited.end()){
//             getAns(childParent[root],target,childParent,ans,k-1,visited);
//         }
//         if(root->left && visited.find(root->left)==visited.end()){
//             getAns(root->left,target,childParent,ans,k-1,visited);
//         }

//          if(root->right && visited.find(root->right)==visited.end()){
//             getAns(root->right,target,childParent,ans,k-1,visited);
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         unordered_map<TreeNode*,TreeNode*>childParent;
//         getParent(root,childParent);
//         vector<int>ans;
//         unordered_map<TreeNode*,bool>visited;
//         getAns(target,target,childParent,ans,k,visited);
//         return ans;
//     }
// };

//Minimum time taken to burn a binary tree
// class Solution {
//   public:
//     void getParent(Node*root,unordered_map<Node*,Node*>&childParent,Node*&src,int target){
//         if(root==NULL){
//             return;
//         }
//         if(root->data==target){
//             src=root;
//         }
//         if(root->left){
//             childParent[root->left]=root;
//         }
//         if(root->right){
//             childParent[root->right]=root;
//         }
//         getParent(root->left,childParent,src,target);
//         getParent(root->right,childParent,src,target);
//     }
//     int minTime(Node* root, int target) 
//     {
//         unordered_map<Node*,Node*>childParent;
//         Node*src=NULL;
//         getParent(root,childParent,src,target);
//         int time=0;
//         queue<Node*>q;
//         q.push(src);
//         unordered_set<Node*>visited;
//         visited.insert(src);
//         while(!q.empty()){
             
//              int size=q.size();
             
//              for(int i=0;i<size;i++){
//                  Node*temp=q.front();
//                  q.pop();
                 
//                  if(temp->left && visited.find(temp->left)==visited.end()){
//                      q.push(temp->left);
//                      visited.insert(temp->left);
//                  }
                 
//                  if(temp->right && visited.find(temp->right)==visited.end()){
//                      q.push(temp->right);
//                      visited.insert(temp->right);
//                  }
                 
//                  if(childParent[temp] && visited.find(childParent[temp])==visited.end()){
//                      q.push(childParent[temp]);
//                      visited.insert(childParent[temp]);
//                  }
//              }
//            time++;
//         }
//         return time-1;
        
//     }
// };

//Find total nodes in a complete binary tree
// class Solution {
// public:
//     int count(TreeNode*root){
//         if(root==NULL){
//             return 0;
//         }
//         int lh=0,rh=0;
//         TreeNode*temp=root;
//         while(temp!=NULL){
//             lh++;
//             temp=temp->left;
//         }
//         temp=root;
//         while(temp!=NULL){
//             rh++;
//             temp=temp->right;
//         }
//         if(lh==rh){
//             return (pow(2,lh)-1);
//         }
//         return 1+count(root->left)+count(root->right);
//     }
//     int countNodes(TreeNode* root) {
//         return count(root);
//     }
// };

//Unique Binary Tree Requirements
// class Solution
// {
// public:
//     bool isPossible(int a,int b)
//     {
//         if((a!=2 && b!=2) || (a==2 && b==2)){
//             return false;
//         }
        
//         return true;
//     }
// };

//Construct binary tree from inorder and preorder traversal
// class Solution {
// public:

//     TreeNode*buildTree(int&preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,vector<int>&inorder,unordered_map<int,int>&inIndex){
//             if(preStart>preEnd || inStart>inEnd){
//                 return NULL;
//             }

//             TreeNode*root=new TreeNode(preorder[preStart++]);
//             int index=inIndex[root->val];

//             root->left=buildTree(preStart,preEnd,preorder,inStart,index-1,inorder,inIndex);
//             root->right=buildTree(preStart,preEnd,preorder,index+1,inEnd,inorder,inIndex);
//             return root;
    
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int,int>inIndex;
//         for(int i=0;i<inorder.size();i++){
//             inIndex[inorder[i]]=i;
//         }
//         int preIndex=0;
//         return buildTree(preIndex,preorder.size()-1,preorder,0,inorder.size()-1,inorder,inIndex);
//     }
// };

//Construct a binary tree from inorder and postorder traversal
// class Solution {
// public:
//     TreeNode*buildT(int&postStart,vector<int>&postorder,int inStart,int inEnd,int n,vector<int>inorder,unordered_map<int,int>&inIndex){
//          if(postStart<0 || inStart>inEnd){
//             return NULL;
//          }

//          TreeNode*root=new TreeNode(postorder[postStart--]);
//          int index=inIndex[root->val];

//          root->right=buildT(postStart,postorder,index+1,inEnd,n,inorder,inIndex);
//          root->left=buildT(postStart,postorder,inStart,index-1,n,inorder,inIndex);

//          return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         unordered_map<int,int>inIndex;
//         for(int i=0;i<inorder.size();i++){
//             inIndex[inorder[i]]=i;
//         }
//         int n=postorder.size(),postStart=n-1;
//         return buildT(postStart,postorder,0,n-1,n,inorder,inIndex);
//     }
// };

//Serialize and Deserialize binary tree
// class Solution {
// public:
//     TreeNode*buildT(int&postStart,vector<int>&postorder,int inStart,int inEnd,int n,vector<int>inorder,unordered_map<int,int>&inIndex){
//          if(postStart<0 || inStart>inEnd){
//             return NULL;
//          }

//          TreeNode*root=new TreeNode(postorder[postStart--]);
//          int index=inIndex[root->val];

//          root->right=buildT(postStart,postorder,index+1,inEnd,n,inorder,inIndex);
//          root->left=buildT(postStart,postorder,inStart,index-1,n,inorder,inIndex);

//          return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         unordered_map<int,int>inIndex;
//         for(int i=0;i<inorder.size();i++){
//             inIndex[inorder[i]]=i;
//         }
//         int n=postorder.size(),postStart=n-1;
//         return buildT(postStart,postorder,0,n-1,n,inorder,inIndex);
//     }
// };

//Morris Traversal Inorder
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root==NULL){
//             return {};
//         }
//         vector<int>ans;
//         TreeNode*curr=root;
//         while(curr){
//             if(!curr->left){
//                 ans.push_back(curr->val);
//                 curr=curr->right;
//             }
//             else{
//                 TreeNode*temp=curr->left;
//                 while(temp->right && temp->right!=curr){
//                     temp=temp->right;
//                 }

//                 if(temp->right==NULL){
//                     temp->right=curr;
//                     curr=curr->left;
//                 }
//                 else{
//                     temp->right=NULL;
//                     ans.push_back(curr->val);
//                     curr=curr->right;
//                 }

//             }
//         }
//         return ans;
//     }
// };

// Preorder Morris Traversal
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(!root){
//             return {};
//         }
//         TreeNode*curr=root;
//         vector<int>ans;
//         while(curr){
//             if(!curr->left){
//                 ans.push_back(curr->val);
//                 curr=curr->right;
//             }
//             else{
              
//                 TreeNode*temp=curr->left;
//                 while(temp->right && temp->right!=curr){
//                     temp=temp->right;
//                 }
//                 if(temp->right==NULL){
//                     temp->right=curr;
//                     ans.push_back(curr->val);
//                     curr=curr->left;
//                 }
//                 else{
//                     temp->right=NULL;
//                     curr=curr->right;
//                 }
//             }
//         }
//         return ans;
//     };

// Flatten a binary tree to a linked list using Morris Traversal
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(!root){
//             return;
//         }
//         TreeNode*curr=root;
//         while(curr){
//             if(curr->left){
//                 TreeNode*temp=curr->left;
//                 while(temp->right){
//                     temp=temp->right;
//                 }
//                 temp->right=curr->right;
//                 curr->right=curr->left;
//                 curr->left=NULL;
//             }
//             curr=curr->right;
//         }
//     }
// };