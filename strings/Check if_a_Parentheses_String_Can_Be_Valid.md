# Check if a Parentheses String Can Be Valid

This document explains the concept and approach to determining if a given parentheses string can be valid based on the locked status of each character.

## Problem Statement

Given a string `s` containing only the characters '(' and ')', and a string `locked` containing only the characters '0' and '1', determine if the parentheses string can be valid. A valid parentheses string is one where every opening parenthesis '(' has a corresponding closing parenthesis ')'.

- `locked[i] == '1'` means the character `s[i]` cannot be changed.
- `locked[i] == '0'` means the character `s[i]` can be changed to either '(' or ')'.

## Approach

1. **Initial Check**:
   - If the length of the string `s` is odd, it cannot be valid, so return `false`.

2. **Use Stacks**:
   - Use two stacks: `open` to store indices of locked '(' characters, and `openClose` to store indices of unlocked characters.

3. **Traverse the String**:
   - For each character in the string:
     - If the character is unlocked (`locked[i] == '0'`), push its index to `openClose`.
     - If the character is a locked '(', push its index to `open`.
     - If the character is a locked ')':
       - If there is a corresponding '(' in the `open` stack, pop from `open`.
       - Otherwise, if there is an unlocked character in the `openClose` stack, pop from `openClose`.
       - If neither stack has a corresponding character, return `false`.

4. **Final Check**:
   - After traversing the string, ensure that all remaining '(' characters in the `open` stack can be matched with unlocked characters in the `openClose` stack.
   - If all `open` characters can be matched, return `true`; otherwise, return `false`.

## Example Code

```cpp
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if (n % 2 != 0) { // odd length
            return false;
        }

        stack<int> open;
        stack<int> openClose;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                openClose.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else if (!openClose.empty()) {
                    openClose.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.empty() && !openClose.empty() && open.top() < openClose.top()) {
            open.pop();
            openClose.pop();
        }

        return open.empty(); // true if all open parentheses are matched
    }
};

Dry Run Example
Consider the following example:

s = "())("
locked = "0101"
Steps
Initial check: Length is 4 (even), proceed.

Traverse the string:

i = 0: s[0] = '(', locked[0] = '0', push 0 to openClose.
i = 1: s[1] = ')', locked[1] = '1', no matching ( in open, pop from openClose.
i = 2: s[2] = ')', locked[2] = '0', push 2 to openClose.
i = 3: s[3] = '(', locked[3] = '1', push 3 to open.
Final check:

open contains index 3.
openClose contains index 2.
Match open and openClose, both stacks are empty.
Result
The string can be valid, so the function returns true.