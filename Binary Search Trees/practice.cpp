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

//Validate Binary Search Tree
// class Solution {
// public:
//     bool getAns(TreeNode*root,long min,long max){
//         if(root==NULL){
//             return true;
//         }
//         if(root->val<=min || root->val>=max){
//             return false;
//         }
//         return getAns(root->left,min,root->val)&&getAns(root->right,root->val,max);
//     }
//     bool isValidBST(TreeNode* root) {
//         return getAns(root,LONG_MIN,LONG_MAX);
//     }
// };

//LCA in a binary search tree
// class Solution {
// public:
//     TreeNode*getAns(TreeNode*root,TreeNode*p,TreeNode*q){
//             if(root==NULL || root==p || root==q){
//                 return root;
//             }

//             if(p->val>root->val && q->val>root->val){
//                 return getAns(root->right,p,q);
//             }
//             else if(p->val<root->val && q->val<root->val){
//                 return getAns(root->left,p,q);
//             }
//             return root;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return getAns(root,p,q);
//     }
// };

//Construct a BST from preorder traversal
// class Solution {
// public:
//     TreeNode*getAns(int&index,vector<int>&preorder,long maxi){
//          if(index==preorder.size() || preorder[index]>maxi){
//             return NULL;
//          }

//          TreeNode*root=new TreeNode(preorder[index++]);

//          root->left=getAns(index,preorder,root->val);
//          root->right=getAns(index,preorder,maxi);

//          return root;



//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int index=0;
//          return getAns(index,preorder,LONG_MAX);
//     }
// };

// Inorder successor in BST
// class Solution {
// public:
//     int inorderSuccessor(TreeNode* root, int k) {
//         TreeNode*maxi=NULL;
//         while(root){

//             if(root->val>k){
//                 maxi=root;
//                 root=root->left;
//             }
//             else{
//                 root=root->right;
//             }
//         }
//         return maxi;
//     }
// };

//Binary Search Tree Iterator
// class BSTIterator {
// public:
//     stack<TreeNode*>stk;
//     BSTIterator(TreeNode* root) {
//         TreeNode*temp=root;
//         while(temp){
//             stk.push(temp);
//             temp=temp->left;
//         }
//     }
    
//     int next() {
//         TreeNode*temp=stk.top();
//         stk.pop();
//         if(temp->right){
//             TreeNode*temp1=temp->right;
//             while(temp1){
//                 stk.push(temp1);
//                 temp1=temp1->left;
//             }
//         }
//         return temp->val;
//     }
    
//     bool hasNext() {
//         return !stk.empty();
//     }
// };

//Two Sum- Brute Force Approach
// class Solution {
// public:
// void fillvector(TreeNode*root,vector<int>&v){
//     if(root==NULL){
//         return;
//     }
//     fillvector(root->left,v);
//     v.push_back(root->val);
//     fillvector(root->right,v);
// }
// void getans(vector<int>&v,bool&ans,int k){
//     int i=0;
//     int j=v.size()-1;
//     while(i<j){
//         if(v[i]+v[j]<k){
//             i++;
//         }
//         else if(v[i]+v[j]>k){
//             j--;
//         }
//         else{
//             ans=true;
//             return;
//         }
//     }
// }
//     bool findTarget(TreeNode* root, int k) {
//     vector<int>v;
//     fillvector(root,v); 
//     bool ans=false;
//     getans(v,ans,k);
//     return ans;   
//     }
// };

//Recover binary search tree
// class Solution {
// public:
//     TreeNode*first,*firstNext,*second;
//     void getAns(TreeNode*root,TreeNode*&prev){
//         if(root==NULL){
//             return;
//         }
//         getAns(root->left,prev);
//        if(prev!=NULL){
//        if(root->val<prev->val){
//             if(first==NULL){
//                 first=prev;
//                 firstNext=root;
//             }
//             else{
//                 second=root;
//             }
//        }
//        }
//        prev=root;
//         getAns(root->right,prev);
//     }
//     void recoverTree(TreeNode* root) {
//         first=NULL;
//         firstNext=NULL;
//         second=NULL;
//         TreeNode*prev=NULL;
//         getAns(root,prev);
//                 int temp=first->val;
//         if(second==NULL){
//             first->val=firstNext->val;
//             firstNext->val=temp;
//         }
//         else{
//             first->val=second->val;
//             second->val=temp;
//         }
//     }
// };

//Largest BST in Binary Search Tree
// class Solution{
//     public:
//     pair<int,pair<int,int>>getAns(Node*root){
         
//          if(root==NULL){
//              return {0,{INT_MIN,INT_MAX}};
//          }
         
//          pair<int,pair<int,int>>left=getAns(root->left);
//          pair<int,pair<int,int>>right=getAns(root->right);
         
//          if(root->data>left.second.first && root->data<right.second.second){
//               return { left.first+right.first+1, { max(root->data,right.second.first), min(root->data,left.second.second)}};
//          }
//          else{
//              return {max(left.first,right.first),{INT_MAX,INT_MIN}};
//          }
//     }

//     int largestBst(Node *root)
//     {
//     	pair<int,pair<int,int>>p=getAns(root);
//     	return p.first;
//     }
// };