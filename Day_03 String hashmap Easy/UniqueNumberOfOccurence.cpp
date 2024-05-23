#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;

    // Count the frequency of each element
    for (auto x : arr) {
        mp[x]++;
    }

    // Insert frequencies into a set
    unordered_set<int> st;
    for (auto x : mp) {
        st.insert(x.second);
    }

    // Check if the size of the set equals the size of the map
    return st.size() == mp.size();
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << "Are the occurrences of each element unique? " << boolalpha << uniqueOccurrences(arr) << endl;
    return 0;
}
