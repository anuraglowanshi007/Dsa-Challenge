#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged; // Resultant merged array
    int i = 0, j = 0;   // Two pointers for the arrays

    // Traverse both arrays
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]); // Add the smaller element
            i++; // Move pointer for arr1
        } else {
            merged.push_back(arr2[j]); // Add the smaller element
            j++; // Move pointer for arr2
        }
    }

    // Append remaining elements of arr1 (if any)
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Append remaining elements of arr2 (if any)
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};

    vector<int> result = mergeSortedArrays(arr1, arr2);

    cout << "Merged Array: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
