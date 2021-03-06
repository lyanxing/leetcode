/*
 * @lc app=leetcode id=822 lang=cpp
 *
 * [822] Card Flipping Game
 *
 * https://leetcode.com/problems/card-flipping-game/description/
 *
 * algorithms
 * Medium (39.79%)
 * Total Accepted:    5.7K
 * Total Submissions: 14.1K
 * Testcase Example:  '[1,2,4,4,7]\n[1,3,4,1,3]'
 *
 * On a table are N cards, with a positive integer printed on the front and
 * back of each card (possibly different).
 * 
 * We flip any number of cards, and after we choose one card. 
 * 
 * If the number X on the back of the chosen card is not on the front of any
 * card, then this number X is good.
 * 
 * What is the smallest number that is good?  If no number is good, output 0.
 * 
 * Here, fronts[i] and backs[i] represent the number on the front and back of
 * card i. 
 * 
 * A flip swaps the front and back numbers, so the value on the front is now on
 * the back and vice versa.
 * 
 * Example:
 * 
 * 
 * Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
 * Output: 2
 * Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the
 * backs are [1,2,4,1,3].
 * We choose the second card, which has number 2 on the back, and it isn't on
 * the front of any card, so 2 is good.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= fronts.length == backs.length <= 1000.
 * 1 <= fronts[i] <= 2000.
 * 1 <= backs[i] <= 2000.
 * 
 * 
 */
#include <unordered_map>
using namespace std;
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int, vector<int>> m;
        int min = 3000;
        for(int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                m[fronts[i]].push_back(i);
            }
        }
        for(int i = 0; i < fronts.size(); i++)
        {
            int el = fronts[i];
            if (el < min) {
                if (m.count(el) == 0) {
                    min = el;
                }
            }
        }
        for(int i = 0; i < backs.size(); i++)
        {
            int el = backs[i];
            if (el < min) {
                if (m.count(el) == 0) {
                    min = el;
                }
            }
        }

        return min == 3000 ? 0 : min;
        
        
    }
};

