#include <iostream>
using namespace std;

int print2largest(int arr[], int n) {
    // Initialize the largest and second largest
    int maxi = arr[0];
    int Smaxi = -1;

    // Iterate over the array to find the largest and second largest elements
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxi) {
            Smaxi = maxi;
            maxi = arr[i];
        } else if(arr[i] > Smaxi && arr[i] != maxi) {
            Smaxi = arr[i];
        }
    }
    return Smaxi;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = print2largest(arr, n);
    if(result != -1)
        cout << "The second largest element is " << result << endl;
    else
        cout << "There is no second largest element" << endl;
    return 0;
}

// Time Complexity: O(N),
//  We do two linear traversals in our array
// Space Complexity: O(1)
