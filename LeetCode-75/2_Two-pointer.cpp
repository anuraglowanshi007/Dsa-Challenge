// 283. Move Zeroes

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero=0;
    for(int j=0;j<nums.size();j++){
        if(nums[j]!=0){
            swap(nums[j],nums[nonzero]);
            nonzero++;
        }
    }
   
 }



// 392. Is Subsequence
// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        for(int i=0;i<t.length() ;i++){
                if(t[i]==s[cnt]){
                    cnt++;
                }
        } 
        return cnt == s.length() ? true : false;
        
    }
};


// Container With Most Water

//Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
//  In this case, the max area of water (blue section) the container can contain is 49.

 class Solution {
public:
    int maxArea(vector<int>& height) {

        //Two ptr
        //find the width 
        // min height 
        // min height*width
        // max area 
        int i=0;
        int j = height.size()-1;
        int ans = 0;

        while(i<j){
           
             ans = max(ans, (j-i)*min(height[i],height[j]));
             if(height[i]<height[j]){
                i++;
            }
            else{ 
                j--;
            }
        }

        return ans;
        
    }
};


// 1679. Max Number of K-Sum Pairs

// Input: nums = [1,2,3,4], k = 5
// Output: 2
// Explanation: Starting with nums = [1,2,3,4]:
// - Remove numbers 1 and 4, then nums = [2,3]
// - Remove numbers 2 and 3, then nums = []
// There are no more pairs that sum up to 5, hence a total of 2 operations.


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        int cnt = 0;
        while(s<e){
            if(nums[s]+nums[e]==k){
               cnt++;
               s++;
               e--;
              
            }
            else if(nums[s]+nums[e]<k){
                s++;
            }else{
                e--;
            }
        }
        return cnt;
    }
};

