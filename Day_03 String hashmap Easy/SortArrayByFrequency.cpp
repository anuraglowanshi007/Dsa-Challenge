#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> mp;

    // Count the frequency of each element
    for (auto x : nums) {
        mp[x]++;
    }

    // Sort the vector based on frequency using lambda function
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        return mp[a] != mp[b] ? mp[a] < mp[b] : a > b;
    });

    return nums;
}

int main() {
    vector<int> nums = {3, 3, 1, 1, 1, 8, 8, 8, 8, 4, 4, 6, 6, 6, 6};
    vector<int> sortedNums = frequencySort(nums);

    cout << "Sorted vector based on frequency: ";
    for (auto num : sortedNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
