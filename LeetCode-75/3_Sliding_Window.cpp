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

