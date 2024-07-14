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

//Sort a linked list
// class Solution {
// public:
//     ListNode*getMiddle(ListNode*head){
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         ListNode*slow=head,*fast=head->next;
//         while(fast!=NULL && fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
//     ListNode*mergeLL(ListNode*left,ListNode*right){
//         ListNode*dummyNode=new ListNode(-1);
//         ListNode*temp=dummyNode;
//         while(left!=NULL && right!=NULL){
//             if(left->val<=right->val){
//                 temp->next=left;
//                 left=left->next;
//             }
//             else{
//                 temp->next=right;
//                 right=right->next;
//             }
//             temp=temp->next;
//         }
//         while(left){
//            temp->next=left;
//            left=left->next;
//            temp=temp->next;
//         }
//         while(right){
//             temp->next=right;
//             right=right->next;
//             temp=temp->next;
//         }
//         return dummyNode->next;
//     }
//     ListNode* sortList(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             //List is already sorted.
//             return head;
//         }
//         ListNode*middle=getMiddle(head);
//         ListNode*right=middle->next;
//         middle->next=NULL;
//         ListNode*left=head;
//         left=sortList(left);
//         right=sortList(right);
//         return mergeLL(left,right);
//     }
// };

//Sort a LL having only 0's, 1's and 2's
// class Solution
// {
//     public:
//     //Function to sort a linked list of 0s, 1s and 2s.
//     Node* segregate(Node *head) {
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         Node*dummyZero=new Node(-1);
//         Node*dummyOne=new Node(-1);
//         Node*dummyTwo=new Node(-1);
//         Node*zero=dummyZero,*one=dummyOne,*two=dummyTwo;
//         Node*temp=head;
//         while(temp!=NULL){
//             if(temp->data==0){
//                 zero->next=temp;
//                 zero=zero->next;
//             }
//             else if(temp->data==1){
//                 one->next=temp;
//                 one=one->next;
//             }
//             else{
//                 two->next=temp;
//                 two=two->next;
//             }
//             temp=temp->next;
//         }
//         zero->next = dummyOne->next ? dummyOne->next : dummyTwo->next;
//         one->next = dummyTwo->next;
//         two->next = nullptr;

//         return dummyZero->next ? dummyZero->next : (dummyOne->next ? dummyOne->next : dummyTwo->next);
        
//     }
// };

//Find intersection point of a Y linked list.
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(!headA || !headB){
//             return NULL;
//         }
//         unordered_set<ListNode*>set;
//         while(headA){
//             set.insert(headA);
//             headA=headA->next;
//         }
//         while(headB){
//             if(set.find(headB)!=set.end()){
//                 return headB;
//             }
//             headB=headB->next;
//         }
//         return NULL;
//     }
// };

//Add 1 to a number represented by linked list.
// class Solution
// {
//     public:
//     Node*getReversed(Node*head){
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         Node*curr=head,*prev=NULL,*forw=NULL;
//         while(curr){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }
//     Node* addOne(Node *head) 
//     {
//         Node*newHead=getReversed(head);
//         int carry=1;
//         Node*temp=newHead,*prev=NULL;;
//         while(temp && carry){
//             if(temp->data==9){
//                 temp->data=0;
//                 carry=1;
//             }
//             else{
//                 temp->data=temp->data+1;
//                 carry=0;
//             }
//             prev=temp;
//             temp=temp->next;
//         }
//         if(carry){
//             Node*newNode=new Node(carry);
//             prev->next=newNode;
//         }
//         return getReversed(newHead);
//     }
// };

//Add two numbers in LL
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode*temp1=l1,*temp2=l2;
//         ListNode*dummy=new ListNode(-1);
//         ListNode*temp=dummy;
//         int carry=0;
//         while(temp1 && temp2){
//             int data=temp1->val+temp2->val+carry;
//             if(data>9){
//                 carry=data/10;
//                 data%=10;
//             }
//             else{
//                 carry=0;
//             }
//             ListNode*newNode=new ListNode(data);
//             temp->next=newNode;
//             temp=temp->next;
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         while(temp1){
//             int data=temp1->val+carry;
//             if(data>9){
//                 carry=data/10;
//                 data%=10;
//             }
//             else{
//                 carry=0;
//             }
//             ListNode*newNode=new ListNode(data);
//             temp->next=newNode;
//             temp=temp->next;
//             temp1=temp1->next;
//         }
//         while(temp2){
//             int data=temp2->val+carry;
//             if(data>9){
//                 carry=data/10;
//                 data%=10;
//             }
//             else{
//                 carry=0;
//             }
//             ListNode*newNode=new ListNode(data);
//             temp->next=newNode;
//             temp=temp->next;
//             temp2=temp2->next;
//         }
//         if(carry){
//             ListNode*newNode=new ListNode(carry);
//             temp->next=newNode;
//             temp=temp->next;
//         }
//         return dummy->next;
//     }
// };