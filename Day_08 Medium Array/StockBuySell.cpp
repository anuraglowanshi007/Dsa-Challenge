// Stock Buy And Sell 
// 01 Brute force 
// 02 optimal 


#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);

        // if (arr[i] < minPrice) {
        //     minPrice = arr[i]; // Update minimum price
        // }
        // int price = arr[i] - minPrice; // Calculate potential profit
        // if (price > maxPro) {
        //     maxPro = price; // Update maximum profit
        // }
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}


// #include<bits/stdc++.h>
// using namespace std;

// int maxProfit(vector<int> &arr) {
//     int maxPro = 0;
//     int n = arr.size();

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] > arr[i]) {
//             maxPro = max(arr[j] - arr[i], maxPro);
//             }
//         }
//         }

//     return maxPro;
// }

// int main() {
//     vector<int> arr = {7,1,5,3,6,4};
//     int maxPro = maxProfit(arr);
//     cout << "Max profit is: " << maxPro << endl;
// }

