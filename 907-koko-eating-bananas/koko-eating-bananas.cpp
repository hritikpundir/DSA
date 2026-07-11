class Solution {
public:
    long long totalHours(vector<int>& piles, int speed) {
        long long h = 0;
        for (int i = 0; i < piles.size(); i++) {
            h += (piles[i] + speed - 1) / speed; // ceiling division
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int hourly) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (totalHours(piles, mid) > hourly) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};