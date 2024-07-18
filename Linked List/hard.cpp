//Reverse Linked list in k length groups.
// class Solution {
// public:
//     ListNode*reverse(ListNode*head){
//         if(head==NULL && head->next==NULL){
//             return head;
//         }
//         ListNode*curr=head,*prev=NULL,*forw=NULL;
//         while(curr){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         ListNode*temp=head,*forw=NULL;
//         for(int i=0;i<k-1 && temp;i++){
//             temp=temp->next;
//         }
//         if(!temp){
//             return head;
//         }
//         forw=temp->next;
//         temp->next=NULL;
//         ListNode*newHead=reverse(head);
//         ListNode*front=reverseKGroup(forw,k);
//         head->next=front;
//         return newHead;
//     }
// };

//Rotate a linked list
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head==NULL || head->next==NULL || k==0){
//             return head;
//         }
//         ListNode*temp=head;
//         int length=1;
//         while(temp->next){
//             length++;
//             temp=temp->next;
//         }
//         temp->next=head;
//         k=k%length;
//         int end = length-k; //to get end of the list
//     while(end--) temp = temp->next;
//     //breaking last node link and pointing to NULL
//     head = temp->next;
//     temp->next = NULL;
        
//     return head;
//     }
// };

//Flattening of linked list
// Node*merge(Node*head1,Node*head2){
//     if(head1==NULL && head2==NULL){
//         return NULL;
//     }
//     if(head1==NULL && head2!=NULL){
//         return head2;
//     }
//     if(head1!=NULL && head2==NULL){
//         return head1;
//     }
//     Node*dummy=new Node(-1);
//     Node*tail=dummy,*temp1=head1,*temp2=head2;
//     while(temp1 && temp2){
//         if(temp1->data<=temp2->data){
//             Node*forw=temp1->bottom;
//             tail->bottom=temp1;
//             temp1->bottom=NULL;
//             temp1->next=NULL;
//             temp1=forw;
//             tail=tail->bottom;
//         }
//         else{
//             Node*forw=temp2->bottom;
//             tail->bottom=temp2;
//             temp2->bottom=NULL;
//             temp2->next=NULL;
//             temp2=forw;
//             tail=tail->bottom;
//         }
//     }
//     while(temp1){
//             Node*forw=temp1->bottom;
//             tail->bottom=temp1;
//             temp1->bottom=NULL;
//             temp1->next=NULL;
//             temp1=forw;
//             tail=tail->bottom;
//     }
//     while(temp2){
//          Node*forw=temp2->bottom;
//             tail->bottom=temp2;
//             temp2->bottom=NULL;
//             temp2->next=NULL;
//             temp2=forw;
//             tail=tail->bottom;
//     }
//     return dummy->bottom;
    
// }
// Node *flatten(Node *root) {
//     if(root->next==NULL){
//         return root;
//     }
//     Node*toMerge=flatten(root->next);
//     Node*merged=merge(root,toMerge);
//     return merged;
// }

// Clone a linked list with random next pointers.
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node*temp=head;
//         //Pehle duplicate nodes inserted between the original nodes.
//         while(temp){
//             Node*newNode=new Node(temp->val);
//             Node*forw=temp->next;
//             temp->next=newNode;
//             newNode->next=forw;
//             temp=forw;
//         }
//         temp=head;
//         //setting the random pointers.
//         while(temp){
//             Node*rand=temp->random;
//             if(!rand){
//                 temp->next->random=NULL;
//             }
//             else{
//                 temp->next->random=rand->next;
//             }
//             temp=temp->next->next;
//         }

//         //Fetching the duplicate list and making the original list like it was before.
//         temp=head;
//         Node*dummy=new Node(-1);
//         Node*tail=dummy;
//         while(temp){
//             tail->next=temp->next;
//             Node*forw=temp->next->next;
//             tail=tail->next;
//             tail->next=NULL;
//             temp->next=forw;
//             temp=forw;

//         }
//         return dummy->next;
//     }
// };