# Counting Words with a Given Prefix

This document explains the concept and approach to counting the number of strings in an array that start with a given prefix.

## Intuition

The problem requires us to count strings that start with a given prefix. The straightforward approach is to check each string in the array and verify if it starts with the prefix by comparing characters from the beginning.

## Approach

1. Initialize a counter to keep track of strings with the given prefix.
2. For each word in the array:
   - First, check if the word's length is at least equal to the prefix length.
   - If yes, extract a substring from the word with the same length as the prefix.
   - Compare this substring with the prefix.
   - If they match, increment the counter.
3. Return the final count.

### Time Complexity

- **O(N * K)**: 
  - N is the number of words in the input array.
  - K is the length of the prefix.

## Example Code

```cpp
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLen = pref.length();
        for (string word : words) {
            if (word.length() >= prefLen) {
                if (word.substr(0, prefLen) == pref) {
                    count++;
                }
            }
        }
        return count;
    }
};