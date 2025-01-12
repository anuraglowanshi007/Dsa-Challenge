#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// optimal appraoch of the longest subarray length

int longestSubarray(vector<int>&arr,int k,int n){
      int i=0;
      int j=0;
      int sum = arr[0];
      int maxLen = 0;

      while(j<n){
            while(j<=i&&sum>k){
                  sum-=arr[i];
                  i++;
            }
            if(sum==k){
                  maxLen = max(maxLen,j-i+1);
            }
            j++;

            if(j<n){
                  sum+=arr[j];
            }
      }
      return maxLen;

}

int main(){
      vector<int>arr = {2,3,3,2,1,9};
      int k = 10;
      int n = arr.size();
      int result = longestSubarray(arr,k,n);
      cout<<"Longest subarray : " <<result<<endl;

      return 0;
}