//Introduction
// class Solution {
//   public:
//     Node* constructDLL(vector<int>& arr) {
//         // code here
//         Node*head=new Node(arr[0]);
//         Node*temp=head;
//         Node*prev=NULL;
//         for(int i=1;i<arr.size();i++){
//             temp->next=new Node(arr[i]);
//             temp->prev=prev;
//             prev=temp;
//             temp=temp->next;
//         }
//         return head;
//     }
// };

//Insert a node in a double linked list
// void addNode(Node *head, int pos, int data)
// {
//    // Your code here
//    Node*temp=head;
//    while(pos!=0){
//        pos--;
//        temp=temp->next;
//    }
//    Node*forw=temp->next;
//    Node*newNode=new Node(data);
//    newNode->prev=temp;
//    newNode->next=forw;
//    temp->next=newNode;
//    if(forw){
//        forw->prev=newNode;
//    }
// }

//Delete a node in a doubly linked list
// class Solution {
//   public:
//     Node* deleteNode(Node* head, int x) {
//         if(x==1){
//             Node*temp=head;
//             head=head->next;
//             temp->next=NULL;
//             head->prev=NULL;
//             return head;
//         }
//         Node*back=NULL,*temp=head;
//         while(x!=1){
//             x--;
//             back=temp;
//             temp=temp->next;
//         }
//         Node*forw=temp->next;
//         back->next=forw;
//         if(forw){
//             forw->prev=back;
//         }
//         delete temp;
//         return head;
//     }
// };

//Reverse a doubly linked list
// class Solution
// {
//     public:
//     Node* reverseDLL(Node * head)
//     {
//         Node*last=NULL,*curr=head,*forw=NULL;
//         while(curr){
//             forw=curr->next;
//             curr->next=last;
//             curr->prev=forw;
//             last=curr;
//             curr=forw;
//         }
//         return last;
//     }
// };