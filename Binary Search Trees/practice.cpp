//Ceil in a binary search tree
// int findCeil(Node* root, int input) {
//     if (root == NULL) return -1;
//     int ceil=INT_MAX;
//     Node*curr=root;
//     while(curr){
//         if(curr->data==input){
//             return curr->data;
//         }
//         if(curr->data>input && curr->data<ceil){
//             ceil=curr->data;
//         }
//         if(curr->data>input){
//             curr=curr->left;
//         }
//         else{
//             curr=curr->right;
//         }
//     }
//      return ceil==INT_MAX?-1:ceil;
// }

// Floor in a binary search tree
// class Solution{
// public:
//     int floor(Node* root, int x) {
//         int floor=-1;
//         Node*curr=root;
//         while(curr){
//             if(curr->data==x){
//                 return curr->data;
//             }
//             if(curr->data>floor && curr->data<x){
//                 floor=curr->data;
//             }
//             if(curr->data>x){
//                 curr=curr->left;
//             }
//             else{
//                 curr=curr->right;
//             }
//         }
//         return floor;
//     }
// };

//Insert into a binary search tree
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//      if(root==NULL){
//         return new TreeNode(val);;
//      }
//      TreeNode*curr=root;
//      while(curr){
//         if(curr->val>val){
//             if(curr->left==NULL){
//                 curr->left=new TreeNode(val);
//                 break;
//             }
//             else{
//                 curr=curr->left;
//             }
//         }
//         else{
//             if(curr->right==NULL){
//                     curr->right=new TreeNode(val);
//                     break;
//             }
//             else{
//                 curr=curr->right;
//             }
//         }
//      }
//      return root;
//     }
// };

//Delete node in a bst
// class Solution {
// public:
// TreeNode*helper(TreeNode*root){
//     if(root->left==NULL){
//         return root->right;
//     }
//     else if(root->right==NULL){
//         return root->left;
//     }
//     else{
//         TreeNode*rootRight=root->right;
//         TreeNode*rootLeft=root->left;
//         while(rootLeft->right){
//             rootLeft=rootLeft->right;
//         }
//         rootLeft->right=rootRight;
//         return root->left;
//     }
// }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//             if(root==NULL){
//                 return root;
//             }
//             TreeNode*curr=root;
            
//             if(root->val==key){
//                 return helper(root);
//             }
//         while(curr){
           
//            if(curr->val>key){

//                 if(curr->left && curr->left->val==key){
//                         curr->left=helper(curr->left);
//                         break;
//                 }
//                 else{
//                     curr=curr->left;
//                 }
//            }
//            else{

//                 if(curr->right && curr->right->val==key){
//                         curr->right=helper(curr->right);
//                         break;
//                 }
//                 else{
//                     curr=curr->right;
//                 }
//            }
//         }
//         return root;
//     }
// };

//Find kth smallest element in a binary search tree
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//           int kk=k;
//             TreeNode*curr=root;
//             vector<int>ans;
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
//             return ans[k-1];
//     }
// }