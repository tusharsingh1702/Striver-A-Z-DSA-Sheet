//Introduction
// class Solution {
//   public:
//     Node* constructLL(vector<int>& arr) {
//         Node*head=new Node(arr[0]);
//         Node*temp=head;
//         for(int i=1;i<arr.size();i++){
//             Node*newNode=new Node(arr[i]);
//             temp->next=newNode;
//             temp=newNode;
//         }
//         return head;
//     }
// };

//Inserting a node in the linked list: beginning and end
// class Solution{
//   public:
//     //Function to insert a node at the beginning of the linked list.
//     Node *insertAtBegining(Node *head, int x) {
//         if(!head){
//             return new Node(x);
//         }
//        Node*temp=new Node(x);
//        temp->next=head;
//        head=temp;
//        return head;
//     }
    
    
//     //Function to insert a node at the end of the linked list.
//     Node *insertAtEnd(Node *head, int x)  {
//         if(!head){
//             return new Node(x);
//         }
//     Node*temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     Node*newNode=new Node(x);
//     temp->next=newNode;
//     newNode->next=NULL;
//     return head;
//     }
// };

//Delete node in a linked list
// class Solution {
// public:
//     void deleteNode(ListNode* node) {

//         ListNode*curr=node,*forw=NULL,*prev=NULL;
//         while(curr->next!=NULL){
//             forw=curr->next;
//             curr->val=forw->val;
//             prev=curr;
//             curr=forw;
//         }
//         prev->next=NULL;
//         delete curr;
//     }
// };

//Find length of linked list
// class Solution
// {
//     public:
//     int getCount(struct Node* head){
//     int count=0;
//     Node*temp=head;
//     while(temp){
//         count++;
//         temp=temp->next;
//     }
//     return count;
//     }
// };

//Search in a linked list
// class Solution {
//   public:
//     // Function to count nodes of a linked list.
//     bool searchKey(int n, struct Node* head, int key) {
//         Node*temp=head;
//         while(temp){
//             if(temp->data==key){
//                 return true;
//             }
//             temp=temp->next;
//         }
//         return false;
//     }
// };
