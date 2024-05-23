#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    // Store frequency of each character
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    // Push into vector
    vector<pair<char, int>> v;
    for (auto x : mp) {
        v.push_back({x.first, x.second});
    }

    // Sort vector using lambda function
    sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    // Construct the result string according to frequency
    string ans = "";
    for (auto x : v) {
        for (int i = 0; i < x.second; i++) {
            ans += x.first;
        }
    }

    return ans;
}

int main() {
    string s = "tree";
    cout << "Original string: " << s << endl;
    string sortedString = frequencySort(s);
    cout << "String sorted by frequency: " << sortedString << endl;
    return 0;
}
