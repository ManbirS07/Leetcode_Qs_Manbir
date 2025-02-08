# LeetCode 703: Kth Largest Element in a Stream

This document explains the concept and approach to solving the LeetCode problem 703 "Kth Largest Element in a Stream".

## Problem Statement

Design a class to find the `k`-th largest element in a stream. Note that it is the `k`-th largest element in the sorted order, not the `k`-th distinct element.

Implement the `KthLargest` class:
- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Appends the integer `val` to the stream and returns the element representing the `k`-th largest element in the stream.

## Approach

1. **Use a Min-Heap**:
   - Use a min-heap (priority queue) to keep track of the `k` largest elements in the stream.
   - The root of the min-heap will always be the `k`-th largest element.

2. **Initialization**:
   - Initialize the min-heap with the first `k` elements of the stream. If there are fewer than `k` elements, initialize the heap with all elements.

3. **Add Method**:
   - When a new element is added to the stream, compare it with the root of the min-heap.
   - If the new element is larger than the root, replace the root with the new element and reheapify.
   - If the new element is smaller than or equal to the root, do nothing.
   - Return the root of the min-heap, which represents the `k`-th largest element.

### Example Code

```cpp
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;  // returns 4
    cout << kthLargest.add(5) << endl;  // returns 5
    cout << kthLargest.add(10) << endl; // returns 5
    cout << kthLargest.add(9) << endl;  // returns 8
    cout << kthLargest.add(4) << endl;  // returns 8

    return 0;
}