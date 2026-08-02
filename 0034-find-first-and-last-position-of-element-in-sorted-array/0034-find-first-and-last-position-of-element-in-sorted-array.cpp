class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int first = -1, last = -1;

        // Find first occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Find last occurrence
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) last = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};