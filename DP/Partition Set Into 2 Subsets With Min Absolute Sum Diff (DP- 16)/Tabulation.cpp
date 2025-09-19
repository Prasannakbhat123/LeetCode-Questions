//only for positive numbers

#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to find the minimum absolute difference between two subset sums
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // Calculate total sum of all elements
        for (int num : nums) sum += num;

        // DP table: dp[i][j] = true if subset sum j is possible with first i elements
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case: sum 0 is always possible (empty subset)
        for (int i = 0; i < n; i++) dp[i][0] = true;
        // Base case: with only the first element
        if (nums[0] <= sum) dp[0][nums[0]] = true;

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                // Not take current element
                bool notTake = dp[i - 1][target];
                // Take current element if it does not exceed target
                bool take = false;
                if (nums[i] <= target)
                    take = dp[i - 1][target - nums[i]];
                // Either take or not take
                dp[i][target] = take || notTake;
            }
        }

        int mini = INT_MAX;
        // Try all possible subset sums up to sum/2 (to minimize difference)
        for (int i = 0; i <= sum / 2; i++) {
            if (dp[n - 1][i]) {
                int s2 = sum - i; // Other subset sum
                mini = min(mini, abs(s2 - i)); // Update minimum difference
            }
        }
        return mini;
    }
};
