# Max Sum of a Pair With Equal Sum of Digits

## Problem Statement

Given an array of integers, the task is to find the maximum sum of a pair of integers such that the sum of the digits of both integers is equal. If no such pair exists, return -1.

## Approach

1. **Digit Sum Calculation**:
   - Create a helper function to calculate the sum of digits of a given integer.

2. **Grouping by Digit Sum**:
   - Use a hash map (or unordered map) to group integers by their digit sums. The key will be the digit sum, and the value will be a vector of integers that have that digit sum.

3. **Finding Maximum Pair Sum**:
   - Iterate through the hash map. For each entry with more than one integer, calculate the maximum sum of any two integers in that group.
   - Keep track of the overall maximum sum found.

4. **Return Result**:
   - If at least one valid pair is found, return the maximum sum. Otherwise, return -1.

## Usage Instructions

1. **Compilation**:
   - Navigate to the project directory and compile the code using a C++ compiler. For example:
     ```
     g++ src/main.cpp -o max_sum_pair
     ```

2. **Execution**:
   - Run the compiled program:
     ```
     ./max_sum_pair
     ```

3. **Input Format**:
   - The program expects an array of integers as input. You can modify the `main.cpp` file to include specific test cases or read from standard input.

## Example

Given the input array `[51, 71, 17, 42]`, the output will be `93` because the pairs `(51, 42)` and `(71, 17)` both have a digit sum of `6` and `8`, respectively, and the maximum sum of these pairs is `93`.


## CODE

src/main.cpp

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to find the maximum sum of a pair with equal sum of digits
int maxSumOfPairsWithEqualDigitSum(const vector<int>& nums) {
    unordered_map<int, int> digitSumMap; // Maps digit sum to the maximum number with that digit sum
    int maxSum = -1;

    for (int num : nums) {
        int digitSum = sumOfDigits(num);
        // If there's already a number with the same digit sum, calculate the potential max sum
        if (digitSumMap.find(digitSum) != digitSumMap.end()) {
            maxSum = max(maxSum, digitSumMap[digitSum] + num);
        }
        // Update the maximum number for this digit sum
        digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {51, 71, 17, 42};
    int result = maxSumOfPairsWithEqualDigitSum(nums);
    cout << "Maximum sum of a pair with equal sum of digits: " << result << endl; // Output: 93

    return 0;
}