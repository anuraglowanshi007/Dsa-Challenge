// 1768. Merge Strings Alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i =0;
        int j=0;
        string ans;
        while(i<word1.size()&& j<word2.size()){
            ans+=word1[i];
           ans+=word2[j];
            i++;
            j++;
        }
        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
}; 



// 1071. Greatest Common Divisor of Strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};

// 1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         vector<bool>ans;
        int maxi ;
        int k;

        for(int i=0;i<candies.size();i++){
            maxi = candies[i]+extraCandies;
             
             k = maxi;
            for(int i=0;i<candies.size();i++){
                k = max(candies[i],k);   
            }
            if(k==maxi)
            ans.push_back(true);

            else{
                ans.push_back(false);
            }
        }
        return ans;

    }
};

// another approach 

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxCandies = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxCandies)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};



// 605. Can Place Flowers

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        if(n==0) return true;

        for(int i=0;i<l;i++){
            if(flowerbed[i]==0){
                bool left_khali =  (i==0)||(flowerbed[i-1]==0);
                bool right_khali = ( i==l-1) || (flowerbed[i+1]==0 );

                if(left_khali && right_khali){
                    flowerbed[i]=1;
                    n--;
                }
                if(n==0){
                    return true;
                }
            }
        }
        return false;
    }
};


//345. Reverse Vowels of a String
// Example 1:
// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"

class Solution {
public:
    string reverseVowels(string s) {
        //two pointer
        //check the vowel 
        //not present moves 
        //present swap
       int start = 0;
       int end  = s.size()-1;
       while(start<end){
           if(!isVowel(s[start])){ 
               start++;
           }
           if(!isVowel(s[end])) {
               end--;
               }
           if(isVowel(s[start])&&isVowel(s[end])){
               swap(s[start++],s[end--]);
           }
       }
           return s;
    }
       
       bool isVowel(char x){
        return x=='a' || x=='e'|| x=='i'||x=='o'||x=='u'||x=='A' || x=='E'||x=='I'||
        x=='O'||x=='U';  
        
    }
};


// 334. Increasing Triplet Subsequence

// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.
// Example 2:

// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=first){
                first = nums[i];
            }
            else if(nums[i]<=second){
                second = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};


// String Compression

// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
// Example 2:

// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.


class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n = chars.size();
        int index = 0; 

        while(i<n){
            char curr_char = chars[i];
            int cnt = 0;

            // if duplicates find and stores count 
            while(i<n && chars[i] == curr_char){
                cnt++;
                i++;
            }

            chars[index] = curr_char;
            index++;

            if(cnt>1){
                    string count_str = to_string(cnt);
                    for(char &ch : count_str){
                        chars[index] = ch;
                        index++;
                    }
            }
        }
        return index;

    }
};


