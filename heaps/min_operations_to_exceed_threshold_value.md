# Minimum Operations to Exceed Threshold Value II

## Problem Statement

Given an array of integers and a threshold value, the task is to find the minimum number of operations required to make the sum of the array exceed the threshold value. Each operation consists of incrementing an element of the array by 1.

## Approach

1. **Calculate Initial Sum**:
   - Calculate the initial sum of the array.

2. **Check if Already Exceeds Threshold**:
   - If the initial sum already exceeds the threshold, return 0.

3. **Use a Min-Heap (Priority Queue)**:
   - Use a min-heap (priority queue) to keep track of the smallest elements in the array.

4. **Increment Elements**:
   - Increment the smallest elements in the heap until the sum exceeds the threshold.
   - Keep track of the number of operations performed.

5. **Return Result**:
   - Return the total number of operations performed.


## Example

Given the input array `[1, 2, 3]` and threshold `10`, the output will be `4` because we need to perform 4 operations to make the sum exceed 10.

## Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int ans = 0;

        for (long long num : nums) {
            pq.push(num);
        }

        while (pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push((min(x, y) * 2) + max(x, y));
            ans++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int threshold = 10;
    Solution sol;
    int result = sol.minOperations(nums, threshold);
    cout << "Minimum operations to exceed threshold: " << result << endl; // Output: 4

    return 0;
}