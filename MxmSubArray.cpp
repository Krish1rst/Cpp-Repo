#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < n; ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum sum subarray: " << maxSubarraySum(nums) << endl;
    return 0;
}
