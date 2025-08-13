#include <vector>
using namespace std;

class Solution {
public:
    // Helper function with memoization to check if subset sum 'target' is possible up to index 'ind'
    bool sumPoss(int ind, int  target, vector<int>&nums, vector<vector<int>>&dp){
        // Base case: target achieved
        if(target==0) return true;

        // Base case: only one element left
        if(ind==0) return nums[ind]==target;

        // Return cached result if already computed
        if(dp[ind][target]!=-1) return dp[ind][target];
        // Not take current element
        bool notTake=sumPoss(ind-1, target, nums, dp);

        // Take current element if possible
        bool take=false;
        if(nums[ind]<=target) take=sumPoss(ind-1, target-nums[ind], nums, dp);

        // Store and return result
        return dp[ind][target]=take | notTake;
    }

    // Main function to check if array can be partitioned into two equal subsets
    bool canPartition(vector<int>& nums) {
        int sum=0;
        // Calculate total sum
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        // If sum is odd, can't partition
        if(sum%2==1) return false;
        sum/=2; // Target sum for each subset

        // DP table initialized to -1 (uncomputed)
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));

        // Start memoized recursion from last index
        return sumPoss(nums.size()-1, sum, nums, dp);

    }
};