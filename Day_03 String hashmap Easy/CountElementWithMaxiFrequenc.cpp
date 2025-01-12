#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    map<int, int> mp;

    // Count the frequency of each element
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    // Find the maximum frequency
    int maxi = INT_MIN;
    for (auto x : mp) {
        if (x.second > maxi) {
            maxi = x.second;
        }
    }

    // Sum up the frequencies of the elements that have the maximum frequency
    int ans = 0;
    for (auto i : mp) {
        if (maxi == i.second) {
            ans += i.second;
        }
    }

    return ans;

}

