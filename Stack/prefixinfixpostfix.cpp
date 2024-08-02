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

// Postfix to infix conversion
// class Solution {
//   public:
//     string postToInfix(string exp) {
//            stack<string>stk;
//         int i=0,n=exp.length();
//         while(i<n){
//             if( isalnum(exp[i])){
//                 stk.push(string(1,exp[i]));
//             }
//             else{
//                 string top1=stk.top();
//                 stk.pop();
//                 string top2=stk.top();
//                 stk.pop();
//                 stk.push("("+top2+exp[i]+top1+")");
//             }
//             i++;
//         }
//         return stk.top();
//     }
// };

//Prefix to Infix conversion
// class Solution {
//   public:
//     string preToInfix(string pre_exp) {
//         int i=pre_exp.length()-1;
//         stack<string>stk;
//         while(i>=0){
//             if(isalpha(pre_exp[i]) || isdigit(pre_exp[i])){
//                 stk.push(string(1,pre_exp[i]));
//             }
//             else{
//                 string top1=stk.top();
//                 stk.pop();
//                 string top2=stk.top();
//                 stk.pop();
//                 stk.push("("+top1+pre_exp[i]+top2+")");
//             }
//             i--;
//         }
//         return stk.top();
//     }
// };

//Postfix to prefix
// class Solution {
//   public:
//     string postToPre(string post_exp) {
//         stack<string>stk;
//         int i=0,n=post_exp.length();
//         while(i<n){
//             if(isalnum(post_exp[i])){
//                 stk.push(string(1,post_exp[i]));
//             }
//             else{
//                 string top1=stk.top();
//                 stk.pop();
//                 string top2=stk.top();
//                 stk.pop();
//                 stk.push(post_exp[i]+top2+top1);
//             }
//             i++;
//         }
//         return stk.top();
//     }
// };

// Prefix to postfix
// class Solution {
//   public:
//     string preToPost(string pre_exp) {
//         stack<string>stk;
//         int i=pre_exp.length()-1;
//         while(i>=0){
//             if(isalnum(pre_exp[i])){
//                 stk.push(string(1,pre_exp[i]));
//             }
//             else{
//                 string top1=stk.top();
//                 stk.pop();
//                 string top2=stk.top();
//                 stk.pop();
//                 stk.push(top1+top2+pre_exp[i]);
//             }
//             i--;
//         }
//         return stk.top();
//     }
// };