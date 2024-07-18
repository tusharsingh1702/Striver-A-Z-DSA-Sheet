//Infix to postfix conversion using stack
// class Solution {
//   public:
//     // Function to convert an infix expression to a postfix expression.
//     int priority(char c){
//         if(c=='^'){
//             return 3;
//         }
//         else if(c=='*' || c=='/'){
//             return 2;
//         }
//         else if(c=='+' || c=='-'){
//             return 1;
//         }
//         else{
//             return -1;
//         }
//     }
//     string infixToPostfix(string s) {
//         string ans;
//         stack<char>stk;
//         int i=0,n=s.length();
//         while(i<n){
//             if(s[i]=='('){
//                 stk.push(s[i]);
//             }
//             else if(isalpha(s[i]) || isdigit(s[i])){
//                 ans.push_back(s[i]);
//             }
//             else if(s[i]==')'){
//                 while(stk.top()!='('){
//                     ans.push_back(stk.top());
//                     stk.pop();
//                 }
//                 stk.pop();
//             }
//             else{

//                     while(!stk.empty() && priority(stk.top())>=priority(s[i])){
//                         ans.push_back(stk.top());
//                         stk.pop();
//                     }
//                     stk.push(s[i]);
//             }
//             i++;
//         }
//         while(!stk.empty()){
//             ans.push_back(stk.top());
//             stk.pop();
//         }
//         return ans;
//     }
// };