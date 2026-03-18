class Solution {
public:
    bool canDistribute(int productsInEachStore, vector<int>& quantities, int n) {
        int m = quantities.size();
        int totalStores = 0;

        for(int i = 0; i < m; i++) {
            int quantity = quantities[i];
            int stores = (quantity % productsInEachStore == 0) ? quantity / productsInEachStore : (quantity / productsInEachStore) + 1; 
            totalStores += stores;
        }

        return totalStores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int low = 1, high = 1e5;
        int ans = high;
        while(low <= high) {
            //mid = max products per store
            int mid = low + (high - low) / 2;

            if(canDistribute(mid, quantities, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};