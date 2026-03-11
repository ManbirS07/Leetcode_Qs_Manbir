class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        //suppose I have
        //1 2 3 5 6
        //I have to find for 3
        //for numbers smaller, 3 - 1 + 3 - 2 = (3 * 2) - ( 1 + 2) = 3 ke pehle kitne h - prefixSum till 3
        //for larger numbers, since abs diff, 5 - 3 + 6 - 3 = (5 + 6) - (3 * 2) = suffix sum aage tak ka - 3 ke aage kitne h numbers
        //dono ka sum = result (pehle + aage)

        int n = nums.size();
        vector<int> result(n);

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        //numbers before current = i
        //numbers after current = n - i - 1

        //prefixSum till i = prefix[i - 1]
        //suffixSum = prefix[n - 1] - prefix[i]
        result[0] = (prefix[n - 1] - prefix[0]) - (nums[0] * (n - 1)); //n - 1 elements aage
        for(int i = 1; i < n; i++) {
            int curr = nums[i];
            int numsBefore = i;
            int numsAfter = n - i - 1;

            int beforeSum = (curr * numsBefore) - prefix[i - 1];
            int afterSum = (prefix[n - 1] - prefix[i]) - (curr * numsAfter);
            result[i] = beforeSum + afterSum;
        } 
        return result;
    }
};