//introduction
// class Solution {
//   public:
//     bool isBSTTraversal(vector<int>& arr) {
//         for(int i=1;i<arr.size();i++){
//             if(arr[i]<=arr[i-1]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

//Search in a binary search tree
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(root==NULL || root->val==val){
//             return root;
//         }
//         TreeNode*curr=root;
//         while(curr){
//             if(curr->val==val){
//                 return curr;
//             }
//             if(curr->val>val){
//                 curr=curr->left;
//             }
//             else{
//                 curr=curr->right;
//             }
//         }
//         return NULL;
//     }
// };

//Minimum in a BST
// class Solution {
//   public:
//     int minValue(Node* root) {
//         if(!root){
//             return -1;
//         }
//         Node*temp=root;
//         while(temp->left){
//             temp=temp->left;
//         }
//         return temp->data;
//     }
// };