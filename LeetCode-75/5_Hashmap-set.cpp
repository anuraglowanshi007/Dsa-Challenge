// 2215. Find the Difference of Two Arrays
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<int> v1, v2;
        for(auto it: st1)
            if(st2.find(it) == st2.end()) 
                v1.push_back(it);
        for(auto it: st2)
            if(st1.find(it) == st1.end()) 
                v2.push_back(it);
        ans = {v1, v2};
        return ans;
    }


// 1657. Determine if Two Strings Are Close

  bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int>arr1(26,0);
        vector<int>arr2(26,0);

        if(m!=n){
            return false;
        }

        for(int i=0;i<n;i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            arr1[ch1-'a']++;
            arr2[ch2-'a']++;
            
        }

        for(int i=0;i<26;i++){
            if(arr1[i]!=0 && arr2[i]==0 || arr1[i]==0 && arr2[i]!=0){
                return false;
            }
        }

        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        for(int i=0;i<26;i++){
            if(arr1!=arr2){
                return false;
            }
        }
        return true;
    }

    

    // 1207. Unique Number of Occurrences
    
    bool uniqueOccurrences(vector<int>& arr) {
         //cnt frequncey in map
         //insert in set (because set doesnt duplicates allow)
         //compare size both 

        unordered_map<int,int>mp;
        // for(int i=0;i<arr.size();i++){
        //     mp[arr[i]]++;
        // }
        for(auto x:arr){
            mp[x]++;
        }

        unordered_set<int>st;
        for(auto x:mp){
            st.insert(x.second);
        }
        if(st.size()==mp.size()){
            return true;
        }
        else{
            return false;
        }  
    }

//  2352  Equal Row and Column Pairs
// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]

// Brute force 
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();  // Get the size of the grid (n x n)
        int cnt = 0;  // Initialize the counter for equal pairs
        
        // Loop over each row and each column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool isEqual = true;
                
                // Compare row i with column j
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] != grid[k][j]) {
                        isEqual = false;  // If any element doesn't match, mark as not equal
                        break;  // Break out of the loop as we already know the row and column are not equal
                    }
                }
                
                // If the row and column were equal, increment the counter
                if (isEqual==true) {
                    cnt++;
                }
            }
        }
        
        return cnt;  // Return the total count of equal pairs
    }

  // optimal approach 
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();  // Get the size of the grid
        map<vector<int>, int> mp;  // Map to store the frequency of rows
        int count = 0;  // Initialize the count of equal pairs

        // Store each row as a vector and count its frequency
        for (int row = 0; row < n; row++) {
            mp[grid[row]]++;
        }

        // Now, we need to compare each column with the rows stored in the map
        for (int col = 0; col < n; col++) {
            vector<int> temp;
            // Extract the column as a vector
            for (int row = 0; row < n; row++) {
                temp.push_back(grid[row][col]);
            }
            // Check if the column vector exists in the map
            if (mp.find(temp) != mp.end()) {
                count += mp[temp];  // If found, add the frequency to count
            }
        }

        return count;  // Return the total count of equal pairs
    }



