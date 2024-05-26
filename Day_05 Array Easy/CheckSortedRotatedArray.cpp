#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    
    // Check for decreases in the array
    for (int i = 1; i < n; i++) {
        if (nums[i-1] > nums[i]) {
            count++;
        }
    }
    
    // Check if the last element is greater than the first element
    if (nums[n-1] > nums[0]) {
        count++;
    }
    
    // The array is sorted and rotated if there is at most one decrease
    if(count == 1 || count == 0){
      return true;
    }
    
    return false;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    if (check(nums)) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is not sorted and rotated." << endl;
    }
    return 0;
}
