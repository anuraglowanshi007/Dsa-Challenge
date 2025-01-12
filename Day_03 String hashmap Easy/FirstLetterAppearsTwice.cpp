#include <iostream>
#include <string>
#include <unordered_map>
#include<bits/stdc++.h>


using namespace std;

char repeatedCharacter(string s) {
    // Create an unordered map to store the frequency of characters
    unordered_map<char, int> mp;
    
    // Iterate through the string
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++; // Increment the count for the character
        
        // If the count becomes 2, return the character
        if (mp[s[i]] == 2) {
            return s[i];
        }
    }
    
    return '\0'; // Return null character if no repeated character is found
}

int main() {
    string s = "abccbaacz";
    char result = repeatedCharacter(s);
    
    if (result != '\0') {
        cout << "The first character that appears twice is: " << result << endl;
    } else {
        cout << "No character appears twice in the string." << endl;
    }

    return 0;
}
