# Rabbits in Forest

This document explains the concept and approach to solving the problem "Rabbits in Forest".

## Problem Statement

In a forest, each rabbit has some color. Some rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Given an array `answers` where `answers[i]` is the number of other rabbits that have the same color as the `i`-th rabbit, return the minimum number of rabbits that could be in the forest.

## Approach

1. **Count Frequencies**:
   - Use a hashmap to count the frequency of each answer in the `answers` array.

2. **Calculate Minimum Rabbits**:
   - For each unique answer `x` in the hashmap:
     - If `x` rabbits report `x` other rabbits of the same color, then there are `x + 1` rabbits of that color.
     - Calculate the number of groups needed for each answer and add the total number of rabbits for those groups to the result.

### Example Code

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int answer : answers) {
            count[answer]++;
        }

        int result = 0;
        for (auto& [answer, freq] : count) {
            int groupSize = answer + 1;
            int groups = (freq + groupSize - 1) / groupSize; // ceil(freq / groupSize)
            result += groups * groupSize;
        }

        return result;
    }
};