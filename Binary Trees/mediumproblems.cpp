//height of a binary tree
// class Solution {
// public:
//     int getHeight(TreeNode*root){
//         if(root==NULL){
//             return 0;
//         }
//         int left=getHeight(root->left);
//         int right=getHeight(root->right);
//         return max(left,right)+1;
//     }
//     int maxDepth(TreeNode* root) {
//         return getHeight(root);
//     }
// };

//balanced tree or not
// class Solution {
// public:
//     pair<bool,int> balanced(TreeNode*root){
//         if(root==NULL){
//             return {true,0};
//         }
//         pair<bool,int>left=balanced(root->left);
//         pair<bool,int>right=balanced(root->right);
//         if(!left.first || !right.first){
//             return {false,0};
//         }
//         return {abs(left.second-right.second)<=1,max(left.second,right.second)+1};

//     }
//     bool isBalanced(TreeNode* root) {
//         return balanced(root).first;
//     }
// };

//Diameter of a binary tree
// class Solution {
// public:
// int dia;
//     int getAns(TreeNode*root){
//         if(root==NULL){
//             return 0;
//         }
//         int left=getAns(root->left);
//         int right=getAns(root->right);
//         dia=max(dia,left+right);
//         return max(left,right)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         dia=0;
//         getAns(root);
//         return dia;
//     }
// };

//Maximum path sum
// class Solution {
// public:
//     int pathSum;
//     int getAns(TreeNode*root){
//         if(root==NULL){
//             return 0;
//         }
//         int left=max(0,getAns(root->left));
//         int right=max(0,getAns(root->right));
//         pathSum=max(pathSum,left+right+root->val);
//         return max(left,right)+root->val;
//     }
//     int maxPathSum(TreeNode* root) {
//         pathSum=INT_MIN;
//         getAns(root);
//         return pathSum;
//     }
// };

//Same Tree
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(!p && !q){
//             return true;
//         }
//         if(p && !q){
//             return false;
//         }
//         if(!p &&q){
//             return false;
//         }
//         if(p->val!=q->val){
//             return false;
//         }
//         bool left=isSameTree(p->left,q->left);
//         bool right=isSameTree(p->right,q->right);
//         return left&&right;
//     }
// };

//Zig Zag Traversal of Binary Tree
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if(root==NULL){
//             return {};
//         }
//         vector<vector<int>>ans;
//         int level=1;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//           int size=q.size();
//             vector<int>v;
//             for(int i=0;i<size;i++){
//                 TreeNode*temp=q.front();
//                 v.push_back(temp->val);
//                 q.pop();
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//             }
//             if(level%2==0){
//                 reverse(v.begin(),v.end());
//             }
//             ans.push_back(v);
//             level++;
//         }
//         return ans;
//     }
// };

//Vertical order traversal of binary tree
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         queue<pair<TreeNode*,pair<int,int>>>q;
//         map<int,map<int,multiset<int>>>mp;
//         q.push({root,{0,0}});
//         while(!q.empty()){
//             int size=q.size();

//             for(int i=0;i<size;i++){
//                 pair<TreeNode*,pair<int,int>>p=q.front();
//                 q.pop();
//                 mp[p.second.first][p.second.second].insert(p.first->val);
//                 if(p.first->left){
//                     q.push({p.first->left,{p.second.first-1,p.second.second+1}});
//                 }

//                 if(p.first->right){
//                     q.push({p.first->right,{p.second.first+1,p.second.second+1}});
//                 }
//             }
//         }
//         vector<vector<int>>ans;
//         for(auto it:mp){
//             vector<int>v;
//             map<int,multiset<int>>mpp=it.second;
//             for(auto itt:mpp){
//                 for(auto iter:itt.second){
//                     v.push_back(iter);
//                 }
//             }
//             ans.push_back(v);
//         }
//         return ans;
//     }
// };

//Top view of a binary tree
// class Solution
// {
//     public:
//     vector<int> topView(Node *root)
//     {
//         map<int,int>verticalnode;
//         //storing the vertical and the value of the node at that level
//         queue<pair<Node*,int>>q;
//         //storing the root and the vertical
//         q.push({root,0});
//         while(!q.empty()){
//             int size=q.size();
            
//             for(int i=0;i<size;i++){
//                 pair<Node*,int>p=q.front();
//                 q.pop();
//                 if(verticalnode.find(p.second)==verticalnode.end()){
//                     verticalnode[p.second]=p.first->data;
//                 }
//                 if(p.first->left){
//                     q.push({p.first->left,p.second-1});
//                 }
//                 if(p.first->right){
//                     q.push({p.first->right,p.second+1});
//                 }
//             }
//         }
//         vector<int>ans;
//         for(auto it:verticalnode){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }

// };

//Bottom view of binary tree
// class Solution {
//   public:
//     vector <int> bottomView(Node *root) {
// map<int,int>verticalnode;
//         //storing the vertical and the value of the node at that level
//         queue<pair<Node*,int>>q;
//         //storing the root and the vertical
//         q.push({root,0});
//         while(!q.empty()){
//             int size=q.size();
            
//             for(int i=0;i<size;i++){
//                 pair<Node*,int>p=q.front();
//                 q.pop();
//                     verticalnode[p.second]=p.first->data;
//                 if(p.first->left){
//                     q.push({p.first->left,p.second-1});
//                 }
//                 if(p.first->right){
//                     q.push({p.first->right,p.second+1});
//                 }
//             }
//         }
//         vector<int>ans;
//         for(auto it:verticalnode){
//             ans.push_back(it.second);
//         }
//         return ans;    }
// };

//Binary Tree Right Side View
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(root==NULL){
//             return {};
//         }
//         map<int,int>levelnode;
//         queue<pair<TreeNode*,int>>q;
//         q.push({root,0});
//         while(!q.empty()){
//             int size=q.size();

//             for(int i=0;i<size;i++){
//                 pair<TreeNode*,int>temp=q.front();
//                 q.pop();

//                if(levelnode.find(temp.second)==levelnode.end()){
//                   levelnode[temp.second]=temp.first->val;
//                }
//                 if(temp.first->right){
//                     q.push({temp.first->right,temp.second+1});
//                 }
//                  if(temp.first->left){
//                     q.push({temp.first->left,temp.second+1});
//                 }
//             }
//         }
//         vector<int>ans;
//         for(auto it:levelnode){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };

//Symmetric binary tree
// class Solution {
// public:
//     bool getAns(TreeNode*root1,TreeNode*root2){
//         if(!root1 && !root2){
//             return true;
//         }
//         if(root1 && !root2){
//             return false;
//         }
//         if(!root1 && root2){
//             return false;
//         }
//         if(root1->val!=root2->val){
//             return false;
//         }
//         bool first=getAns(root1->left,root2->right);
//         bool second=getAns(root1->right,root2->left);
//         return first&&second;
//     }
//     bool isSymmetric(TreeNode* root) {
//         return getAns(root->left,root->right);
//     }
// };