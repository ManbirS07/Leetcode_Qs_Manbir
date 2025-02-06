#include <bits/stdc++.h>
using namespace std;

vector<int> pancakeSort(vector<int>& arr) {
    vector<int> result;
    int n = arr.size();

    for (int size = n; size > 1; --size) {
        // Find the index of the maximum element in arr[0..size-1]
        int maxIndex = max_element(arr.begin(), arr.begin() + size) - arr.begin();

        // If the maximum element is not already at the end of the current array
        if (maxIndex != size - 1) {
            // Flip the maximum element to the front if it's not already there
            if (maxIndex != 0) {
                result.push_back(maxIndex + 1);
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
            }
            // Flip it to its correct position
            result.push_back(size);
            reverse(arr.begin(), arr.begin() + size);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {3, 2, 4, 1};
    vector<int> result = pancakeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Flip sequence: ";
    for (int flip : result) {
        cout << flip << " ";
    }
    cout << endl;

    return 0;
}