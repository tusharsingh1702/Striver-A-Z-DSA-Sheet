//Longest Common Subsequence
// class Solution {
// public:
//     vector<vector<int>>dp;
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.length(),m=text2.length();
//         dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
//         for(int i=0;i<=m;i++){
//             dp[0][i]=0;
//         }
//         for(int i=0;i<=n;i++){
//             dp[i][0]=0;
//         }
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                  if(text1[i-1]==text2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//         }
//         else{
//         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//         }
//             }
//         }
//         return dp[n][m];
//     }
// };

//Print all LCSs
// class Solution
// {
// 	public:
//     // vector<vector<int>>dp;
//     void getAns(string&s,string&t,int i,int j,string str,int ind,set<string>&ans,vector<vector<int>>&dp){
//         if(i<=0 || j<=0){
//             ans.insert(str);
//             return;
//         }
//         if(s[i-1]==t[j-1]){
//             str[ind]=s[i-1];
//             getAns(s,t,i-1,j-1,str,ind-1,ans,dp);
//         }
//         else{
//          if(dp[i-1][j]<=dp[i][j-1]){
//             getAns(s,t,i,j-1,str,ind,ans,dp);
//         }
//         if(dp[i-1][j]>=dp[i][j-1]){
//             getAns(s,t,i-1,j,str,ind,ans,dp);
            
//         }
//         }
//     }
// 		vector<string> all_longest_common_subsequences(string s, string t)
// 		{
// 		    int n=s.length(),m=t.length();
// 		    vector<vector<int>>dp(n+1,(vector<int>(m+1,-1)));
// 		    for(int i=0;i<=m;i++){
// 		        dp[0][i]=0;
// 		    }
// 		    for(int i=0;i<=n;i++){
// 		        dp[i][0]=0;
// 		    }
// 		    for(int i=1;i<=n;i++){
// 		        for(int j=1;j<=m;j++){
// 		            if(s[i-1]==t[j-1]){
// 		                dp[i][j]= 1+dp[i-1][j-1];
// 		            }
// 		            else{
// 		                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
// 		            }
// 		        }
// 		    }
		
// 		    set<string>ans;
// 		    string str(dp[n][m],'$');
// 		    int ind=dp[n][m]-1,i=n,j=m;
// 		    getAns(s,t,i,j,str,ind,ans,dp);
// 		   return vector<string>(ans.begin(),ans.end());
// 		}
// };

//Longest common substring
// class Solution{
//     public:
    
//     int longestCommonSubstr (string S1, string S2, int n, int m)
//     {
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//         for(int i=0;i<=m;i++){
//             dp[0][i]=0;
//         }
//         for(int i=0;i<=n;i++){
//             dp[i][0]=0;
//         }
//         int ans=0;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(S1[i-1]==S2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                     ans=max(ans,dp[i][j]);
//                 }
//                 else{
//                     dp[i][j]=0;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//Longest Pallindromic Subsequence
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         string t=s;
//         reverse(t.begin(),t.end());
//         int n=t.length(),m=n;
//         vector<int>prev(n+1,0),curr(n+1,0);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==t[j-1]){
//                     curr[j]=1+prev[j-1];
//                 }
//                 else{
//                     curr[j]=0+max(prev[j],curr[j-1]);
//                 }
//             }
//             prev=curr;
//         }
//        return prev[m];
//     }
// };

//Minimum insertion steps to make a string pallindrome
// class Solution {
// public:
//     int longestPalindromicSubsequence(string s){
//          string t=s;
//         reverse(t.begin(),t.end());
//         int n=t.length(),m=n;
//         vector<int>prev(n+1,0),curr(n+1,0);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==t[j-1]){
//                     curr[j]=1+prev[j-1];
//                 }
//                 else{
//                     curr[j]=0+max(prev[j],curr[j-1]);
//                 }
//             }
//             prev=curr;
//         }
//        return prev[m];
//     }
//     int minInsertions(string s) {
//         int len=longestPalindromicSubsequence(s);
//         return s.length()-len;
//     }
// };

//Delete operations for two strings
// class Solution {
// public:
//     int longestCommonSubsequence(string word1,string word2){
//         int n=word1.length(),m=word2.length();
//         // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//         vector<int>prev(m+1,0),curr(m+1,0);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1]==word2[j-1]){
//                     curr[j]=1+prev[j-1];
//                 }
//                 else{
//                     curr[j]=max(prev[j],curr[j-1]);
//                 }
//             }
//             prev=curr;
//         }
//         return prev[m];
//     }
//     int minDistance(string word1, string word2) {
//         int len=longestCommonSubsequence(word1,word2);
//         int deletion=word1.length()-len;
//         int insertions=word2.length()-len;
//         return deletion+insertions;
//     }
// };