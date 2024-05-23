#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {  
    unordered_map<char, int> mp;

    // Store the frequency of each character in the string
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    // Find the first character with a frequency of 1
    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] == 1) {
            return i; // Return the index of the first unique character
        }
    }

    return -1; // If no unique character is found, return -1
}

int main() {
    string s = "loveleetcode";
    int index = firstUniqChar(s);
    
    if (index != -1) {
        cout << "The first unique character is at index: " << index << endl;
    } else {
        cout << "There is no unique character in the string." << endl;
    }

    return 0;
