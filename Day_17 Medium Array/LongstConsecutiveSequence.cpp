#include<bits/stdc++.h>
using namespace std;

// IP - arr = [100, 4, 200, 1, 3, 2]:
int longsetConsecutiveSequence(vector<int> & arr){
      int n = arr.size();
      sort(arr.begin(),arr.end());

      int lastsmallest = INT_MAX;
      int longest = 1;
      int cnt = 0;

      for(int i=0;i<n;i++){
            if(arr[i]-1 == lastsmallest){
                  cnt++;
                  lastsmallest = arr[i];
            }
            else if(arr[i]!=lastsmallest){
                  cnt = 1;
                  lastsmallest = arr[i];
            }
            longest = max(longest,cnt);
      }
      return longest;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << "The length of the longest consecutive sequence is: " << longsetConsecutiveSequence(arr) << endl;
    
    return 0;
}
