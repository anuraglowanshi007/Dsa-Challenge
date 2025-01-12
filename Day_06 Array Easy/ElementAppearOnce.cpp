#include <bits/stdc++.h>
using namespace std;

int getSingleElement(int arr[],int n) {

    //size of the array:
    

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

int main()
{
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = getSingleElement(arr,n);

    cout << "The single element is: " << ans << endl;
    return 0;
}