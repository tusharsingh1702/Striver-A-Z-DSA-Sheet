//Middle of the linked list
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode*slow=head,*fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
// };

//Reverse a linked list (iteratively)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode*prev=NULL,*curr=head,*forw=NULL;
//         while(curr){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }
// };

// Reverse a linked list recursively
// class Solution {
// public:
//     ListNode*getReversed(ListNode*head){
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         ListNode*newHead=getReversed(head->next);
//         ListNode*front=head->next;
//         front->next=head;
//         head->next=NULL;
//         return newHead;
//     }
//     ListNode* reverseList(ListNode* head) {
//         return getReversed(head);
//     }
// };

//Detect a loop in a linked list
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode*slow=head,*fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//Find starting point of loop
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode*slow=head,*fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast){
//                 break;
//             }
//         }
//         if(!fast || !fast->next){
//             return NULL;
//         }
//         slow=head;
//         while(slow!=fast){
//             slow=slow->next;
//             fast=fast->next;
//         }
//         return slow;
//     }
// };

//Find length of loop
// int countNodesinLoop(struct Node *head)
// {
//     Node*slow=head,*fast=head;
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//         if(slow==fast){
//             break;
//         }
//     }
//     if(!fast || !fast->next){
//         return 0;
//     }
//     slow=head;
//     while(slow!=fast){
//         slow=slow->next;
//         fast=fast->next;
//     }
//     int count=1;
//     slow=slow->next;
//     while(slow!=fast){
//         count++;
//         slow=slow->next;
//     }
//     return count;
// }

//Check if LL is sorted or not.
// class Solution {
// public:
//     ListNode*reverseLL(ListNode*head){
//         ListNode*curr=head,*prev=NULL,*forw=NULL;
//         while(curr){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(!head || !head->next){
//             return true;
//         }
//         ListNode*slow=head,*fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         ListNode*newHead=reverseLL(slow);
//         while(head && newHead){
//             if(head->val!=newHead->val){
//                 return false;
//             }
//             head=head->next;
//             newHead=newHead->next;
//         }
//         return true;
//     }
// };

//Segregate odd and even nodes in LL
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(head==NULL || head->next==NULL || head->next->next==NULL){
//             return head;
//         }
//         ListNode*temp1=head,*temp2=head->next,*head2=head->next;
//         while(temp1->next && temp2->next){
//             temp1->next=temp2->next;
//             temp1=temp1->next;
//             temp2->next=temp1->next;
//             temp2=temp2->next;
//         }
//         if(temp1){
//             temp1->next=head2;
//             return head;
//         }
//         else{
//             temp1=head;
//             while(temp1->next!=NULL){
//                 temp1=temp1->next;
//             }
//             temp1->next=head2;
//             return head;
//         }
//     }
// };

//Remove nth node from the back of the ll
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head==NULL || (head->next==NULL && n==1)){
//             return NULL;
//         }
//         ListNode*slow=head,*fast=head;
//         for(int i=0;i<n;i++){
//             fast=fast->next;
//         }
//         if(!fast){
//             return head->next;
//         }
//         while(fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next;
//         }
//         ListNode*toDelete=slow->next;
//         slow->next=toDelete->next;
//         toDelete->next=NULL;
//         delete toDelete;
//         return head;
//     }
// };

//Delete the middle of the linked list
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return NULL;
//         }
//         ListNode*slow=head,*fast=head,*prev=NULL;
//         while(fast && fast->next){
//             prev=slow;
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         prev->next=slow->next;
//         delete slow;
//         return head;
//     }
// };