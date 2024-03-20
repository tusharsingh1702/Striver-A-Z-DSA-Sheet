//Introduction to Trees
// int numberOfNodes(int N){
//     // Write your code here
//     return pow(2,N-1);
// }

//Binary Tree representation in c++
// Node* createTree(vector<int>&arr){
//     Node*head=new Node(arr[0]);
//     head->left=new Node(arr[1]);
//     head->right=new Node(arr[2]);
//     head->left->left=new Node(arr[3]);
//     head->left->right=new Node(arr[4]);
//     head->right->left=new Node(arr[5]);
//     head->right->right=new Node(arr[6]);
//     return head;
// }

//Tree Traversals
// vector<vector<int>> getTreeTraversal(TreeNode *root){
// vector<int>preOrder,inOrder,postOrder;
// stack<pair<TreeNode*,int>>s;
// s.push({root,1});
// while(!s.empty()){
//     pair<TreeNode*,int>p=s.top();
//     int num=p.second;
//     s.pop();
//     if(num==1){
//         preOrder.push_back(p.first->data);
//         p.second++;
//         s.push(p);
//         if(p.first->left){
//             s.push({p.first->left,1});
//         }
//     }
//     if(num==2){
//         inOrder.push_back(p.first->data);
//         p.second++;
//         s.push(p);
//         if(p.first->right){
//             s.push({p.first->right,1});
//         }
//     }
//     if(num==3){
//         postOrder.push_back(p.first->data);
//     }
// }
// vector<vector<int>>ans;
// ans.push_back(inOrder);
// ans.push_back(preOrder);
// ans.push_back(postOrder);
// return ans;


// }

//Preorder Traversal (Recursive)
// class Solution {
// public:
// void answer(TreeNode*root,vector<int>&v){
//     if(root==NULL){
//         return;
//     }
//     v.push_back(root->val);
//     if(root->left){
//         answer(root->left,v);
//     }
//     if(root->right){
//         answer(root->right,v);
//     }
// }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>v;
//         answer(root,v);
//         return v;
//     }
// };

//Inorder traversal (Recursive)
// class Solution {
// public:
//     void getInorder(TreeNode*root,vector<int>&ans){
//         if(root==NULL)return;
//         getInorder(root->left,ans);
//         ans.push_back(root->val);
//         getInorder(root->right,ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         getInorder(root,ans);
//         return ans;
//     }
// };

//Postorder Traversal (Recursive)
// class Solution {
// public:
// void answer(TreeNode*root,vector<int>&v){
//     if(root==NULL){
//         return;
//     }
//         answer(root->left,v);
//         answer(root->right,v);
//     v.push_back(root->val);
// }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>v;
//         answer(root,v);
//         return v;
//     }
// };

//Level Order Traversal
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         if(root==NULL){
//             return ans;
//         }
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//              int size=q.size();
//              vector<int>v;
//              for(int i=0;i<size;i++){
//                 TreeNode*temp=q.front();
//                 q.pop();
//                 v.push_back(temp->val);
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//              }
//              ans.push_back(v);
//         }
//         return ans;
//     }
// };

//Iterative Preorder Traversal
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         if(root==NULL){
//             return ans;
//         }
//         stack<TreeNode*>s;
//         s.push(root);
//         while(!s.empty()){
//             int size=s.size();
//             for(int i=0;i<size;i++){
//                 TreeNode*temp=s.top();
//                 s.pop();
//                 ans.push_back(temp->val);
//                 if(temp->right){
//                     s.push(temp->right);
//                 }
//                 if(temp->left){
//                     s.push(temp->left);
//                 }
//             }
//         }
//         return ans;
//     }
// };

//Iterative inorder traversal
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         if(!root)return ans;
//         stack<TreeNode*>s;
//         while(true){
//             if(root){
//                 s.push(root);
//                 root=root->left;
//             }
//             else{
//                 if(s.empty())break;
//                 root=s.top();
//                 s.pop();
//                 ans.push_back(root->val);
//                     root=root->right;
//             }
//         }
//         return ans;
//     }
// };

//Preorder, Inorder and Postorder in one traversal
// vector<vector<int>> getTreeTraversal(TreeNode *root){
// vector<int>preOrder,inOrder,postOrder;
// stack<pair<TreeNode*,int>>s;
// s.push({root,1});
// while(!s.empty()){
//     pair<TreeNode*,int>p=s.top();
//     int num=p.second;
//     s.pop();
//     if(num==1){
//         preOrder.push_back(p.first->data);
//         p.second++;
//         s.push(p);
//         if(p.first->left){
//             s.push({p.first->left,1});
//         }
//     }
//     if(num==2){
//         inOrder.push_back(p.first->data);
//         p.second++;
//         s.push(p);
//         if(p.first->right){
//             s.push({p.first->right,1});
//         }
//     }
//     if(num==3){
//         postOrder.push_back(p.first->data);
//     }
// }
// vector<vector<int>>ans;
// ans.push_back(inOrder);
// ans.push_back(preOrder);
// ans.push_back(postOrder);
// return ans;
// }