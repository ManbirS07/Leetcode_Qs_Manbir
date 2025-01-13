## Problem
You are given a string s. You can perform the following operation repeatedly:

Choose an index i such that there is at least one identical character to the left and right of s[i].
Remove the closest identical characters on both sides of s[i].
The task is to return the minimum length of the string after all possible operations.

## Intuition
The problem boils down to efficiently handling characters' frequencies:

Characters with even frequencies: These can be fully removed in pairs.
Characters with odd frequencies ≥ 3: We remove pairs until one remains.
We don’t need to simulate the operations, just analyze how much of the string is left after applying these rules.

## Approach 1
class Solution {
public:
    int minimumLength(string s) {
        vector<int> charFrequency(26, 0);
        int totalLength = 0;
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }
        for (int frequency : charFrequency) 
        {
            if (frequency == 0) continue;
            if (frequency % 2 == 0) {
                totalLength += 2;
            } else {
                totalLength += 1;
            }
        }
        return totalLength;
    }
};

## Key Idea
Track each character's frequency:

For even frequencies, characters can be removed in pairs.
For odd frequencies, one character remains.
### Time Complexity

Time: O(n) for counting characters.

### Space Complexity
Space: O(1) (constant space for 26 English letters).

## Approach: 2 Pair Reduction
Count character frequencies.
For each frequency ≥ 3, reduce pairs (-2) iteratively until the frequency is < 3.

### Example Code
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        unordered_map<int,int> mp;
       for(char c:s) mp[c]++;
        for(auto &it:mp)
        {
            while(it.second>2)
                {
                    it.second-=2;
                    n-=2;
                }   
        }
        return n;
    }
};

## Key Idea:
For each character:

Subtract 2 for every removable pair until no more pairs can be removed.
### Time Complexity

Time: **O(n)** for counting + constant pair reductions.

### Space Complexity
Space:  O(k), where k is the number of unique characters in the string. This is because the unordered_map stores the frequency of each unique character. In the worst case, if all characters in the string are unique, the space complexity would be O(n),.