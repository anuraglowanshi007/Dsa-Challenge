#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(const vector<int>& arr, int n) {
    vector<int> rotatedArr(n); // Create a new vector for rotated array
    int temp = arr[0];
    for(int i = 1; i < n; i++) {
        rotatedArr[i-1] = arr[i];
    }
    rotatedArr[n-1] = temp;
    return rotatedArr; // Return the new rotated array
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    vector<int> rotatedArr = rotateArray(arr, n);
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Rotated Array: ";
    for (int num : rotatedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
