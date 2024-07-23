class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int gola_index = -1;
        int n = nums.size();
        
        // Finding gola_index (the first number from the end that is smaller than the next)
        for(int i = n-1; i > 0; i--) {
            if(nums[i-1] < nums[i]) {
                gola_index = i-1;
                break; 
            }
        }
        
        if(gola_index != -1) { // If a valid gola_index is found
            int swap_index = gola_index;
            // Finding the swap_index (the first number larger than nums[gola_index] from the end)
            for(int j = n-1; j >= gola_index + 1; j--) {
                if(nums[j] > nums[gola_index]) {
                    swap_index = j;
                    break; 
                }
            }
            // Swap the values at gola_index and swap_index
            swap(nums[gola_index], nums[swap_index]);
            // Reverse the sub-array from gola_index + 1 to the end
            reverse(nums.begin() + gola_index + 1, nums.end());
        } else {
            // If no valid gola_index is found, reverse the entire array
            reverse(nums.begin(), nums.end()); // Missing in your code
        }
    }
};
