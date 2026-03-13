class Solution {
public:
    int bestClosingTime(string customers) {
        //O(n) solution
        //assume closing at the 0th hour
        //penalty would be all the customers -> all the Y's in the array
        //then we try to shift the closing time one by one
        //if I am at ith index, I would close the shop at i + 1
        //so, if current character is Y, penalty reduces because abhi shop open h jab aaya h cust and if current char is N penalty increases kyuki ye aaya nhi and iske ek baad penalty decrease hogi
        int n = customers.size();

        int penalty = 0, ans = 0;
        for(int i = 0; i < n; i++) if(customers[i] == 'Y') penalty++;

        int minPenalty = penalty;

        for(int i = 0; i < n; i++) {
            //closing at i + 1th hour
            if(customers[i] == 'Y') {
                penalty--;
            } else {
                penalty++;
            }

            if(penalty < minPenalty) {
                ans = i + 1;
                minPenalty = penalty;
            }
        }
        return ans;
    }
};