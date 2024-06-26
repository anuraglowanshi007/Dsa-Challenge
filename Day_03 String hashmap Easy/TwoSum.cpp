#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // To store the number and its index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if the complement is already in the map
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; // Return the indices of the two numbers
        }
        
        // Add the current number and its index to the map
        num_map[nums[i]] = i;
    }

    return {}; // Return an empty vector if no solution is found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << " are: ";
        cout << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to " << target << endl;
    }

    return 0;
}
