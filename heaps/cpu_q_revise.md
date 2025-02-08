Lovely ka bhi lovely Q
# LeetCode 1353: Maximum Number of Events That Can Be Attended

This document explains the concept and approach to solving the LeetCode problem 1353 "Maximum Number of Events That Can Be Attended".

## Problem Statement

You are given an array of `events` where `events[i] = [startDayi, endDayi]`. Every event `i` starts at `startDayi` and ends at `endDayi`.

You can attend an event `i` at any day `d` where `startDayi <= d <= endDayi`. You can only attend one event at any day `d`.

Return the maximum number of events you can attend.

## Approach

1. **Sort Events**:
   - Sort the events based on their start day. If two events have the same start day, sort them by their end day.

2. **Use a Min-Heap**:
   - Use a min-heap to keep track of the end days of the events that can be attended on the current day.

3. **Iterate Through Days**:
   - Iterate through each day from the earliest start day to the latest end day.
   - For each day, add all events that start on that day to the min-heap.
   - Remove events from the min-heap that have already ended.
   - Attend the event that ends the earliest (i.e., the top of the min-heap) and remove it from the heap.

4. **Count Attended Events**:
   - Keep a counter to count the number of events attended.

### Example Code

```cpp
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int maxEvents = 0;
        int day = 0;
        int i = 0;
        int n = events.size();

        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }
            minHeap.pop();
            maxEvents++;
            day++;
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        return maxEvents;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    int result = solution.maxEvents(events);

    cout << "Maximum number of events that can be attended: " << result << endl;

    return 0;
}