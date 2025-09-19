#include <vector>
using namespace std;

class Solution {
public:
    // Function to determine if the array can be partitioned into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int sum=0;
        // Calculate total sum of elements
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        // If sum is odd, can't partition into two equal subsets
        if(sum%2==1) return false;
        sum/=2; // Target sum for each subset

        // DP table: dp[i][j] = true if subset sum j is possible with first i elements
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1, 0));

        // Base case: sum 0 is always possible (empty subset)
        for(int i=0;i<nums.size();i++) dp[i][0]=1;

        // Base case: with only the first element
        if (nums[0] <= sum) dp[0][nums[0]]=1;

        // Fill the DP table
        for(int ind=1;ind<nums.size();ind++){
            for(int target=1;target<=sum;target++){
                // Not take current element
                bool notTake=dp[ind-1][target];

                // Take current element if it does not exceed target
                bool take=false;
                if(nums[ind]<=target) take=dp[ind-1][target-nums[ind]];

                // Either take or not take
                dp[ind][target]=take || notTake; // dp[ind][target] tells if sum 'target' is possible with first 'ind' elements
            }
        }

        // Final answer: is it possible to get 'sum' using all elements?
        return dp[nums.size()-1][sum];

    }
};