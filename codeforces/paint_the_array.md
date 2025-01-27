# Paint the Array

This document explains the concept and approach to solving the Codeforces problem "Paint the Array".

I was inclined towards finding LCM duh!!!

## Problem Statement

You are given an array of integers. Your task is to find the greatest common divisor (GCD) of the elements at even indices and the GCD of the elements at odd indices. Then, determine if one of these GCDs can be used to paint the array such that no element at an even index is divisible by the GCD of the odd indices and no element at an odd index is divisible by the GCD of the even indices.

## Approach

1. **Calculate GCDs**:
   - Calculate the GCD of the elements at even indices (`gcde`).
   Because the gcd would be such that it would divide every element at even indexes so it can be the d for the even indexed elements, same for odd indexed ones
   - Calculate the GCD of the elements at odd indices (`gcdo`).

2. **Check Validity**:
   - Check if `gcde` can be used to paint the array such that no element at an odd index is divisible by `gcde`.
   - Check if `gcdo` can be used to paint the array such that no element at an even index is divisible by `gcdo`.

3. **Output Result**:
   - If `gcde` is valid, print `gcde`.
   - If `gcdo` is valid, print `gcdo`.
   - If neither is valid, print `0`.

### Time Complexity

- **O(n log n)**: The time complexity is dominated by the GCD calculations, which are logarithmic in nature.

### Space Complexity

- **O(1)**: The space complexity is constant as no additional space is used other than a few variables.

## Example Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Macros and constants
#define pb push_back
#define endl ("\n")
#define ll long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Aliases and Types
using vec = vector<int>;
using pii = pair<int, int>;
using mapi = map<int, int>;
using si = set<int>;

const int mod = 1e9 + 7;

int32_t main() {
    fast

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        ll gcde = 0, gcdo = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i % 2 == 0) gcde = __gcd(gcde, v[i]);
            else gcdo = __gcd(gcdo, v[i]);
        }
        bool flag = true; // flag to check if gcde is valid
        bool cnt = true;  // cnt to check if gcdo is valid
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && v[i] % gcdo == 0) cnt = false;
            if (i % 2 != 0 && v[i] % gcde == 0) flag = false;
        }
        if (flag) {
            cout << gcde << endl;
        } else if (cnt) {
            cout << gcdo << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}