//Count occurence of Anagrams 

// Function to check if all elements in the counter are zero
bool allzero(vector<int>& counter) {
    for (int &i : counter) {
        if (i != 0) {
            return false;
        }
    }
    return true;
}

// Function to search for anagram occurrences
int search(string pat, string txt) {
    vector<int> counter(26, 0);  // Frequency counter for characters 'a' to 'z'
    int n = txt.size();
    int k = pat.size();  // Length of the pattern
    int result = 0;      // Number of anagrams found
    
    // Initialize the counter with the frequency of the pattern's characters
    for (int i = 0; i < k; i++) {
        counter[pat[i] - 'a']++;
    }
    
    int i = 0, j = 0;
    
    while (j < n) {
        // Decrease the frequency count for the current character in the window
        counter[txt[j] - 'a']--;
        
        // When the window size matches the pattern size
        if (j - i + 1 == k) {
            // Check if all counts are zero (indicating an anagram)
            if (allzero(counter)) {
                result++;
            }
            
            // Slide the window: increment the count of the character at index i and move i forward
            counter[txt[i] - 'a']++;
            i++;
        }
        
        // Move the window forward by increasing j
        j++;
    }
    
    return result;
}

int main() {
    string pat, txt;
    
    cout << "Enter the pattern: ";
    cin >> pat;
    
    cout << "Enter the text: ";
    cin >> txt;
    
    int result = search(pat, txt);
    cout << "Number of anagram occurrences: " << result << endl;
    
    return 0;
}


// Find All Anagrams in a String


     bool allzero(vector<int>&counter){
        for(int &i : counter){
            if(i!=0){
                return false;
            }
        }
        return true;

     }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>counter(26,0);
        int n = s.size();
        int k = p.size();

        // store the char freq count 
        for(int i=0;i<p.size();i++){
            counter[p[i]-'a']++;
        }

        int i=0;
        int j=0;
        vector<int>result;
        while(j<n){
            
            // decrement count 
            counter[s[j]-'a']--;

            if(j-i+1==k){
                if(allzero(counter)){
                    result.push_back(i);
                }
                // increment count freq
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }


// 643. Maximum Average Subarray I
    class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans =0;
        double sum = 0;

        // calculate the sum of first k ele
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        ans = sum;

        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            ans = max(ans,sum);
        }
        return ans/k;
    }
};

//1004. Max Consecutive Ones III
// Brute force 

int longestOnes(vector<int>& nums, int k) {
        int len =0;
        int maxLen = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int zero =0;
            for(int j=i;j<n;j++){

                if(nums[j]==0){
                    zero++;
                }
                if(zero <= k){
                len = j-i+1;
                maxLen = max(maxLen,len);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }


    // Sliding Window approach 
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n = nums.size();
        int len = 0;
        int maxlen = 0;
        int zero =0;

        while(j<n){
            if(nums[j]==0){
                zero++;
            }

            if(zero<=k){
                len = j-i+1;
                maxlen = max(maxlen,len);
            }
            else{
                if(nums[i]==0){
                    zero--;   
                }
                i++;
            }
            
            j++;
        }
        return maxlen;
    }


// 1493. Longest Subarray of 1's After Deleting One Element

// Brute force 
    int findMax(vector<int>& nums, int skip_idx) {
        int currentLength = 0;
        int maxLength = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == skip_idx) {
                continue;
            }
            if (nums[i] == 1) {
                currentLength++;
                maxLength = max(currentLength, maxLength);
            } else {
                currentLength = 0;
            }
        }
        return maxLength;
    }
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        int zerocount =0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zerocount++;
                result = max(result, findMax(nums, i));
            }
            if(zerocount==0){
                return n-1;
            }
        }
        return result;
    }

// Sliding window 

    int longestSubarray(vector<int>& nums) {
        int i = 0;                // Left pointer for the sliding window
        int j = 0;                // Right pointer for the sliding window
        int maxLen = 0;           // To store the maximum length of the subarray
        int zerocount = 0;        // To track the number of zeros in the current window
        int n = nums.size();      // Size of the input array
        int len = 0;              // To track the current window length

        // Traverse the array with the right pointer `j`
        while (j < n) {
            // If a zero is encountered, increase the zero count
            if (nums[j] == 0) {
                zerocount++;
            }

            // If there is at most one zero in the window, calculate the length
            if (zerocount <= 1) {
                len = j - i;       // The length of the window is j - i
                maxLen = max(maxLen, len); // Update the max length if current window is larger
            } 
            // If there are more than one zero in the window, shrink it from the left
            else {
                // If the element at the left pointer is zero, reduce the zero count
                if (nums[i] == 0) {
                    zerocount--;
                }
                i++;               // Move the left pointer to the right to shrink the window
            }
            j++;                   // Move the right pointer to expand the window
        }
        
        return maxLen;             // Return the maximum length of the subarray found
    }

