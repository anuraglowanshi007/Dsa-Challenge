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

