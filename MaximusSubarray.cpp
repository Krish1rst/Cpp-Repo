#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxCrossingSum(vector<int>& nums, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += nums[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += nums[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    
    return leftSum + rightSum;
}

int maxSubarraySum(vector<int>& nums, int low, int high) {
    if (low == high) {
        return nums[low];
    }
    
    int mid = (low + high) / 2;
    
    int leftSum = maxSubarraySum(nums, low, mid);
    int rightSum = maxSubarraySum(nums, mid + 1, high);
    int crossSum = maxCrossingSum(nums, low, mid, high);
    
    return max({leftSum, rightSum, crossSum});
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum sum subarray: " << maxSubarraySum(nums, 0, nums.size() - 1) << endl;
    return 0;
}
