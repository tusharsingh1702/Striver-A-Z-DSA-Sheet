//String to Integer (atoi)
// class Solution {
// public:
//     int myAtoi(string s) {
//         if(s.length()==0){
//             return 0;
//         }
//         int i=0;
//         while(s[i]==' ' && i<s.length()){
//             i++;
//         }
//         s=s.substr(i);
//         int sign=1;
//         i=(s[0]=='-' || s[0]=='+')?1:0;
//         if(s[0]=='-'){
//             sign=-1;
//         }
//         long ans=0;
//         while(i<s.length() && isdigit(s[i]) && s[i]!=' '){
//             ans=ans*10+(s[i]-'0');
//             if(sign==1 && ans*sign>INT_MAX)return INT_MAX;
//             else if(sign==-1 && ans*sign<INT_MIN)return INT_MIN;
//             i++;
//         }
//         return (int)(ans*sign);
//     }
// };

//Power function using recursion
// class Solution {
// public:
//     double power(double x,int n){
//          if(n==0){
//             return 1;
//          }

//          return x*power(x,n-1);
//     }
//     double myPow(double x, int n) {
//         if(n==INT_MIN){
//             return x==1||x==-1?1:0;
//         }
//         if(n==INT_MAX){
//             return x==1?1:(x==-1)?-1:0;
//         }
//         if(n==0 || x==1){
//             return 1;
//         }
//         if(n>=0){
//            return power(x,n);
//         }
//         long num=n*(-1);
//         x=1/x;
//         return power(x,num);
//     }
// };

//Count good numbers
// class Solution {
// public:
// /*
// 0 1 2 3 4 5 6 7 8 9
// even- 0 2 4 6 8 
// prime- 2 3 5 7
// 5*4*5*4=400
// 0 1 2 3 4 5 6
// */
//     int MOD=1e9+7;
//     long long power(long long x,long long n){
//         long long ans=1;
//         while(n>0){
//             if(n%2==0){
//                 x=(x*x)%MOD;
//                 n/=2;
//             }
//             else{
//                 ans=(ans*x)%MOD;
//                 n-=1;
//             }
//         }
//         return ans;
//     }
//     int countGoodNumbers(long long n) {
//         long long odd=n/2;
//         long long even=n-odd;
//         // ans= 5^even*4*odd;
//         long long evenRaise=power(5,even);
//         long long oddRaise=power(4,odd);

//         return (evenRaise*oddRaise)%MOD;

//     }
// };


//Sort a stack using Recursion
// void insertSorted(stack<int>&s,int num){
//     if(s.empty()){
//         s.push(num);
//         return;
//     }
//     if(s.top()>num){
//         int n=s.top();
//         s.pop();
//         insertSorted(s,num);
//         s.push(n);
//     }
//     else{
//         s.push(num);
//     }
// }
// void SortedStack :: sort()
// {
//    if(s.empty()){
//        return;
//    }
//    int num=s.top();
//    s.pop();
//   sort();
//   insertSorted(s,num);
// }

//Reverse a stack using Recursion
// class Solution{
// public:
//     void insertAtBottom(stack<int>&St,int num){
//         if(St.empty()){
//             St.push(num);
//                 return;
//         }
//         int number=St.top();
//         St.pop();
//         insertAtBottom(St,num);
//         St.push(number);
//     }
//     void Reverse(stack<int> &St){
//         if(St.empty()){
//             return;
//         }
//         int num=St.top();
//         St.pop();
//         Reverse(St);
//         insertAtBottom(St,num);
//     }
// };