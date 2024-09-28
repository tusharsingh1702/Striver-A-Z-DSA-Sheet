// Implement Trie-2
// #include <bits/stdc++.h> 
// class TrieNode{
//     public:
//     TrieNode*children[26];
//     int endCount;
//     int prefixCount;
//     TrieNode(){
//         endCount=0;
//         prefixCount=0;
//         for(int i=0;i<26;i++){
//             this->children[i]=NULL;
//         }
//     }
// };
// class Trie{
//     public:
//     TrieNode*root;

//     Trie(){
//         root=new TrieNode();
//     }

//     void insert(string &word){
//         TrieNode*temp=root;
//         int n=word.length();
//         for(int i=0;i<n;i++){
//             int ind=word[i]-'a';
//             if(temp->children[ind]==NULL){
//                 temp->children[ind]=new TrieNode();
//             }
//             temp=temp->children[ind];
//             temp->prefixCount=temp->prefixCount+1;
//         }
//         temp->endCount=temp->endCount+1;

//     }

//     int countWordsEqualTo(string &word){
//             TrieNode*temp=root;
//             int n=word.length();
//             for(int i=0;i<n;i++){
//                 int ind=word[i]-'a';
//                 if(temp->children[ind]==NULL){
//                     return 0;
//                 }
//                 temp=temp->children[ind];
//             }
//             return temp->endCount;
//     }

//     int countWordsStartingWith(string &word){
//             int n=word.length();
//             TrieNode*temp=root;
//             for(int i=0;i<n;i++){
//                 int ind=word[i]-'a';
//                 if(temp->children[ind]==NULL){
//                     return 0;
//                 }
//                 temp=temp->children[ind];
//             }
//             return temp->prefixCount;
//     }

//     void erase(string &word){
//         TrieNode*temp=root;
//         int n=word.length();
//         for(int i=0;i<n;i++){
//             int ind=word[i]-'a';
//             temp=temp->children[ind];
//             temp->prefixCount--;
//         }
//         temp->endCount=temp->endCount-1;
//     }
// };

// Complete String
// #include <bits/stdc++.h> 
// class TrieNode{
//     public:
//     TrieNode*children[26];
//     bool end;
//     TrieNode(){
//         this->end=false;
//         for(int i=0;i<26;i++){
//             this->children[i]=NULL;
//         }
//     }
// };

//     TrieNode*getTrieNode(){
//         TrieNode*newNode=new TrieNode();
//         return newNode;
//     }
// void insert(TrieNode*root,string str){
//     TrieNode*temp=root;
//     int n=str.length();
//     for(int i=0;i<n;i++){
//         int ind=str[i]-'a';
//         if(temp->children[ind]==NULL){
//             temp->children[ind]=getTrieNode();
//         }
//         temp=temp->children[ind];
//     }
//     temp->end=true;
// }

// bool checkComplete(TrieNode*root,string str){
//     TrieNode*temp=root;
//     int n=str.length();
//     for(int i=0;i<n;i++){
//         int ind=str[i]-'a';
//         if(temp->children[ind]==NULL || temp->children[ind]->end==false){
//             return false;
//         }
//         temp=temp->children[ind];
//     }
//     return true;
// }
// string completeString(int n, vector<string> &a){
//     TrieNode*root=getTrieNode();

//     for(string&str:a){
//         insert(root,str);
//     }
//     string complete="";
//     for(string&str:a){
//         bool isComplete=checkComplete(root,str);
//         if(isComplete){
//             if(complete=="" || str.length()>complete.length()){
//                 complete=str;
//             }
//             else if(str.length()==complete.length()){
//                 complete=min(complete,str);
//             }
//         }
//     }

//     return complete==""?"None":complete;
// }

//Count distinct substrings
// class TrieNode{
//     public:
//     TrieNode*children[26];
//     TrieNode(){
//         for(int i=0;i<26;i++){
//             this->children[i]=NULL;
//         }
//     }
// };

// TrieNode*getTrieNode(){
//     return new TrieNode();
// }

// void insert(TrieNode*root,string str,int&count){
//     TrieNode*temp=root;
//     int n=str.length();
//     for(int i=0;i<n;i++){
//         int ind=str[i]-'a';
//         if(temp->children[ind]==NULL){
//             temp->children[ind]=getTrieNode();
//             count++;
//         }
//         else{
//             temp=temp->children[ind];
//         }
//     }
// }
// int countDistinctSubstrings(string &s)
// {
//     TrieNode*root=getTrieNode();
//     int count=0;
//     for(int i=0;i<s.length();i++){
//         for(int j=i;j<s.length();j++){
//             insert(root,s.substr(i,j-i+1),count);
//         }
//     }
//     return count+1;

