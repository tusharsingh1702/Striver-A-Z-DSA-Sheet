// Sliding Window Maximum
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int>ans;
//     deque<int>dq;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         if(!dq.empty() && dq.front()==i-k){
//             dq.pop_front();
//         }
//         while(!dq.empty() && nums[dq.back()]<=nums[i]){
//             dq.pop_back();
//         }
//         if(dq.empty() || nums[i]<nums[dq.back()]){
//             dq.push_back(i);
//         }

//         if(i>=k-1){
//             ans.push_back(nums[dq.front()]);
//         }
//     }
    
//     return ans;
//     }
// };

//Online stock span
// class StockSpanner {
// public:
//     int index;
//     stack<pair<int,int>>stk;
//     //val and index;
//     StockSpanner() {
//         index=-1;
//     }
    
//     int next(int price) {
//         index++;
//         int prevMax=1;
//         if(stk.empty() || price<stk.top().first){
//             stk.push({price,index});
//         }
//         else{
//             while(!stk.empty() && stk.top().first<=price){
//                 stk.pop();
//             }
//             if(stk.empty()){
//                 prevMax=index+1;
//             }
//             else{
//             prevMax=index-stk.top().second;
//             }
//             stk.push({price,index});
//         }
//         // cout<<prevMax<<' '<<index<<endl;
//         return prevMax;
//     }
// };

//Celebrity Problem
// class Solution {
//   public:
//     // Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& M, int n) {
//          int up=0,down=n-1;
//          while(up<down){
//              if(M[up][down]==1){
//                  up++;
//              }
//              else if(M[down][up]==1){
//                  down--;
//              }
//              else{
//                  up++;
//                  down--;
//              }
//          }
//          if(up>down){
//              return -1;
//          }
//          for(int i=0;i<n;i++){
//              if(M[up][i]==1 && i!=up){
//                  return -1;
//              }
//              if(M[i][up]==0 && i!=up){
//                  return -1;
//              }
//          }
//          return up;
//     }
// };

//LRU Cache Problem
// class Node{
//     public:
//     Node*next;
//     Node*prev;
//     int key;
//     int val;
//     Node(int key,int value){
//         this->key=key;
//         this->val=value;
//         this->next=NULL;
//         this->prev=NULL;
//     }
// };
// class LRUCache {
// public:
//         unordered_map<int,Node*>mp;
//         Node*head,*tail;
//         int size,capacity;
//     LRUCache(int capacity) {
//         this->capacity=capacity;
//         size=0;
//         mp.clear();
//         head=new Node(-1,-1);
//         tail=new Node(-1,-1);
//         head->next=tail;
//         tail->prev=head;
//     }
    


//     void deleteNode(Node*node){
//     Node*previous=node->prev;
//      previous->next=node->next;
//     node->next->prev=previous;
//     // node->prev=NULL;
//     // node->next=NULL;
//     }
//     void insertAtHead(Node*node){
//             Node*forw=head->next;
//             head->next=node;
//             node->prev=head;
//             node->next=forw;
//             forw->prev=node;
//     }
//     int get(int key) {
//         if(mp.find(key)==mp.end()){
//             return -1;
//         }
//         else{
//             Node*node=mp[key];
//             deleteNode(node);
//             insertAtHead(node);
//             return node->val;
//         }
//     }
    
//     void put(int key, int value) {
//         if(mp.find(key)!=mp.end()){
//             Node*node=mp[key];
//             node->val=value;
//             mp[key]=node;
//             deleteNode(node);
//             insertAtHead(node);
//         }
//         else{
//              if(size==capacity){
//                 mp.erase(tail->prev->key);
//                 deleteNode(tail->prev);
//                 size--;
//              }
//             Node*node=new Node(key,value);
//              insertAtHead(node);
//              size++;
//                 mp[key]=node;
//         }
//     }
// };

//LFU cache problem
// struct Node {
//     int key, value, cnt;
//     Node *next; 
//     Node *prev;
//     Node(int _key, int _value) {
//         key = _key;
//         value = _value; 
//         cnt = 1; 
//     }
// }; 
// struct List {
//     int size; 
//     Node *head; 
//     Node *tail; 
//     List() {
//         head = new Node(0, 0); 
//         tail = new Node(0,0); 
//         head->next = tail;
//         tail->prev = head; 
//         size = 0;
//     }
    
//     void addFront(Node *node) {
//         Node* temp = head->next;
//         node->next = temp;
//         node->prev = head;
//         head->next = node;
//         temp->prev = node;
//         size++; 
//     }
    
//     void removeNode(Node* delnode) {
//         Node* delprev = delnode->prev;
//         Node* delnext = delnode->next;
//         delprev->next = delnext;
//         delnext->prev = delprev;
//         size--; 
//     }
    
    
    
// };
// class LFUCache {
//     map<int, Node*> keyNode; 
//     map<int, List*> freqListMap; 
//     int maxSizeCache;
//     int minFreq; 
//     int curSize; 
// public:
//     LFUCache(int capacity) {
//         maxSizeCache = capacity; 
//         minFreq = 0;
//         curSize = 0; 
//     }
//     void updateFreqListMap(Node *node) {
//         keyNode.erase(node->key); 
//         freqListMap[node->cnt]->removeNode(node); 
//         if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
//             minFreq++; 
//         }
        
//         List* nextHigherFreqList = new List();
//         if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
//             nextHigherFreqList = freqListMap[node->cnt + 1];
//         } 
//         node->cnt += 1; 
//         nextHigherFreqList->addFront(node); 
//         freqListMap[node->cnt] = nextHigherFreqList; 
//         keyNode[node->key] = node;
//     }
    
//     int get(int key) {
//         if(keyNode.find(key) != keyNode.end()) {
//             Node* node = keyNode[key]; 
//             int val = node->value; 
//             updateFreqListMap(node); 
//             return val; 
//         }
//         return -1; 
//     }
    
//     void put(int key, int value) {
//         if (maxSizeCache == 0) {
//             return;
//         }
//         if(keyNode.find(key) != keyNode.end()) {
//             Node* node = keyNode[key]; 
//             node->value = value; 
//             updateFreqListMap(node); 
//         }
//         else {
//             if(curSize == maxSizeCache) {
//                 List* list = freqListMap[minFreq]; 
//                 keyNode.erase(list->tail->prev->key); 
//                 freqListMap[minFreq]->removeNode(list->tail->prev);
//                 curSize--; 
//             }
//             curSize++; 
//             minFreq = 1; 
//             List* listFreq = new List(); 
//             if(freqListMap.find(minFreq) != freqListMap.end()) {
//                 listFreq = freqListMap[minFreq]; 
//             }
//             Node* node = new Node(key, value); 
//             listFreq->addFront(node);
//             keyNode[key] = node; 
//             freqListMap[minFreq] = listFreq; 
//         }
//     }
// };
