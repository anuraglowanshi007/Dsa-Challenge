//1732. Find the Highest Altitude


// Example 1:

// Input: gain = [-5,1,5,0,-7]
// Output: 1
// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
// Example 2:

// Input: gain = [-4,-3,-2,-1,4,3,2]
// Output: 0
// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.


    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;

        for(int i=0;i<gain.size();i++){
            currentAltitude+=gain[i];
            if(maxAltitude<currentAltitude){
            maxAltitude = currentAltitude;
            }
                
        }
        return maxAltitude;
    }

    

// 724. Find Pivot Index  

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

 int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int leftSum = 0;
        
        for(int i=0;i<n;i++){
            totalSum +=nums[i];
        }
        for(int i=0;i<n;i++){
            int rightSum = totalSum - nums[i]-leftSum;

            if(leftSum == rightSum){
                return i;
            }
            else{
                leftSum +=nums[i];
            }
        }
        return -1;