// }

// Bit Prerequisites
// class Solution {
//   public:
//     int XOR(int n, int m) {
//             return n^m;
//     }
//     int check(int a, int b) {
// return (b & (1 << (a-1))) != 0;
//     }
//     int setBit(int c, int d) {
//         return (d|(1<<c));
//     }
// };

// Maximum XOR of two numbers in an array
// class TrieNode{
//     public:
//     TrieNode*links[2];
//     TrieNode(){
//         for(int i=0;i<2;i++){
//             this->links[i]=NULL;
//         }
//     }
// };
// class Solution {
// public:
//     void insert(TrieNode*root,int num){
//         TrieNode*temp=root;
//         for(int i=31;i>=0;i--){
//             bool isSet=(num&(1<<i))!=0;
//             if(isSet){
//                 if(temp->links[1]==NULL){
//                     temp->links[1]=new TrieNode();
//                 }
//                     temp=temp->links[1];
//             }
//             else{
//                 if(temp->links[0]==NULL){
//                     temp->links[0]=new TrieNode();
//                 }
//                     temp=temp->links[0];
//             }
//         }
//     }

//     int getMaxXor(TrieNode*root,int x){
//         int ans=0;
//         TrieNode*temp=root;
//         for(int i=31;i>=0;i--){
//             bool isSet=(x&(1<<i))!=0;
//             if(isSet){
//                 if(temp->links[0]!=NULL){
//                     ans=(ans|(1<<i));
//                     temp=temp->links[0];
//                 }
//                 else{
//                     temp=temp->links[1];
//                 }
//             }
//             else{
//                 if(temp->links[1]!=NULL){
//                     ans=(ans|(1<<i));
//                     temp=temp->links[1];
//                 }
//                 else{
//                     temp=temp->links[0];
//                 }
//             }
//         }
//         return ans;
//     }
//     int findMaximumXOR(vector<int>& nums) {
//          TrieNode*root=new TrieNode();
//          int maxi=0,ind=-1;
//          for(int i=0;i<nums.size();i++){
//             int num=nums[i];
//             insert(root,num);
//             maxi=max(maxi,getMaxXor(root,num));
//          }
//          return maxi;
//     }
// };

//Maximize Xor from an element from array.
// class TrieNode{
//     public:
//     TrieNode*links[2];
//     TrieNode(){
//         this->links[0]=NULL;
//         this->links[1]=NULL;
//     }
// };
// class Solution {
// public:
//     static bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
//         return a.second.second<b.second.second;
//     }

//   void insert(TrieNode*root,int num){
//         TrieNode*temp=root;
//         for(int i=31;i>=0;i--){
//             bool isSet=(num&(1<<i))!=0;
//             if(isSet){
//                 if(temp->links[1]==NULL){
//                     temp->links[1]=new TrieNode();
//                 }
//                     temp=temp->links[1];
//             }
//             else{
//                 if(temp->links[0]==NULL){
//                     temp->links[0]=new TrieNode();
//                 }
//                     temp=temp->links[0];
//             }
//         }
//     }
    
//      int getMaxXor(TrieNode*root,int x){
//         if(!root){
//             return -1;
//         }
//         int ans=0;
//         TrieNode*temp=root;
//         for(int i=31;i>=0;i--){
//             bool isSet=(x&(1<<i))!=0;
//             if(isSet){
//                 if(temp->links[0]!=NULL){
//                     ans=(ans|(1<<i));
//                     temp=temp->links[0];
//                 }
//                 else{
//                     temp=temp->links[1];
//                 }
//             }
//             else{
//                 if(temp->links[1]!=NULL){
//                     ans=(ans|(1<<i));
//                     temp=temp->links[1];
//                 }
//                 else{
//                     temp=temp->links[0];
//                 }
//             }
//         }
//         return ans;
//     }
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<pair<int,pair<int,int>>>vec;
//         int n=queries.size();
//         for(int i=0;i<n;i++){
//             vec.push_back({i,{queries[i][0],queries[i][1]}});
//         }

//         sort(vec.begin(),vec.end(),cmp);
//         sort(nums.begin(),nums.end());

//         TrieNode*root=new TrieNode();
//         int i,j=0;
//         vector<int>ans(n);
//         for(i=0;i<n;i++){
//             int first=vec[i].second.first;
//             int second=vec[i].second.second;
//             if(j==0 && nums[0]>second){
//                 ans[vec[i].first]=-1;
//             }
//             else{
//             for(;j<nums.size() && nums[j]<=second;j++){
//                 insert(root,nums[j]);
//             }
//                     ans[vec[i].first]=getMaxXor(root,first);
//             }
//         }
//         return ans;
//     }
// };