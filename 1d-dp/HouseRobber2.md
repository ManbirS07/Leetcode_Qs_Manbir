## House Robber II

### Problem Statement

You are given an integer array `nums` representing the amount of money at each house arranged in a circle. Return the maximum amount of money you can rob tonight without alerting the police (cannot rob adjacent houses, and the first and last houses are also adjacent).

### Approach

- Since the first and last houses are adjacent, you cannot rob both.
- Consider two cases:
  1. Exclude the last house and solve for houses `[0, n-2]`.
  2. Exclude the first house and solve for houses `[1, n-1]`.
- Use a helper function with optimized space to solve each case.
- The answer is the maximum of the two cases.

### Time Complexity

- **O(n)**

### Space Complexity

- **O(1)** (using variables instead of a DP array)

### Example Code

```cpp
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int last = robRange(nums, 0, n - 2); //Exclude last house
        int first = robRange(nums, 1, n - 1);  // Exclude first house
        return max(last, first);
    }
};