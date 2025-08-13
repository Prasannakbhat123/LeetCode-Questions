#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to check if subset sum 'target' is possible using elements up to index 'ind'
    bool sumPoss(int ind, int  target, vector<int>&nums){
        // Base case: target achieved
        if(target==0) return true;

        // Base case: only one element left
        if(ind==0) return nums[ind]==target;

        // Not take current element
        bool notTake=sumPoss(ind-1, target, nums);

        // Take current element if possible
        bool take=false;
        if(nums[ind]<=target) take=sumPoss(ind-1, target-nums[ind], nums);

        // Return true if either possibility works
        return take | notTake;
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

        // Start recursion from last index
        return sumPoss(nums.size()-1, sum, nums);

    }
};