//Maximum of all Subarray of size k 

// Brute Force 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int maxi;
    vector<int>ans;
    int n = nums.size();
    for(int i=0;i<=n-k;i++){
        maxi = nums[i];
        for(int j=i;j<i+k;j++){
            maxi = max(maxi,nums[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
        
    }

// sliding window approach 

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     deque<int> q;  // Deque to store the indices of the elements
    int i = 0, j = 0;  // i and j are the window pointers
    vector<int> res;  // Result vector to store the maximum of each window
    int n = nums.size();

    while (j < n) {
        // Maintain the deque such that elements in q are in descending order
        // Remove elements from the back of the deque if they are smaller than arr[j]
        while (!q.empty() && q.back() < nums[j]){
         q.pop_back();
        }
        q.push_back(nums[j]);  // Add current element to the deque

        // If the current window size is less than k, just increment j
        if (j - i + 1 < k) 
        j++;
        
        // When the window size is exactly k
        else if (j - i + 1 == k) {
            // The front of the deque is the largest element of the current window
            res.push_back(q.front());
            
            // Remove the element from the front if it is the one that is sliding out of the window
            if (q.front() == nums[i])
             q.pop_front();
            
            // Slide the window
            i++;
            j++;
        }
    }
    return res;  // Return the result containing the maximum of each window
}


    
//  Maximum Sum of Distinct Subarrays With Length K
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> distinctElements;  // To store distinct elements
        long long sum = 0;                   // To store current sum
        long long maxi = 0;                  // To store the maximum sum of distinct subarrays
        int i = 0, j = 0;                    // Sliding window pointers
        int n = nums.size();

        while (j < n) {

            while (distinctElements.find(nums[j]) != distinctElements.end()) {
                sum -= nums[i];  // Remove the leftmost element from sum
                distinctElements.erase(nums[i]);  // Remove the leftmost element from the set
                i++;  // Slide the window from the left
            }
            // Add nums[j] to the sum and distinct set
            
            sum += nums[j];
            distinctElements.insert(nums[j]);

            // If the size of the distinct set is less than the window size k,
            // we haven't reached a valid subarray yet.
            if (j - i + 1 < k) {
                j++;
            }
            // When the window size is exactly k
            else if (j - i + 1 == k) {
                // Check if all elements are distinct (i.e., size of set is k)
                if (distinctElements.size() == k) {
                    maxi = max(maxi, sum);
                }
                
                // Now, slide the window
                sum -= nums[i];  // Remove the leftmost element from sum
                distinctElements.erase(nums[i]);  // Remove the leftmost element from the set
                i++;  // Slide the window from the left
                j++;  // Move the right pointer forward
            }
        }
        return maxi;
    }


    // Count the no. of subarray sum equal K
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;               // Left pointer
        int j = 0;               // Right pointer
        long long sum = 0;       // Running sum
        int cnt = 0;             // Count of subarrays with sum equal to k
        int n = nums.size();     // Size of the input array

        while (j < n) {
            sum += nums[j];  // Add the current element to the sum

            // Shrink the window while sum exceeds k
            while (sum > k && i <= j) {
                sum -= nums[i];  // Remove the element at the left boundary
                i++;
            }

            // If the sum is exactly equal to k, increment the count
            if (sum == k) {
                cnt++;
            }

            // Move the right pointer to expand the window
            j++;
        }

        return cnt;
    }


    // Longest/ Largest subarray Sum k 
    int Longest_subarraySum(vector<int>& nums, int k) {
        int i = 0;               // Left pointer
        int j = 0;               // Right pointer
        long long sum = 0;       // Running sum
        int maxi = 0;             
        int n = nums.size();     // Size of the input array

        while (j < n) {
            sum += nums[j];  // Add the current element to the sum

            // Shrink the window while sum exceeds k
            while (sum > k && i <= j) {
                sum -= nums[i];  // Remove the element at the left boundary
                i++;
            }

            // If the sum is exactly equal to k, 
            if (sum == k) {
                maxi = max(maxi,j-i+1);
            }

            // Move the right pointer to expand the window
            j++;
        }

        return maxi;
    }


// Longest K unique characters substring

