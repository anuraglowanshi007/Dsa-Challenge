#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int>leaderArray(int arr[],int n){
      vector<int>ans;            
      for(int i=0;i<n;i++){
            bool leader = true;
            for(int j=i+1;j<n;j++){
                  if(arr[j]>arr[i]){
                        leader = false;
                        break;
                  }
            }
             if(leader){
            ans.push_back(arr[i]);
             }
      }
     
     return ans;
}

int main(){
      int arr[] = {1,2,3,2,4,5};
      int n  = sizeof(arr)/sizeof(arr[0]);
      vector<int>result = leaderArray(arr,n);
      for(int i=0;i<result.size();i++){
            cout<<result[i]<<endl;
      }
      return 0;
}