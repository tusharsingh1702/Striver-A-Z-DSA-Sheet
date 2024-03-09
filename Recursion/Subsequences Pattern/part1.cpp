//Print all subsequences/ Power set
// Using recursion
// #include <iostream>
// using namespace std;
// void findSubsequences(int*arr,vector<int>ds,int index,int n){
//       if(index==n){
//             if(ds.size()==0){
//                   cout<<"[]"<<endl;
//             }
//             else{
//             for(auto it:ds){
//                   cout<<it<<' ';
//             }
//             cout<<endl;
//             }
//             return;
//       }
//       ds.push_back(arr[index]);
//       findSubsequences(arr,ds,index+1,n);
//       ds.pop_back();
//       findSubsequences(arr,ds,index+1,n);
// }
// int main(){
//       int arr[]={3,2,1};
//       int n=sizeof(arr)/sizeof(int);
//       vector<int>ds;
//       findSubsequences(arr,ds,0,n);
//       return 0;
// }

//Using Power Set
// #include <iostream>
// using namespace std;
// int main(){
//       int arr[]={3,2,1};
//       int n=sizeof(arr)/sizeof(int);
//       for(int num=0;num<(1<<n);num++){
//             vector<int>ds;
//             for(int i=0;i<n;i++){
//                   if((num&(1<<i))!=0){
//                         ds.push_back(arr[i]);
//                   }
//             }
//             for(auto it:ds){
//                   cout<<it<<' ';
//             }
//             cout<<endl;
//       }
//       return 0;
// }

//Count all subsequences with sum k.
// #include <iostream>
// using namespace std;
// void getSubsequences(int*arr,int n,int index,vector<int>ds,int sum,int s){
//       if(index==n){
//             if(s==sum){
//                   for(auto it:ds){
//                         cout<<it<<' ';
//                   }
//                   cout<<endl;
//             }
//                   return;
//       }
//       ds.push_back(arr[index]);
//       getSubsequences(arr,n,index+1,ds,sum,s+arr[index]);
//       ds.pop_back();
//       getSubsequences(arr,n,index+1,ds,sum,s);
// }
// int main(){
//       int arr[]={1,2,2,1,4,3};
//       int n=sizeof(arr)/sizeof(int);
//       int sum=4;
//       vector<int>ds;
//       getSubsequences(arr,n,0,ds,sum,0);
//       return 0;
// }

//Combination Sum 1- Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// #include <iostream>
// using namespace std;
// void getAns(int*arr,int n,int index,vector<vector<int> >&ans,vector<int>ds,int target){
//       if(index==n){
//             if(target==0){
//                   ans.push_back(ds);
//             }
//             return;
//       }
//       if(arr[index]<=target){
//             ds.push_back(arr[index]);
//             getAns(arr,n,index,ans,ds,target-arr[index]);
//             ds.pop_back();
//       }
//       getAns(arr,n,index+1,ans,ds,target);
// }
// int main(){
//       int arr[]={2,3,6,7};
//       int n=sizeof(arr)/sizeof(int);
//       vector<vector<int> >ans;
//       vector<int>ds;
//       int target=7;
//       getAns(arr,n,0,ans,ds,target);
//       for(int i=0;i<ans.size();i++){
//             for(int j=0;j<ans[i].size();j++){
//                   cout<<ans[i][j]<<' ';
//             }
//             cout<<endl;
//       }
//       return 0;
// }

//Combination Sum 2-Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.Each number in candidates may only be used once in the combination.The solution set must not contain duplicate combinations.
// #include <iostream>
// using namespace std;
// void getAns(int*arr,int n,int index,int target,vector<int>ds,vector<vector<int> >&ans){
// if(target==0){
//       ans.push_back(ds);
//       return;
// }
// for(int i=index;i<n;i++){
//       if(i>index && arr[i]==arr[i-1]){
//             continue;
//       }
//       if(arr[i]>target){
//             break;
//       }
//       ds.push_back(arr[i]);
//       getAns(arr,n,i+1,target-arr[i],ds,ans);
//       ds.pop_back();
// }
// }
// int main(){
//       int arr[]={10,1,2,7,6,1,5};
//       int n=sizeof(arr)/sizeof(int);
//       int target=8;
//       vector<vector<int> >ans;
//       vector<int>ds;
//       sort(arr,arr+n);
//       getAns(arr,n,0,target,ds,ans);
//       for(int i=0;i<ans.size();i++){
//             for(int j=0;j<ans[i].size();j++){
//                   cout<<ans[i][j]<<' ';
//             }
//             cout<<endl;
//       }
//       return 0;
// }

//Combination Sum 3
// void getans(int index,vector<int>&candidates,int k,int n,vector<int>&ds,vector<vector<int>>&ans){
//         if(index==candidates.size()){
//             if(ds.size()==k && n==0){
//                 ans.push_back(ds);
//             }
//             return;
//         }
//         if(candidates[index]<=n){
//         ds.push_back(candidates[index]);
//         getans(index+1,candidates,k,n-candidates[index],ds,ans);
//         ds.pop_back();
//         }
//         getans(index+1,candidates,k,n,ds,ans);
//     }
//     vector<vector<int> > combinationSum3(int k, int n) {
//         vector<int>candidates(9);
//         iota(candidates.begin(),candidates.end(),1);
//         vector<int>ds;
//         vector<vector<int>>ans;
//         getans(0,candidates,k,n,ds,ans);
//         return ans;
//     }

//Subset Sum-1
// void getAns(vector<int>num,int index,int sum,vector<int>&ds,int n){
// 	if(index==n){
// 		ds.push_back(sum);
// 		return;
// 	}

// 	getAns(num,index+1,sum+num[index],ds,n);
// 	getAns(num,index+1,sum,ds,n);
// }
// vector<int> subsetSum(vector<int> &num){
//     vector<int>ds;
// 	int n=num.size();
// 	getAns(num,0,0,ds,n);
// 	sort(ds.begin(),ds.end());
// 	return ds;
// }

//Subset Sum 2
//     void getAns(vector<int>nums,int index,vector<int>ds,vector<vector<int>>&ans,int n){
//         ans.push_back(ds);
//         for(int i=index;i<n;i++){
//             if(i>index && nums[i-1]==nums[i]){
//                 continue;
//             }
//                 ds.push_back(nums[i]);
//                 getAns(nums,i+1,ds,ans,n);
//                 ds.pop_back();
//         }
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>ds;
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         getAns(nums,0,ds,ans,n);
//         return ans;
//     }

//Letter combinations of a phone number.
// void getAns(string&digits,string*mapping,int index,string output,vector<string>&ans,int&n){
//     if(index==n){
//         ans.push_back(output);
//         return;
//     }
//     int number=digits[index]-'0';
//     string combination=mapping[number];
//     for(int i=0;i<combination.length();i++){
//         output.push_back(combination[i]);
//         getAns(digits,mapping,index+1,output,ans,n);
//         output.pop_back();
//     }
// }
//     vector<string> letterCombinations(string digits) {
//         string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//         vector<string>ans;
//         string output="";
//         int n=digits.length();
//         if(n==0){
//             return ans;
//         }
//         getAns(digits,mapping,0,output,ans,n);
//         return ans;
//     }
