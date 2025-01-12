#include <iostream>
#include <vector>
#include <algorithm> // for the swap function

using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonzero = 0;
    for(int j = 0; j < nums.size(); j++) {
        if(nums[j] != 0) {
            // swap(nums[j], nums[nonzero]);
            int temp = nums[j];
            nums[j] = nums[nonzero];
            nums[nonzero] = temp;
            nonzero++;
        }
    }
}

int main() {
    // Example usage
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    
    cout << "Array after moving zeroes: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

// t/c - 0(n)
// s/c - 0(1)





// #include <bits/stdc++.h>
// using namespace std;

// vector<int> moveZeros(int n, vector<int> a) {
//     //temporary array:
//     vector<int> temp;
//     //copy non-zero elements
//     //from original -> temp array:
//     for (int i = 0; i < n; i++) {
//         if (a[i] != 0)
//             temp.push_back(a[i]);
//     }

//     // number of non-zero elements.
//     int nz = temp.size();

//     //copy elements from temp
//     //fill first nz fields of
//     //original array:
//     for (int i = 0; i < nz; i++) {
//         a[i] = temp[i];
//     }

//     //fill rest of the cells with 0:
//     for (int i = nz; i < n; i++) {
//         a[i] = 0;
//     }
//     return a;
// }


// int main()
// {
//     vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
//     int n = 10;
//     vector<int> ans = moveZeros(n, arr);
//     for (auto &it : ans) {
//         cout << it << " ";
//     }
//     cout << '\n';
//     return 0;
// }


