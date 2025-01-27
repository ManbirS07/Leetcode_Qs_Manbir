# Maximizing Array Sum by Converting Negatives to Positives

This document explains the concept and approach to solving the problem of maximizing the sum of an array by converting some negative numbers to positive.

## Problem Statement

Given an array of integers, you need to maximize the sum of the array after converting some of the negative numbers to positive. If the count of negative numbers is odd, you need to make the sum as large as possible by flipping the sign of one more number.

## Approach

1. **Count Negative Numbers**:
   - Count the number of negative numbers in the array.

2. **Convert Negatives to Positives**:
   - Convert all negative numbers to positive and calculate the sum.

3. **Check Parity of Count**:
   - If the count of negative numbers is even, the sum is already maximized.
   - If the count of negative numbers is odd, you need to flip the sign of one more number to make the count even. To minimize the impact on the sum, you should flip the smallest positive number.

### Detailed Steps

1. **Input Reading**:
   - Read the number of elements in the array and the array itself.

2. **Count Negatives and Calculate Sum**:
   - Count the number of negative numbers and calculate the sum of the absolute values of the elements.

3. **Sort the Array**:
   - Sort the array to easily access the smallest element.

4. **Check Parity**:
   - If the count of negative numbers is even, print the sum.
   - If the count of negative numbers is odd, subtract `2 * arr[0]` from the sum. This is because flipping the smallest positive number (or the smallest absolute value) minimizes the reduction in the sum.

### Explanation of `2 * arr[0]`

- **Sum Calculation**: After converting all negative numbers to positive, the sum is the sum of all absolute values.
- **Odd Count Handling**: If the count of negative numbers is odd, we need to flip one more number to make the count even. To minimize the impact on the sum, we flip the smallest positive number (or the smallest absolute value).
- **Subtract `2 * arr[0]`**: Flipping the smallest positive number means subtracting `2 * arr[0]` from the sum because we are effectively changing its sign twice (once to positive and once back to negative).

This approach ensures that the sum is maximized even when the count of negative numbers is odd.

## Example Code

```cpp
#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define ll long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main() {
    fast

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        // Count negative numbers and calculate sum of absolute values
        int countNegatives = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                countNegatives++;
            }
            sum += abs(v[i]);
        }

        // Sort the array to access the smallest absolute value easily
        sort(v.begin(), v.end(), [](ll a, ll b) { return abs(a) < abs(b); });

        // If the count of negative numbers is odd, adjust the sum
        if (countNegatives % 2 != 0) {
            sum -= 2 * abs(v[0]);
        }

        cout << sum << endl;
    }
    return 0;
}