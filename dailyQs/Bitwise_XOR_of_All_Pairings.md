# Bitwise XOR of All Pairings

This document explains the concept and approach to finding the bitwise XOR of all pairings between two arrays.

## Problem Statement

Given two arrays `nums1` and `nums2`, find the bitwise XOR of all pairings between elements of `nums1` and `nums2`. A pairing consists of one element from `nums1` and one element from `nums2`.

## Intuition

To solve the problem efficiently, we need to analyze the XOR operation properties and leverage mathematical patterns. Specifically:

- XOR is commutative and associative, meaning the order of operations doesn't matter.
- Any number XORed with itself results in 0.
- For every even occurrence, the XOR cancels out (e.g., \( x \oplus x = 0 \)).

Given these properties, the XOR of all pairings can be simplified:

- If the length of one array is even, all XOR contributions from that array cancel out.
- If the length is odd, only the XOR of the elements of the other array matters.

## Approach

### Detailed Explanation

1. Calculate the XOR of all elements in `nums1` (`x1`) and `nums2` (`x2`).
2. Check the lengths of `nums1` and `nums2`:
   - If the length of `nums1` is odd, the XOR of `nums2` contributes to the result.
   - If the length of `nums2` is odd, the XOR of `nums1` contributes to the result.
3. Return the combined result of these XOR operations.

This approach ensures we don't explicitly compute all pairings, keeping the solution efficient.

### Complexity

- **Time Complexity**: \( O(n + m) \), where \( n \) and \( m \) are the lengths of `nums1` and `nums2`. We calculate the XOR for both arrays individually.
- **Space Complexity**: \( O(1) \), as we use only constant extra space.

## Example Code

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1 = 0, x2 = 0;
        for (int num : nums1) x1 ^= num;
        for (int num : nums2) x2 ^= num;

        int result = 0;
        if (nums1.size() % 2 != 0) result ^= x2;
        if (nums2.size() % 2 != 0) result ^= x1;

        return result;
    }
};