class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> freqMap;  // To store the frequency of characters in the window
        int i = 0;                        // Left pointer
        int j = 0;                        // Right pointer
        int maxi = -1;                    // To store the maximum length of substring with k unique characters
        int n = s.size();                 // Size of the input string

        // Traverse the string with the right pointer
        while (j < n) {
            freqMap[s[j]]++;  // Add the character s[j] to the frequency map

            // If the number of unique characters is less than k, expand the window by moving j
            if (freqMap.size() < k) {
                j++;
            }
            // If the number of unique characters is exactly k, calculate the maximum length
            else if (freqMap.size() == k) {
                maxi = max(maxi, j - i + 1);  // Update the maximum length
                j++;
            }
            // If the number of unique characters exceeds k, shrink the window by moving i
            else {
                while (freqMap.size() > k) {
                    freqMap[s[i]]--;  // Reduce the frequency of the character at the left pointer
                    if (freqMap[s[i]] == 0) {
                        freqMap.erase(s[i]);  // Remove the character from the map if its count becomes 0
                    }
                    i++;  // Shrink the window from the left
                }
                j++;
            }
        }

        return maxi;  // Return the maximum length, or -1 if no valid substring is found
    }
};


// 3. Longest Substring Without Repeating Characters


    int lengthOfLongestSubstring(string s) {
        int i = 0;  // Left pointer
        int j = 0;  // Right pointer
        int maxLen = 0;  // Maximum length of the substring
        int n = s.size();  // Size of the input string
        unordered_map<char, int> mp;  // To store the frequency of characters in the window

        // Traverse the string with the right pointer
        while (j < n) {
            mp[s[j]]++;  // Increment the frequency of the character at the right pointer

            // If there are no repeating characters (map size matches the window size)
            if (mp.size() == j - i + 1) {
                maxLen = max(maxLen, j - i + 1);  // Update the maximum length
                j++;  // Move the right pointer to expand the window
            }
            // If there are repeating characters (map size is smaller than the window size)
            else if (mp.size() < j - i + 1) {
                while (mp.size() < j - i + 1) {  // Shrink the window until no repeating characters
                    mp[s[i]]--;  // Decrease the frequency of the character at the left pointer
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);  // Remove the character from the map if its count is zero
                    }
                    i++;  // Move the left pointer to shrink the window
                }
                j++;  // Move the right pointer after shrinking the window
            }
        }

        return maxLen;  // Return the maximum length of the substring
    }

// Count the nice Subarray which is odd element in k size window 
function countNiceSubarrays(nums, k) {
    let count = 0;
    
    // Iterate through all possible starting points of subarrays
    for (let i = 0; i < nums.length; i++) {
        let oddCount = 0;
        
        // Generate all subarrays starting at i
        for (let j = i; j < nums.length; j++) {
            // If the current element is odd, increment oddCount
            if (nums[j] % 2 !== 0) {
                oddCount++;
            }
            
            // If we have exactly k odd numbers, increment the result count
            if (oddCount === k) {
                count++;
            }
        }
    }
    
    return count;
}

// using slding window  
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count =0;
        int oddcount = 0;
        int result = 0;
        int n =nums.size();
        
        while(j<n){

            if(nums[j]%2!=0){
                oddcount ++;
                count =0;
            }

            while(oddcount==k){
                count++;

                if(nums[i]%2==1){
                    oddcount--;
                }
                i++;
            }
            result+= count;
            j++;
        }
        return result;
    }
};



// 904. Fruit Into Baskets
//Brute force 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int maxLen  = 0;
       int n = fruits.size();

        for(int i=0;i<n;i++){
             unordered_set<int>st;
             for(int j=i;j<n;j++){
                st.insert(fruits[j]);
                
                if(st.size()<=2){
                    maxLen = max(maxLen,j-i+1);
                }
                else {
                    break;
                }
             }
        }
        return maxLen;
    }
};

// Sldiing Window approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int maxLen = 0;
        int n = fruits.size();
        unordered_map<int, int> mp;

        if (fruits.size() <= 2) {
            return fruits.size();
        }

        while (j < n) {
            mp[fruits[j]]++;
            
            while (mp.size() > 2) {
                mp[fruits[i]]--; // reduce the count of the fruit at the left
                                 // pointer
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]); // remove the fruit if its count
                                         // becomes zero
                }
                i++; // move the left pointer
            }

            // Calculate the length of the current window and update maxLen
            maxLen = max(maxLen, j - i + 1);
            j++; // move the right pointer
        }
        return maxLen;
    }
};


// Maximum Length Substring With Two Occurrences

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        int n = s.size();
        int maxLen = 0;

        for (int j = 0; j < n; j++) {
            mp[s[j]]++;

            while(mp[s[j]] > 2) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};

// 992. Subarrays with K Different Integers

//Brute Force
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int cnt =0;
        int n = nums.size();

        for(int i=0;i<n;i++){
              unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;

                if(mp.size()==k)
                cnt++;
                else if(mp.size()>k)
                break;
            }
        }
        return cnt;
    }
};

// sliding window approach 