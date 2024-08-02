// Implement stack using arrays
// void MyStack ::push(int x) {
//     // Your Code
//     top++;
//     arr[top]=x;
// }

// // Function to remove an item from top of the stack.
// int MyStack ::pop() {
//     // Your Code
//     if(top==-1){
//         return -1;
//     }
//     int x=arr[top];
//     top--;
//     return x;
// }

// Implement queue using arrays
// void MyQueue :: push(int x)
// {
//         arr[rear]=x;
//         rear++;
// }

// //Function to pop an element from queue and return that element.
// int MyQueue :: pop()
// {
//     if(rear==front){
//         return -1;
//     }
//     int x=arr[front];
//     front++;
//     return x;// Your Code       
// }

// Implement Stack Using Queue
// class MyStack {
// public:
// queue<int>q;
//     MyStack() {
//     }
    
//     void push(int x) {
//         int size=q.size();
//         q.push(x);
//         for(int i=0;i<size;i++){
//             q.push(q.front());
//             q.pop();
//         }
//     }
    
//     int pop() {
//         int x=q.front();
//         q.pop();
//         return x;
//     }
    
//     int top() {
//         return q.front();
//     }
    
//     bool empty() {
//         return q.empty();
//     }
// };

//Implement queue using stack
// class MyQueue {
// public:
//     stack<int>stk1;
//     stack<int>stk2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         while(!stk1.empty()){
//             stk2.push(stk1.top());
//             stk1.pop();
//         }
//         stk1.push(x);
//         while(!stk2.empty()){
//             stk1.push(stk2.top());
//             stk2.pop();
//         }
//     }
    
//     int pop() {
//         int x=stk1.top();
//         stk1.pop();
//         return x;
//     }
    
//     int peek() {
//         return stk1.top();
//     }
    
//     bool empty() {
//         return stk1.empty();   
//          }
// };

//Implementing stack using linked list
// class MyQueue {
// public:
//     stack<int>stk1;
//     stack<int>stk2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         while(!stk1.empty()){
//             stk2.push(stk1.top());
//             stk1.pop();
//         }
//         stk1.push(x);
//         while(!stk2.empty()){
//             stk1.push(stk2.top());
//             stk2.pop();
//         }
//     }
    
//     int pop() {
//         int x=stk1.top();
//         stk1.pop();
//         return x;
//     }
    
//     int peek() {
//         return stk1.top();
//     }
    
//     bool empty() {
//         return stk1.empty();   
//          }
// };

// Implementing queue using linked list
// void MyQueue:: push(int x)
// {
//         QueueNode*newNode=new QueueNode(x);
//         if(front==NULL && rear==NULL){
//             front=newNode;
//             rear=newNode;
//         }
//         else{
//             rear->next=newNode;
//             rear=rear->next;
//         }
// }

// //Function to pop front element from the queue.
// int MyQueue :: pop()
// {
//         if(front==NULL){
//             return -1;
//         }     
//         if(front==rear){
//             QueueNode*temp=front;
//             front=NULL;
//             rear=NULL;
//             return temp->data;
//         }
//         int x=front->data;
//         QueueNode*temp=front;
//         front=front->next;
//         delete temp;
//         return x;
// }

// Check for balanced parenthesis
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char>stk;
//         for(char c:s){
//             if(c=='(' || c=='[' || c=='{'){
//                 stk.push(c);
//             }
//             else if( !stk.empty() && ((c==')' && stk.top()=='(') || (c=='}' && stk.top()=='{') || (c==']' && stk.top()=='['))){
//                 stk.pop();
//             }
//             else{
//                 return false;
//             }
//         }
//         return stk.empty();
//     }
// };

// Implement min stack
// class MinStack {
// public:
//     stack<pair<int,int>>stk;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(stk.empty()){
//             stk.push({val,val});
//         }
//         else{
//             if(val<stk.top().second){
//                 stk.push({val,val});
//             }
//             else{
//                 stk.push({val,stk.top().second});
//             }
//         }
//     }
    
//     void pop() {
//         stk.pop();
//     }
    
//     int top() {
//         return stk.top().first;
//     }
    
//     int getMin() {
//         return stk.top().second;
//     }
// };