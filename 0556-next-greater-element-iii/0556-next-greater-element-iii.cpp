class Solution {
public:
    typedef long long ll;
    int nextGreaterElement(int n) {
        // same as next permutation
        vector<int> digits;

        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(begin(digits), end(digits));

        // find the longest prefix i.e the part jistak koi change nhi hoga
        // i | i + 1 -> striver
        int idx = -1;
        int m = digits.size();
        for (int i = m - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1)
            return -1;

        // now, finding the smallest digit > a[i]
        // after breaking point, the sequence would be in an increasing order
        // from the end
        for (int i = m - 1; i > idx; i--) {
            if (digits[i] > digits[idx]) {
                swap(digits[i], digits[idx]);
                break;
            }
        }

        // now, since the digits after breaking point are in increasing order
        // but from the end, simply reverse after the breaking point
        reverse(begin(digits) + idx + 1, end(digits));

        ll num = 0;

        for (int d : digits) {
            num = num * 10 + d;
            if (num > INT_MAX) return -1;
        }

        return (int)num;
    }
};