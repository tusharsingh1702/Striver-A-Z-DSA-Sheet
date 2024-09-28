// Implement Trie || Insert || Search || StartsWith
// class TrieNode{
//     public:
//     TrieNode*children[26];
//     bool ending;
//     TrieNode(){
//         ending=false;
//         for(int i=0;i<26;i++){
//             this->children[i]=NULL;
//         }
//     }
// };
// class Trie {
// public:
//     TrieNode*root;
//     Trie() {
//         root=new TrieNode();
//     }
    
//     void insert(string word) {
//         int n=word.length();
//         TrieNode*temp=root;
//         for(int i=0;i<n;i++){
//             int ind=word[i]-'a';
//             if(temp->children[ind]==NULL){
//                 temp->children[ind]=new TrieNode();
//             }
//             temp=temp->children[ind];
//         }
//         temp->ending=true;
//     }
    
//     bool search(string word) {
//         int n=word.length();
//         TrieNode*temp=root;
//         for(int i=0;i<n;i++){
//             int ind=word[i]-'a';
//             if(temp->children[ind]==NULL){
//                 return false;
//             }
//             temp=temp->children[ind];
//         }
//         return temp->ending;
//     }
    
//     bool startsWith(string prefix) {
//         int n=prefix.length();
//         TrieNode*temp=root;
//         for(int i=0;i<n;i++){
//             int ind=prefix[i]-'a';
//             if(temp->children[ind]==NULL){
//                 return false;
//             }
//             temp=temp->children[ind];
//         }
//         return true;
//     }
// };