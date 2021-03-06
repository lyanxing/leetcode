/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (34.06%)
 * Total Accepted:    170.6K
 * Total Submissions: 493.3K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int i = 0, j = 0, sum = 0, minLen = INT_MAX;
        while (j < nums.size()) {
            sum = sum + nums[j++];
            while (sum >= s) {
                minLen = min(minLen, j - i);
                sum = sum - nums[i++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

