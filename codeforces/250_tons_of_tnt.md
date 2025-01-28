# Codeforces: 250 Tons of TNT

This document explains the concept and approach to solving the Codeforces problem "250 Tons of TNT".

## Problem Statement

You are given an array of integers. Your task is to find the maximum possible difference between the sum of elements of any two groups of size `k` such that the array can be divided into groups of size `k`.

## Approach

1. **Input Reading**:
   - Read the number of test cases.
   - For each test case, read the size of the array `n` and the array elements.

2. **Iterate Over Possible Group Sizes**:
   - Iterate over all possible group sizes `k` from `1` to `n`.
   - For each group size `k`, check if `n` is divisible by `k`.

3. **Calculate Maximum and Minimum Group Sums**:
   - For each valid group size `k`, divide the array into groups of size `k`.
   - Calculate the sum of elements in each group.
   - Track the maximum and minimum sums of these groups.

4. **Calculate the Maximum Difference**:
   - For each valid group size `k`, calculate the difference between the maximum and minimum group sums.
   - Track the maximum of these differences across all valid group sizes.

5. **Output the Result**:
   - Print the maximum difference for each test case.

### Time Complexity

- **O(n^2)**: The time complexity is quadratic due to the nested loops for iterating over possible group sizes and calculating group sums.

### Space Complexity

- **O(1)**: The space complexity is constant as no additional space is used other than a few variables.

## Example Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Macros and constants
#define pb push_back
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
        ll ans = -1;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0) {
                ll maxx = LLONG_MIN;
                ll minn = LLONG_MAX;
                for (int i = 0; i < n; i += k) {
                    ll sum = 0;
                    for (int j = i; j < (k + i); j++) {
                        sum += v[j];
                    }
                    maxx = max(sum, maxx);
                    minn = min(sum, minn);
                }
                ans = max(ans, maxx - minn);
            }
        }
        cout << ans << endl;
    }
    return 0;
}