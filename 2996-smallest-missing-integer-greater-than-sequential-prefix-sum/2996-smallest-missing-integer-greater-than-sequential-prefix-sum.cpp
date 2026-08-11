class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix = nums[0];
        int n = nums.size();

        if (n == 1) {
            return prefix + 1;
        }

        int i = 1;

        while (i < n && nums[i] == nums[i - 1] + 1) {
            prefix += nums[i];
            i++;
        }

        unordered_set<int> present(nums.begin(), nums.end());

        while (present.count(prefix)) {
            prefix++;
        }

        return prefix;
    }
};