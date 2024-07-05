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