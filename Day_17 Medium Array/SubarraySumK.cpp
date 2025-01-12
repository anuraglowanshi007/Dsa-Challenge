#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int subarraySumk(int arr[],int n,int K){
      int count = 0;
      for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                  sum += arr[j];    
                  if(sum == K)
                  count++;
            }
      }
      return count;
}

int main(){
      int arr[] = {1,2,3,4,5,6,7};
      int K = 5;
      int n = sizeof(arr)/sizeof(arr[0]);
      int result = subarraySumk(arr,n,K);
      cout<<result<<endl;
      return 0;
}