# Luke is a Foodie

This document explains the concept and approach to solving the "Luke is a Foodie" problem.

## Problem Statement

Given an array of integers, you need to find the minimum number of changes required to make all segments of the array overlap within a given range. Each element in the array can be adjusted by a value `x` either positively or negatively.

## Approach

1. **Input Reading**:
   - Read the number of elements `n` and the adjustment value `x`.
   - Read the array elements.

2. **Initialization**:
   - Initialize the number of changes to `0`.
   - Initialize the previous segment range as `[arr[0] - x, arr[0] + x]`.

3. **Iterate Through the Array**:
   - For each element in the array, calculate the current segment range as `[arr[i] - x, arr[i] + x]`.
   - Calculate the overlap between the previous segment range and the current segment range.
   - If there is no overlap, increment the number of changes and update the previous segment range to the current segment range.
   - If there is an overlap, update the previous segment range to the overlap range.

4. **Output**:
   - Print the number of changes required.

### Example Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define vll vector<ll>
#define nl "\n"

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int changes = 0;
    vll prev = {arr[0] - x, arr[0] + x};
    for (int i = 1; i < n; i++) {
        vll cur = {arr[i] - x, arr[i] + x};
        vll overlap = {max(prev[0], cur[0]), min(prev[1], cur[1])};
        // if there is no overlap
        if (overlap[0] > overlap[1]) {
            changes++;
            prev = cur;
        } else {
            prev = overlap;
        }
    }
    cout << changes << nl;
}