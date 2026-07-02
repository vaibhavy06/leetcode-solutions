class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Stores indices of elements
        int n = nums.size();
        
        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back(); // Remove 'last' if it is smaller than 'curr'
            }
            dq.push_back(i); // Add 'curr'
        }
        ans.push_back(nums[dq.front()]); // The 'first' element is the max

        // Process the remaining elements as the window slides
        for (int i = k; i < n; i++) {
            // Remove 'first' element if it is outside the current window boundary
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove 'last' elements from the back if they are smaller than 'curr'
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i); // Add 'curr'
            ans.push_back(nums[dq.front()]); // The 'first' element is the max
        }
        
        return ans;
    }
};