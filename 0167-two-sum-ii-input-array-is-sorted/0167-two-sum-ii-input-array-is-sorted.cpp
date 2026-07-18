// Author:- KaiHiwatari 
class Solution {
public: //note there is exactly 1 solution guaranteed 
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0; // two pointer approach initialize start s at begining index 0
        int e = nums.size()-1; // initialize nums at the last element in the array.
        int sum; // variable sum created
        while(s<e){ // binary search 
            sum = nums[s] + nums[e]; // sum will be index 0 and index last
            if(sum == target){ // if sum == target
                return {s+1,e+1}; // s+1 making index 1 of s which is 0 indexed same for e
            }else if (sum > target){ // example 1 [2 + 15] s + e > target 
                e--; // do e-- decrement e
            }else{
                s++; // or increment s
            }
        }
        return {}; // return empty as class solution needs 1 return outside the loop
    }
};