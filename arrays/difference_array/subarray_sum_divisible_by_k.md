Step-by-Step Thought Process
Cumulative Sum 🏃‍♂️

As you traverse through the array, keep a running total of the sum of the elements you have encountered so far. This is known as the cumulative sum 😊.

Remainders ➗
For each cumulative sum, calculate the remainder when it is divided by k. The remainder can help us determine if the sum of any subarray (up to the current index) is a multiple of k.

Why Remainders Help (IMPORTANT!!) 🟢🟢🟢

If at two different points in the array, the cumulative sums give the same remainder when divided by k, it means the sum of the elements between ↔️ these two points is a multiple of k.
For example 🤓 lets take if we divide 7 by 5 we get remainder as 2, and if we divide 12 by 5 we also get remainder as 2, since their remainders are same (2), thus their difference which is (12 - 7 = 5) must be divisible by 5.
If at index i and index j (where j > i), the cumulative sums give the same remainder r when divided by k, then the sum of the subarray from i+1 to j is a multiple of k.
Using a Map for Remainders 🤨

Use a map (dictionary) to store the first occurrence of each remainder.
The key in the map will be the remainder, and the value will be the first index at which this remainder occurs.
Checking Subarray Length 🛣️

Ensure that the subarray length is at least two. This means that the difference between the current index and the stored index for a remainder should be at least 2.

Complexity
Time complexity O(n):

The for loop runs from 0 to nums.length - 1, so it iterates n times, where n is the length of the input array nums. Therefore, the loop itself has a time complexity of O(n).
Inside the loop, the operations performed (adding to currSum, calculating remainder, checking if remainder is in remaindersFound, and potentially adding a new entry to remaindersFound) are all constant time operations, O(1).
Given that the loop runs n times and each iteration involves constant time operations, the overall time complexity is O(n)

Space complexity O(n):